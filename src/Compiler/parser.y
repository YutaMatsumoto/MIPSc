//
//	This is a parser definition file that will be fed into bisonc++. Then,
//	bisonc++ produces skelton files for C++ Parser class :
//
//		Parserbase.h : base class that Parser class is supposed to extend from
//		Parser.h     : interface for Parser class
//		Parser.ih    : implementation of Parser class
//		parse.cc     : parser implementation which includes Parser.h and Parser.ih
//
//	In this parser definition file, we can use precedures defined in Parser class
//
//	Currently, this parser only shows each reduction taken with debugPrint()
//	function defined in Parser.h and Parser.ih. 
//  
//	Original parser definition file is modified with vim script parser.y.hack.vim
//
//	See also Parser.h and Parser.ih for Parser class
//
// 
// Declarations
//
//      Function called on reduction : reduction ( right-hand-side reduces to left-hand-side )
//      ---------------------------------------------------------------------------------------
//
//      beginDeclarationSection() : compound_statement -> { declaration_list ...
//
//      endDeclarationSection() : declaration_list       -> declaration ... start declaration mode before this, and end declration mode after this
//
//      declare()               : declaration            -> declaration_specifiers init_declarator_list ';'
//
//      determineType()         : declaration_specifiers -> storage_class_specifier | type_specifier | type_qualifier
//
//                              : init_declarator        -> declarator | declarator '=' initializer
//
//      initializeArray()       : initializer            -> '{' initializer_list '}'  |  '{' initializer_list ',' '}'
//
//      addValueToArray()       : initializer_list       -> initializer | initializer_list, initializer
//
//                              : declarator             -> direct_declarator
//
//      ???                     : identifier             -> IDENTIFIER
//
//      addTypeSpecifier()      : type_specifier         -> VOID | INT | LONG | ...
//
//      setConst()              : type_qualifier         -> CONST
//
//      setVolitle()            : type_qualifier         -> VOLATILE
//
//      pushIdentifier()     : direct_declarator      -> identifier
//
//      specifyArray()          : direct_declarator      -> direct_declarator '[' ']'
//
//      specifyArray()          : direct_declarator      -> direct_declarator '[' constant_expression ']'
//
//      specifyFunction()       : direct_declarator      -> '(' parameter_type_list ')'
//
//      specifyFunctionCall()   : direct_declarator      -> '(' identifier_list ')'

%token <CHAR> CHAR_LITERAL

%token <STRING> IDENTIFIER
%token <INT> I_CONSTANT
%token <FLOAT> F_CONSTANT
%token <STRING> STRING_LITERAL
%token TYPEDEF_NAME
%token ENUMERATION_CONSTANT

%token <STRING> WHITESPACE
%token <STRING> COMMENT

%token ENDOFFILE

%token SIZEOF

%token PTR_OP
%token INC_OP
%token DEC_OP
%token LEFT_OP
%token RIGHT_OP
%token LE_OP
%token GE_OP
%token EQ_OP
%token NE_OP
%token AND_OP
%token OR_OP

%token MUL_ASSIGN
%token DIV_ASSIGN
%token MOD_ASSIGN
%token ADD_ASSIGN
%token SUB_ASSIGN
%token LEFT_ASSIGN
%token RIGHT_ASSIGN
%token AND_ASSIGN
%token XOR_ASSIGN
%token OR_ASSIGN

%token TYPEDEF
%token EXTERN
%token STATIC
%token AUTO
%token REGISTER
%token CONST
%token VOLATILE
%token CHAR
%token SHORT
%token INT
%token LONG
%token SIGNED
%token UNSIGNED
%token FLOAT
%token DOUBLE
%token VOID
%token STRUCT
%token UNION
%token ENUM

%token ELLIPSIS

%token CASE
%token DEFAULT
%token IF
%token ELSE
%token SWITCH
%token WHILE
%token DO
%token FOR
%token GOTO
%token CONTINUE
%token BREAK
%token RETURN

%token SQUOTE

// %polymorphic INT: int; FLOAT: float; DOUBLE: double; STRING: std::string; CHAR: char; EXPRESSION: Expression;

//%type <STRING> identifier
//%type <STRING> string
// %type <EXPRESSION> constant;
%stype void*

%lsp-needed
%debug
%no-lines

%%

program
	:
	translation_unit { debugPrint("translation_unit -> program"); }
	{
	
		ast = (TranslationUnitNode*) $1;
	
	}
	;

translation_unit
	: external_declaration { debugPrint("external_declaration -> translation_unit"); }
	{
	
		$$ = new TranslationUnitNode( (ExternalDeclarationNode*) $1 );	
	
	}
	| translation_unit external_declaration { debugPrint("translation_unit external_declaration -> translation_unit"); }
	{
	
		$$ = new TranslationUnitNode( (ExternalDeclarationNode*) $2 , (TranslationUnitNode*) $1 );
	
	}
	;

external_declaration
	: function_definition { debugPrint("function_definition -> external_declaration"); }
	{

		$$ = new ExternalDeclarationNode( (FunctionDefinitionNode*) $1 );

	}
	| declaration { 
		debugPrint("declaration -> external_declaration"); 
	  }
	;

function_definition
	: declarator compound_statement { 
		debugPrint("----to function_definition by production 1----"); 
		debugPrint("declarator compound_statement -> function_definition");
	  }
	 {

		$$ = new FunctionDefinitionNode( (CompoundStatementNode*) $2 , (DeclaratorNode*) $1, symbolTable );

	 }
	| declarator { 
	  	// declaration mdoe start 
	  }
	  declaration_list {
		// declaration mode	end
	  }
	  compound_statement { 
		// declaration mode end
		debugPrint("----to function definition Production 2----"); 
		debugPrint("declarator declaration_list compound_statement -> function_definition"); 

		$$ = new FunctionDefinitionNode( (CompoundStatementNode*) $5 , (DeclaratorNode*) $1, symbolTable); // $BUG
	  }
	| declaration_specifiers declarator compound_statement { 
		debugPrint("----to function_definition by production 3----"); 
	  	debugPrint("declaration_specifiers declarator compound_statement -> function_definition"); 

		$$ = new FunctionDefinitionNode( (DeclarationSpecifiersNode*) $1 , (CompoundStatementNode*) $3, (DeclaratorNode*) $2, symbolTable );

	  }
	| declaration_specifiers {
	  
		beginDeclarationSection();
		symbolTable->beginScope();
	  } declarator declaration_list compound_statement { 
		debugPrint("----to function definition production 4----"); 
	     	debugPrint("declaration_specifiers declarator declaration_list compound_statement -> function_definition"); 
	  
	  	$$ = new FunctionDefinitionNode( (CompoundStatementNode*) $4 , (DeclaratorNode*) $2, symbolTable ); // $BUG

		//symbolTable->endScope();
	  }
	;

declaration
	: declaration_specifiers ';' { 
		// TODO : Is this legal???
		if (!isDeclarationMode()) {
			throw ParserError(ParserError::SemanticError, "Declaration must be done on top of a block"); 
		}
		debugPrint("declaration_specifiers ';' -> declaration"); 
		DeclarationNode* declNode = new DeclarationNode(  (DeclarationSpecifiersNode*) $1 , symbolTable );
		//declNode->declare(symbolTable);
		$$ = (void*) declNode;
		}
	| declaration_specifiers init_declarator_list ';' { debugPrint("declaration_specifiers init_declarator_list ';' -> declaration");  } { 
		if (!isDeclarationMode()) {
			throw ParserError(ParserError::SemanticError, "Declaration must be done on top of a block"); 
		}
		debugPrint("declaration_specifiers init_declarator_list ';' -> declaration"); 
		DeclarationNode* n = new DeclarationNode(  (DeclarationSpecifiersNode*) $1, (InitDeclaratorListNode*) $2 , symbolTable );
		//n->declare(symbolTable);
		$$ = (void*) n;
		/* std::cout << n->toString() << std::endl; */
		}
	;

declaration_list
	: declaration { 
		// beginLookupSection();
		debugPrint("declaration -> declaration_list");
		$$ = new DeclarationListNode( (DeclarationNode*) $1 );
		//TODO: I think this goes here
		//beginLookupSection();
	  }
	| declaration_list declaration { debugPrint("declaration_list declaration -> declaration_list"); }
	{

		$$ = new DeclarationListNode( (DeclarationListNode*) $1 , (DeclarationNode*) $2 );

	}
	;

declaration_specifiers
	: storage_class_specifier { 
		// TODO : is this legal???
		debugPrint("storage_class_specifier -> declaration_specifiers"); 
		$$ = (void*) new DeclarationSpecifiersNode( (StorageClassSpecifierNode*)$1 );
		}
	| storage_class_specifier declaration_specifiers { 
		debugPrint("storage_class_specifier declaration_specifiers -> declaration_specifiers"); 
		$$ = (void*) new DeclarationSpecifiersNode( (StorageClassSpecifierNode*)$1, (DeclarationSpecifiersNode*)$2 );
		}
	| type_specifier { 
		debugPrint("type_specifier -> declaration_specifiers"); 
		$$ = (void*) new DeclarationSpecifiersNode( (TypeSpecifierNode*)$1 );
		}
	| type_specifier declaration_specifiers { 
		debugPrint("type_specifier declaration_specifiers -> declaration_specifiers"); 
		$$ = (void*) new DeclarationSpecifiersNode( (TypeSpecifierNode*)$1, (DeclarationSpecifiersNode*)$2 );
		}
	| type_qualifier  { 
		// TODO : is this legal???
		debugPrint("type_qualifier  -> declaration_specifiers"); 
		$$ = (void*) new DeclarationSpecifiersNode( (TypeQualifierNode*)$1 );
		}
	| type_qualifier declaration_specifiers { 
		debugPrint("type_qualifier declaration_specifiers -> declaration_specifiers"); 
		$$ = (void*) new DeclarationSpecifiersNode( (TypeQualifierNode*)$1, (DeclarationSpecifiersNode*)$2 );
		}
	;

storage_class_specifier
	: AUTO { 
		$$ = (void*) new StorageClassSpecifierNode(StorageClassSpecifierNode::Auto);
		debugPrint("AUTO -> storage_class_specifier"); 
		}
	| REGISTER { 
		$$ = (void*) new StorageClassSpecifierNode(StorageClassSpecifierNode::Register);
		debugPrint("REGISTER -> storage_class_specifier"); 
		}
	| STATIC { 
		$$ = (void*) new StorageClassSpecifierNode(StorageClassSpecifierNode::Static);
		debugPrint("STATIC -> storage_class_specifier"); 
		}
	| EXTERN { 
		$$ = (void*) new StorageClassSpecifierNode(StorageClassSpecifierNode::Extern);
		debugPrint("EXTERN -> storage_class_specifier"); 
		}
	| TYPEDEF { 
		$$ = (void*) new StorageClassSpecifierNode(StorageClassSpecifierNode::Typedef);
		debugPrint("TYPEDEF -> storage_class_specifier"); 
		}
	;

type_specifier
	: VOID { 
		debugPrint("VOID -> type_specifier");
		$$ = (void*) new TypeSpecifierNode( Void );
	  } // { /*currentDeclaration*/ }
	| CHAR { 
		$$ = (void*) new TypeSpecifierNode( Char );
		debugPrint("CHAR -> type_specifier"); 
	  }
	| SHORT { debugPrint("SHORT -> type_specifier"); 
		$$ = (void*) new TypeSpecifierNode( Short );
		addTypeSpecifier();
	  }
	| INT { 
		$$ = (void*) new TypeSpecifierNode( Int );
		debugPrint("INT -> type_specifier"); 
	  }
	| LONG {
		$$ = (void*) new TypeSpecifierNode( Long );
		debugPrint("LONG -> type_specifier"); 
	  }
	| FLOAT  {
		$$ = (void*) new TypeSpecifierNode( Float );
		 debugPrint("FLOAT  -> type_specifier"); 
	  }
	| DOUBLE {
		$$ = (void*) new TypeSpecifierNode( Double );
		debugPrint("DOUBLE -> type_specifier"); 
	  }
	| SIGNED {
		$$ = (void*) new TypeSpecifierNode( Signed );
		debugPrint("SIGNED -> type_specifier"); 
	  }
	| UNSIGNED {
		$$ = (void*) new TypeSpecifierNode( Unsigned );
		debugPrint("UNSIGNED -> type_specifier"); 
	  }
	| struct_or_union_specifier {
		// TODO 
		throw ParserError(ParserError::NotImplemented, "Sturuct/Union is not implemented");
		debugPrint("struct_or_union_specifier -> type_specifier"); 
	  }
	| enum_specifier {
		// TODO 
		//throw ParserError(ParserError::NotImplemented, "enum is not implemented");
		debugPrint("enum_specifier -> type_specifier"); 
	  }
	| TYPEDEF_NAME {
		$$ = (void*) new TypeSpecifierNode( Typedef );
		debugPrint("TYPEDEF_NAME -> type_specifier"); 
	  }
	;

type_qualifier
	: CONST { debugPrint("CONST -> type_qualifier"); } {
		$$ = (void*) new TypeQualifierNode(TypeQualifierNode::Const);
		}
	| VOLATILE { debugPrint("VOLATILE -> type_qualifier"); } {
		$$ = (void*) new TypeQualifierNode(TypeQualifierNode::Volatile);
		}
	;

struct_or_union_specifier
	: struct_or_union identifier '{' struct_declaration_list '}' { debugPrint("struct_or_union identifier '{' struct_declaration_list '}' -> struct_or_union_specifier"); }
	| struct_or_union '{' struct_declaration_list '}' { debugPrint("struct_or_union '{' struct_declaration_list '}' -> struct_or_union_specifier"); }
	| struct_or_union identifier { debugPrint("struct_or_union identifier -> struct_or_union_specifier"); }
	;

struct_or_union
	: STRUCT { debugPrint("STRUCT -> struct_or_union"); }
	| UNION { debugPrint("UNION -> struct_or_union"); }
	;

struct_declaration_list
	: struct_declaration { debugPrint("struct_declaration -> struct_declaration_list"); }
	| struct_declaration_list struct_declaration { debugPrint("struct_declaration_list struct_declaration -> struct_declaration_list"); }
	;

init_declarator_list
	: init_declarator { 
		debugPrint("init_declarator -> init_declarator_list"); 
		$$ = new InitDeclaratorListNode( (InitDeclaratorNode*) $1 );
		}
	| init_declarator_list ',' init_declarator { 
		debugPrint("init_declarator_list ',' init_declarator -> init_declarator_list"); 
		$$ = new InitDeclaratorListNode( (InitDeclaratorListNode*) $1 , (InitDeclaratorNode*) $3 );
		}
	;

init_declarator
	: declarator { 
		debugPrint("declarator -> init_declarator"); 
		//InitDeclaratorNode* initDecl = new InitDeclaratorNode((DeclaratorNode*) $1  , symbolTable);
		/* std::cout << "reduction in init_declarator" << initDecl->toString() << std::endl; */
		$$ = new InitDeclaratorNode( (DeclaratorNode*) $1 , symbolTable );
		}
	| declarator '=' initializer { 
		// TODO : initialize here or even before when something reduces to initializer ?
		/* initializeValue(); */
		debugPrint("declarator '=' initializer -> init_declarator"); 
		$$ = (void*)new InitDeclaratorNode((DeclaratorNode*) $1, (InitializerNode*) $3 , symbolTable );
	  }
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';' { debugPrint("specifier_qualifier_list struct_declarator_list ';' -> struct_declaration"); }
	;

specifier_qualifier_list
	: type_specifier { 
		debugPrint("type_specifier -> specifier_qualifier_list"); 
		$$ = (void*) new SpecifierQualifierListNode( (TypeSpecifierNode*) $1);
		}
	| type_specifier specifier_qualifier_list { 
		debugPrint("type_specifier specifier_qualifier_list -> specifier_qualifier_list"); 
		$$ = (void*) new SpecifierQualifierListNode( (TypeSpecifierNode*) $1, (SpecifierQualifierListNode*)$2);
		}
	| type_qualifier { 
		debugPrint("type_qualifier -> specifier_qualifier_list"); 
		$$ = (void*) new SpecifierQualifierListNode((TypeQualifierNode*)$1);
		}
	| type_qualifier specifier_qualifier_list { 
		debugPrint("type_qualifier specifier_qualifier_list -> specifier_qualifier_list"); 
		$$ = (void*) new SpecifierQualifierListNode((TypeQualifierNode*)$1, (SpecifierQualifierListNode*)$2);
		}
	;

struct_declarator_list
	: struct_declarator { debugPrint("struct_declarator -> struct_declarator_list"); }
	| struct_declarator_list ',' struct_declarator { debugPrint("struct_declarator_list ',' struct_declarator -> struct_declarator_list"); }
	;

struct_declarator
	: declarator { debugPrint("declarator -> struct_declarator"); }
	| ':' constant_expression { debugPrint("':' constant_expression -> struct_declarator"); }
	| declarator ':' constant_expression { debugPrint("declarator ':' constant_expression -> struct_declarator"); }
	;

enum_specifier
	: ENUM '{' enumerator_list '}' { debugPrint("ENUM '{' enumerator_list '}' -> enum_specifier"); }
	| ENUM identifier '{' enumerator_list '}' { debugPrint("ENUM identifier '{' enumerator_list '}' -> enum_specifier"); }
	| ENUM identifier { debugPrint("ENUM identifier -> enum_specifier"); }
	;

enumerator_list
	: enumerator { debugPrint("enumerator -> enumerator_list"); }
	| enumerator_list ',' enumerator { debugPrint("enumerator_list ',' enumerator -> enumerator_list"); }
	;

enumerator
	: identifier { debugPrint("identifier -> enumerator"); }
	| identifier '=' constant_expression { debugPrint("identifier '=' constant_expression -> enumerator"); }
	;

declarator
	: direct_declarator { 
		debugPrint("direct_declarator -> declarator"); 
		$$ = (void*) new DeclaratorNode((DirectDeclaratorNode*)$1);
		}
	| pointer direct_declarator { 
		debugPrint("pointer direct_declarator -> declarator"); 
		$$ = (void*) new DeclaratorNode((PointerNode*)$1, (DirectDeclaratorNode*)$2);
		}
	;

direct_declarator
	: identifier { 
			debugPrint("identifier -> direct_declarator"); 
			$$ = new DirectDeclaratorNode( (IdentifierNode*) $1 );
		}
	| '(' declarator ')' { 
			debugPrint("'(' declarator ')' -> direct_declarator");
			
			//$$ = new DirectDeclaratorNode( (DeclaratorNode*) $2 );
		}
	| direct_declarator '[' ']' { 
			debugPrint("direct_declarator '[' ']' -> direct_declarator"); 
			//DirectDeclaratorNode* ddn = new DirectDeclaratorNode( (DirectDeclaratorNode*)$1 );
			//ddn->specifyArray();
			//$$ = ddn;
		}
	| direct_declarator '[' constant ']' { 
			debugPrint("direct_declarator '[' constant_expression ']' -> direct_declarator"); 
			$$ = new DirectDeclaratorNode( (DirectDeclaratorNode*) $1 , (ConstantNode*) $3 );
			//DirectDeclaratorNode* ddn = new DirectDeclaratorNode( (DirectDeclaratorNode*)$1 );
			//ddn->specifyArray( (ConstantExpressionNode*)$3 );
			//$$ = ddn;
		}
	| direct_declarator '(' ')' { 
			// TODO : function call or structure instantiation ? function definition?
			debugPrint("direct_declarator '(' ')' -> direct_declarator"); 

			$$ = new DirectDeclaratorNode( (DirectDeclaratorNode*) $1 , DirectDeclaratorNode::FunctionCall );
		}
	| direct_declarator '(' parameter_type_list ')' { 
			debugPrint("direct_declarator '(' parameter_type_list ')' -> direct_declarator"); 
			//DirectDeclaratorNode* ddn = new DirectDeclaratorNode( (DirectDeclaratorNode*)$1 );
			$$ = new DirectDeclaratorNode( (DirectDeclaratorNode*) $1 , (ParameterTypeListNode*) $3 );
			
			//ddn->specifyFunction( (ParameterTypeListNode*)$3 );
			//$$ = (void*) ddn;
		}
	| direct_declarator '(' identifier_list ')' { 
			//
			// function call 
			//
			// or
			//
			// function definition with paramters types specified outside of
			// parentheses
			debugPrint("direct_declarator '(' identifier_list ')' -> direct_declarator"); 
			//specifyFunctionCall();	// TODO : or structure instantiation ?
			//DirectDeclaratorNode* ddn = new DirectDeclaratorNode( (DirectDeclaratorNode*)$1 );
			//ddn->specifyFunctionCall( (IdentifierListNode*)$3 ); // TODO TOFIX
			//$$ = (void*) ddn;
		}
	;

pointer
	: '*' { debugPrint("'*' -> pointer"); } {
		$$ = (void*) new PointerNode();
		}
	| '*' type_qualifier_list { debugPrint("'*' type_qualifier_list -> pointer"); } {
		$$ = (void*) new PointerNode((TypeQualifierListNode*) $2);
		}
	| '*' pointer { debugPrint("'*' pointer -> pointer"); } {
		$$ = (void*) new PointerNode((PointerNode*) $2);
		}
	| '*' type_qualifier_list pointer { debugPrint("'*' type_qualifier_list pointer -> pointer"); } {
		$$ = (void*) new PointerNode((TypeQualifierListNode*) $2, (PointerNode*)$3 );
		}
	;

type_qualifier_list
	: type_qualifier { 
		debugPrint("type_qualifier -> type_qualifier_list"); 
		$$ = (void*) new TypeQualifierListNode( (TypeQualifierNode*)$1 );
		}
	| type_qualifier_list type_qualifier { 
		debugPrint("type_qualifier_list type_qualifier -> type_qualifier_list"); 
		$$ = (void*) new TypeQualifierListNode( (TypeQualifierListNode*)$1, (TypeQualifierNode*)$2 );
		}
	;

parameter_type_list
	: parameter_list { debugPrint("parameter_list -> parameter_type_list"); } {
		$$ = (void*) new ParameterTypeListNode( (ParameterListNode*) $1 );
		}
	| parameter_list ',' ELLIPSIS { 
		debugPrint("parameter_list ',' ELLIPSIS -> parameter_type_list"); 
		ParameterTypeListNode* pl = new ParameterTypeListNode( (ParameterListNode*) $1 );
		pl->setVariableArgumentList();
		$$ = (void*) pl;
		}
	;

parameter_list
	: parameter_declaration { 
		debugPrint("parameter_declaration -> parameter_list"); 
		$$ = (void*) new ParameterListNode((ParameterDeclarationNode*)$1);
		}
	| parameter_list ',' parameter_declaration { 
		debugPrint("parameter_list ',' parameter_declaration -> parameter_list"); 
		ParameterListNode* pl = (ParameterListNode*) $1;
		pl->add( (ParameterDeclarationNode*) $3);
		$$ = (void*) pl;
		}
	;

parameter_declaration
	: declaration_specifiers declarator { debugPrint("declaration_specifiers declarator -> parameter_declaration"); } {
		$$ = (void*) new
		ParameterDeclarationNode((DeclarationSpecifiersNode*)$1, (DeclaratorNode*)$2, symbolTable);	
		}
	| declaration_specifiers { debugPrint("declaration_specifiers -> parameter_declaration"); } {
		$$ = (void*) new 
		ParameterDeclarationNode((DeclarationSpecifiersNode*)$1, symbolTable);	
		}
	| declaration_specifiers abstract_declarator { debugPrint("declaration_specifiers abstract_declarator -> parameter_declaration"); } {
		// TODO what's this?
		$$ = (void*) new
		ParameterDeclarationNode((DeclarationSpecifiersNode*)$1, (AbstractDeclaratorNode*)$2, symbolTable);	
		}
	;

identifier_list
	: identifier { debugPrint("identifier -> identifier_list"); } {
			$$ = (void*) new 
			IdentifierListNode( (IdentifierNode*)$1 );
		}
	| identifier_list ',' identifier { debugPrint("identifier_list ',' identifier -> identifier_list"); } {
			IdentifierListNode*	idList = (IdentifierListNode*) $1;
			idList->add( (IdentifierNode*) $3 );
			$$ = (void*) idList;
		}
	;

// TODO
initializer
	: assignment_expression { debugPrint("assignment_expression -> initializer"); }
	{

		$$ = new InitializerNode( (AssignmentExpressionNode*) $1 );

	}
	| '{' initializer_list '}' { 
			initializeArray();
			debugPrint("'{' initializer_list ' }' -> initializer"); 
		}
	| '{' initializer_list ',' '}' { 
			initializeArray();
			debugPrint("'{' initializer_list ',' '}' -> initializer"); 
		}
	;

// TODO
initializer_list
	: initializer { 
			addValueToArray();
			debugPrint("initializer -> initializer_list"); 
		}
	{

		$$ = new InitializerListNode( (InitializerNode*) $1 );

	}
	| initializer_list ',' initializer { 
			addValueToArray();
			debugPrint("initializer_list ',' initializer -> initializer_list"); 
		}
	{

		// $$ = new InitializerListNode( (InitializerListNode*) $1 , (InitializerNode*) $3 );
		$$ = new InitializerListNode( (InitializerNode*) $3, (InitializerListNode*) $1  );

	}
	;

type_name
	: specifier_qualifier_list { debugPrint("specifier_qualifier_list -> type_name"); } {
		$$ = (void*) new 
		TypeNameNode( (SpecifierQualifierListNode*)$1 );
		}
	| specifier_qualifier_list abstract_declarator { debugPrint("specifier_qualifier_list abstract_declarator -> type_name"); } {
		$$ = (void*) new 
		TypeNameNode( (SpecifierQualifierListNode*)$1, (AbstractDeclaratorNode*)$2 );
		}
	;

abstract_declarator
	: pointer { debugPrint("pointer -> abstract_declarator"); } {
		$$ = (void*) new 
		AbstractDeclaratorNode((PointerNode*)$1 );
		}
	| direct_abstract_declarator { debugPrint("direct_abstract_declarator -> abstract_declarator"); } {
		$$ = (void*) new 
		AbstractDeclaratorNode((DirectAbstractDeclaratorNode*)$1 );
		}
	| pointer direct_abstract_declarator { debugPrint("pointer direct_abstract_declarator -> abstract_declarator"); } {
		$$ = (void*) new 
		AbstractDeclaratorNode((PointerNode*)$1, (DirectAbstractDeclaratorNode*)$2 );
		}
	;

direct_abstract_declarator
	: '(' abstract_declarator ')' { debugPrint("'(' abstract_declarator ')' -> direct_abstract_declarator"); } {
		$$ = (void*) new DirectAbstractDeclaratorNode( 
			(AbstractDeclaratorNode*) $2
		);
		}
	| '[' ']' { debugPrint("'[' ']' -> direct_abstract_declarator"); } {
		$$ = (void*) new DirectAbstractDeclaratorNode( 
			DirectAbstractDeclaratorNode::Square
		);
		}
	| '[' constant_expression ']' { debugPrint("'[' constant_expression ']' -> direct_abstract_declarator"); } {
		$$ = (void*) new DirectAbstractDeclaratorNode( 
			(ConstantExpressionNode*) $2
		);
		}
	| direct_abstract_declarator '[' ']' { debugPrint("direct_abstract_declarator '[' ']' -> direct_abstract_declarator"); } {
		// TODO
		$$ = (void*) new DirectAbstractDeclaratorNode( 
			(DirectAbstractDeclaratorNode*) $1,
			DirectAbstractDeclaratorNode::Square
		);
		}
	| direct_abstract_declarator '[' constant_expression ']' { debugPrint("direct_abstract_declarator '[' constant_expression ']' -> direct_abstract_declarator"); } {
		$$ = (void*) new DirectAbstractDeclaratorNode( 
			(DirectAbstractDeclaratorNode*)	$1, 
			(ConstantExpressionNode*)	$3
		);
		}
	| '(' ')' { debugPrint("'(' ')' -> direct_abstract_declarator"); } {
		// TODO
		$$ = (void*) new DirectAbstractDeclaratorNode( 
			DirectAbstractDeclaratorNode::Normal
		);
		}
	| '(' parameter_type_list ')' { debugPrint("'(' parameter_type_list ')' -> direct_abstract_declarator"); } {
		$$ = (void*) new DirectAbstractDeclaratorNode( 
			(ParameterTypeListNode*) $2
		);
		}
	| direct_abstract_declarator function_def_start function_def_end { debugPrint("direct_abstract_declarator '(' ')' -> direct_abstract_declarator"); } {
		// TODO
		$$ = (void*) new DirectAbstractDeclaratorNode( 
			(DirectAbstractDeclaratorNode*) $1,
			DirectAbstractDeclaratorNode::Normal
		);
		}
	| direct_abstract_declarator function_def_start parameter_type_list function_def_end { debugPrint("direct_abstract_declarator '(' parameter_type_list ')' -> direct_abstract_declarator"); } {
		$$ = (void*) new DirectAbstractDeclaratorNode ( 
			(DirectAbstractDeclaratorNode*) $1,
			(ParameterTypeListNode*) $3
		);
		}
	;

function_def_start :
	'('
	{

		beginDeclarationSection(); symbolTable->beginScope();

	};

function_def_end:
	')'
	{

		symbolTable->endScope();

	};

statement
	: labeled_statement { debugPrint("labeled_statement -> statement"); }
	{

		$$ = (void*) new StatementNode( (LabeledStatementNode*) $1 , scanner->lastLine() );

	}
	| compound_statement { debugPrint("compound_statement -> statement"); }
	{
		$$ = (void*) new StatementNode( (CompoundStatementNode*) $1 , scanner->lastLine() );

	}
	| expression_statement { debugPrint("expression_statement -> statement"); }
	{

		$$ = (void*) new StatementNode( (ExpressionStatementNode*) $1 , scanner->lastLine() );

	}
	| selection_statement { debugPrint("selection_statement -> statement"); }
	{

		$$ = (void*) new StatementNode( (SelectionStatementNode*) $1 , scanner->lastLine() );

	}
	| iteration_statement { debugPrint("iteration_statement -> statement"); }
	{

		$$ = (void*) new StatementNode( (IterationStatementNode*) $1 , scanner->lastLine() );

	}
	| jump_statement { debugPrint("jump_statement -> statement"); }
	{

		$$ = (void*) new StatementNode( (JumpStatementNode*) $1 , scanner->lastLine() );

	}
	;

labeled_statement
	: identifier ':' statement { debugPrint("identifier ':' statement -> labeled_statement"); }
	{

		$$ = (void*) new LabeledStatementNode( (IdentifierNode*) $1 , (StatementNode*) $3 );

	}
	| CASE constant_expression ':' statement { debugPrint("CASE constant_expression ':' statement -> labeled_statement"); }
	{

		$$ = (void*) new LabeledStatementNode( (ConstantExpressionNode*) $2 , (StatementNode*) $4 );

	}
	| DEFAULT ':' statement { debugPrint("DEFAULT ':' statement -> labeled_statement"); }
	{

		$$ = (void*) new LabeledStatementNode( (StatementNode*) $3 );

	}
	;

expression_statement
	: ';' { debugPrint("';' -> expression_statement"); }
	{

		$$ = (void*) new ExpressionStatementNode();		

	}
	| expression ';' { debugPrint("expression ';' -> expression_statement"); }
	{

		$$ = (void*) new ExpressionStatementNode( (ExpressionNode*) $1 );

	}
	;

compound_statement 
	: openbrace '}' { 
		debugPrint("'{' '}' -> compound_statement"); 
	  	
		std::cout << "1111111" << std::endl;

		symbolTable->endScope();
	  }
	/* declaration mode*/ 
	| openbrace /*{ beginLookupSection();
		symbolTable->beginScope(); }*/ statement_list '}' { 
		debugPrint("'{' statement_list '}' -> compound_statement"); 
		std::cout << "222222" << std::endl;
		$$ = new CompoundStatementNode( (StatementListNode*) $2 );

		symbolTable->endScope();
	  }
	| openbrace /*{
		symbolTable->beginScope();
		beginDeclarationSection();
		debugPrint("---- Declaration Mode Start ----");
	  } */
	  declaration_list '}' { 
		debugPrint("---- Declaration Mode Done  ----");
		debugPrint("'{' declaration_list '}' -> compound_statement");
		std::cout << "33333333" << std::endl;
		$$ = new CompoundStatementNode( (DeclarationListNode*) $2 );

	  	symbolTable->endScope();
	  }
	| openbrace 
	  /*{
		//symbolTable->beginScope();
		//beginDeclarationSection();
		debugPrint("Declaration Mode Start");
	  
		std::cout << "444444" << std::endl;
	  }*/
	  declaration_list
	  {
		debugPrint("Declaration Mode Done");
		beginLookupSection();
	  }
	  statement_list '}' 
	  { 
		debugPrint("'{' declaration_list statement_list '}' -> compound_statement");
		std::cout << "Took last production in compound statement" << std::endl;
		$$ = new CompoundStatementNode( (DeclarationListNode*) $2 , (StatementListNode*) $4 );
	  	symbolTable->endScope();
	  }
	;

openbrace:
	'{' { beginDeclarationSection(); symbolTable->beginScope(); };


statement_list
	: statement { debugPrint("statement -> statement_list"); }
	{

		$$ = new StatementListNode( (StatementNode*) $1 );


	}
	| statement_list statement { debugPrint("statement_list statement -> statement_list"); }
	{

		$$ = new StatementListNode( (StatementListNode*) $1 , (StatementNode*) $2 );

	}
	;

selection_statement
	: IF '(' expression ')' statement { debugPrint("IF '(' expression ')' statement -> selection_statement"); }
	{

		$$ = (void*) new SelectionStatementNode( (ExpressionNode*) $3 , (StatementNode*) $5 , SelectionStatementNode::If );

	}
	| IF '(' expression ')' statement ELSE statement { debugPrint("IF '(' expression ')' statement ELSE statement -> selection_statement"); }
	{

		$$ = (void*) new SelectionStatementNode( (ExpressionNode*) $3 , (StatementNode*) $5 , (StatementNode*) $7 );

	}
	| SWITCH '(' expression ')' statement { debugPrint("SWITCH '(' expression ')' statement -> selection_statement"); }
	{

		$$ = (void*) new SelectionStatementNode( (ExpressionNode*) $3 , (StatementNode*) $5 , SelectionStatementNode::Switch );

	}
	;

iteration_statement
	: WHILE '(' expression ')' statement { debugPrint("WHILE '(' expression ')' statement -> iteration_statement"); }
	{

		$$ = (void*) new IterationStatementNode( (ExpressionNode*) $3 , (StatementNode*) $5 , IterationStatementNode::While );

	}
	| DO statement WHILE '(' expression ')' ';' { debugPrint("DO statement WHILE '(' expression ')' ';' -> iteration_statement"); }
	{

		$$ = (void*) new IterationStatementNode( (ExpressionNode*) $5 , (StatementNode*) $2 , IterationStatementNode::DoWhile );

	}
	| FOR '(' ';' ';' ')' statement { debugPrint("FOR '(' ';' ';' ')' statement -> iteration_statement"); }
	{

		$$ = (void*) new IterationStatementNode( 0 , 0 , 0 , (StatementNode*) $6 );

	}
	| FOR '(' ';' ';' expression ')' statement { debugPrint("FOR '(' ';' ';' expression ')' statement -> iteration_statement"); }
	{

		$$ = (void*) new IterationStatementNode( 0 , 0 , (ExpressionNode*) $5 , (StatementNode*) $7 );

	}
	| FOR '(' ';' expression ';' ')' statement { debugPrint("FOR '(' ';' expression ';' ')' statement -> iteration_statement"); }
	{
	
		$$ = (void*) new IterationStatementNode( 0 , (ExpressionNode*) $4 , 0 , (StatementNode*) $7 );

	}
	| FOR '(' ';' expression ';' expression ')' statement { debugPrint("FOR '(' ';' expression ';' expression ')' statement -> iteration_statement"); }
	{

		$$ = (void*) new IterationStatementNode( 0 , (ExpressionNode*) $4 , (ExpressionNode*) $6 , (StatementNode*) $8 );

	}
	| FOR '(' expression ';' ';' ')' statement { debugPrint("FOR '(' expression ';' ';' ')' statement -> iteration_statement"); }
	{

		$$ = (void*) new IterationStatementNode( (ExpressionNode*) $3 , 0 , 0 , (StatementNode*) $7 );

	}
	| FOR '(' expression ';' ';' expression ')' statement { debugPrint("FOR '(' expression ';' ';' expression ')' statement -> iteration_statement"); }
	{

		$$ = (void*) new IterationStatementNode( (ExpressionNode*) $3 , 0 , (ExpressionNode*) $6 , (StatementNode*) $8 );

	}
	| FOR '(' expression ';' expression ';' ')' statement { debugPrint("FOR '(' expression ';' expression ';' ')' statement -> iteration_statement"); }
	{

		$$ = (void*) new IterationStatementNode( (ExpressionNode*) $3 , (ExpressionNode*) $5 , 0 , (StatementNode*) $8 );

	}
	| FOR '(' expression ';' expression ';' expression ')' statement { debugPrint("FOR '(' expression ';' expression ';' expression ')' statement -> iteration_statement"); }
	{

		$$ = (void*) new IterationStatementNode( (ExpressionNode*) $3 , (ExpressionNode*) $5 , (ExpressionNode*) $7 , (StatementNode*) $9 );

	}
	;

jump_statement
	: GOTO identifier ';' { debugPrint("GOTO identifier ';' -> jump_statement"); }
	{

		$$ = (void*) new JumpStatementNode( (IdentifierNode*) $2 , symbolTable );

	}
	| CONTINUE ';' { debugPrint("CONTINUE ';' -> jump_statement"); }
	{

		$$ = (void*) new JumpStatementNode( JumpStatementNode::Continue );

	}
	| BREAK ';' { debugPrint("BREAK ';' -> jump_statement"); }
	{

		$$ = (void*) new JumpStatementNode( JumpStatementNode::Break );

	}
	| RETURN ';' { debugPrint("RETURN ';' -> jump_statement"); }
	{

		$$ = (void*) new JumpStatementNode( JumpStatementNode::Return );

	}
	| RETURN expression ';' { debugPrint("RETURN expression ';' -> jump_statement"); }
	{

		$$ = (void*) new JumpStatementNode( (ExpressionNode*) $2 , symbolTable );

	}
	;

expression
	: assignment_expression { debugPrint("assignment_expression -> expression"); }
	{

		$$ = (void*) new ExpressionNode( (AssignmentExpressionNode*) $1 );

	}
	| expression ',' assignment_expression { debugPrint("expression ',' assignment_expression -> expression"); }
	{

		$$ = (void*) new ExpressionNode( (ExpressionNode*) $1 , (AssignmentExpressionNode*) $3 );

	}
	;

assignment_expression
	: conditional_expression { debugPrint("conditional_expression -> assignment_expression"); }
	{

		$$ = (void*) new AssignmentExpressionNode( (ConditionalExpressionNode*) $1 );

	}
	| unary_expression assignment_operator assignment_expression { debugPrint("unary_expression assignment_operator assignment_expression -> assignment_expression"); }
	{

		$$ = (void*) new AssignmentExpressionNode( (UnaryExpressionNode*) $1 , (AssignmentOperatorNode*) $2 , (AssignmentExpressionNode*) $3 );

	}
	;

assignment_operator
	: '=' { debugPrint("'=' -> assignment_operator"); }
	{

		$$ = (void*) new AssignmentOperatorNode( AssignmentOperatorNode::Assign );

	}
	| MUL_ASSIGN { debugPrint("MUL_ASSIGN -> assignment_operator"); }
	{

		$$ = (void*) new AssignmentOperatorNode( AssignmentOperatorNode::MulAssign );

	}
	| DIV_ASSIGN { debugPrint("DIV_ASSIGN -> assignment_operator"); }
	{

		$$ = (void*) new AssignmentOperatorNode( AssignmentOperatorNode::DivAssign );

	}
	| MOD_ASSIGN { debugPrint("MOD_ASSIGN -> assignment_operator"); }
	{

		$$ = (void*) new AssignmentOperatorNode( AssignmentOperatorNode::ModAssign );

	}
	| ADD_ASSIGN { debugPrint("ADD_ASSIGN -> assignment_operator"); }
	{

		$$ = (void*) new AssignmentOperatorNode( AssignmentOperatorNode::AddAssign );

	}
	| SUB_ASSIGN { debugPrint("SUB_ASSIGN -> assignment_operator"); }
	{

		$$ = (void*) new AssignmentOperatorNode( AssignmentOperatorNode::SubAssign );

	}
	| LEFT_ASSIGN { debugPrint("LEFT_ASSIGN -> assignment_operator"); }
	{

		$$ = (void*) new AssignmentOperatorNode( AssignmentOperatorNode::LeftAssign );

	}
	| RIGHT_ASSIGN { debugPrint("RIGHT_ASSIGN -> assignment_operator"); }
	{

		$$ = (void*) new AssignmentOperatorNode( AssignmentOperatorNode::RightAssign );

	}
	| AND_ASSIGN { debugPrint("AND_ASSIGN -> assignment_operator"); }
	{

		$$ = (void*) new AssignmentOperatorNode( AssignmentOperatorNode::AndAssign );

	}
	| XOR_ASSIGN { debugPrint("XOR_ASSIGN -> assignment_operator"); }
	{

		$$ = (void*) new AssignmentOperatorNode( AssignmentOperatorNode::XORAssign );

	}
	| OR_ASSIGN { debugPrint("OR_ASSIGN -> assignment_operator"); }
	{

		$$ = (void*) new AssignmentOperatorNode( AssignmentOperatorNode::OrAssign );

	}
	;

conditional_expression
	: logical_or_expression { debugPrint("logical_or_expression -> conditional_expression"); }
	{

		$$ = (void*) new ConditionalExpressionNode( (LogicalOrExpressionNode*) $1 );

	}
	| logical_or_expression '?' expression ':' conditional_expression { debugPrint("logical_or_expression '?' expression ':' conditional_expression -> conditional_expression"); }
	{

		$$ = (void*) new ConditionalExpressionNode( (LogicalOrExpressionNode*) $1 , (ExpressionNode*) $3 , (ConditionalExpressionNode*) $5 );

	}
	;

constant_expression
	: conditional_expression { debugPrint("conditional_expression -> constant_expression"); }
	{

		$$ = (void*) new ConstantExpressionNode( (ConditionalExpressionNode*) $1 );

	}
	;

logical_or_expression
	: logical_and_expression { debugPrint("logical_and_expression -> logical_or_expression"); }
	{
	
		$$ = (void*) new LogicalOrExpressionNode( (LogicalAndExpressionNode*) $1 );
	
	}
	| logical_or_expression OR_OP logical_and_expression { debugPrint("logical_or_expression OR_OP logical_and_expression -> logical_or_expression"); }
	{
	
		$$ = (void*) new LogicalOrExpressionNode( (LogicalOrExpressionNode*) $1 , (LogicalAndExpressionNode*) $3 );
	
	}
	;

logical_and_expression
	: inclusive_or_expression { debugPrint("inclusive_or_expression -> logical_and_expression"); }
	{
	
		$$ = (void*) new LogicalAndExpressionNode( (InclusiveOrExpressionNode*) $1 );
	
	}
	| logical_and_expression AND_OP inclusive_or_expression { debugPrint("logical_and_expression AND_OP inclusive_or_expression -> logical_and_expression"); }
	{
	
		$$ = (void*) new LogicalAndExpressionNode( (LogicalAndExpressionNode*) $1 , (InclusiveOrExpressionNode*) $3 );
	
	}
	;

inclusive_or_expression
	: exclusive_or_expression { debugPrint("exclusive_or_expression -> inclusive_or_expression"); }
	{

		$$ = (void*) new InclusiveOrExpressionNode( (ExclusiveOrExpressionNode*) $1 );

	}
	| inclusive_or_expression '|' exclusive_or_expression { debugPrint("inclusive_or_expression '|' exclusive_or_expression -> inclusive_or_expression"); }
	{

		$$ = (void*) new InclusiveOrExpressionNode( (InclusiveOrExpressionNode*) $1 , (ExclusiveOrExpressionNode*) $3 );

	}
	;

exclusive_or_expression
	: and_expression { debugPrint("and_expression -> exclusive_or_expression"); }
	{

		$$ = (void*) new ExclusiveOrExpressionNode( (AndExpressionNode*) $1 );

	}
	| exclusive_or_expression '^' and_expression { debugPrint("exclusive_or_expression '^' and_expression -> exclusive_or_expression"); }
	{

		$$ = (void*) new ExclusiveOrExpressionNode( (ExclusiveOrExpressionNode*) $1 , (AndExpressionNode*) $3 );

	}
	;

and_expression
	: equality_expression { debugPrint("equality_expression -> and_expression"); }
	{

		$$ = (void*) new AndExpressionNode( (EqualityExpressionNode*) $1 );

	}
	| and_expression '&' equality_expression { debugPrint("and_expression '&' equality_expression -> and_expression"); }
	{

		$$ = (void*) new AndExpressionNode( (AndExpressionNode*) $1 , (EqualityExpressionNode*) $3 );

	}
	;

equality_expression
	: relational_expression { debugPrint("relational_expression -> equality_expression"); }
	{

		$$ = (void*) new EqualityExpressionNode( (RelationalExpressionNode*) $1 );

	}
	| equality_expression EQ_OP relational_expression { debugPrint("equality_expression EQ_OP relational_expression -> equality_expression"); }
	{

		$$ = (void*) new EqualityExpressionNode( (EqualityExpressionNode*) $1 , (RelationalExpressionNode*) $3 , EqualityExpressionNode::Equal );

	}
	| equality_expression NE_OP relational_expression { debugPrint("equality_expression NE_OP relational_expression -> equality_expression"); }
	{

		$$ = (void*) new EqualityExpressionNode( (EqualityExpressionNode*) $1 , (RelationalExpressionNode*) $3 , EqualityExpressionNode::NotEqual );

	}
	;

relational_expression
	: shift_expression { debugPrint("shift_expression -> relational_expression"); }
	{

		$$ = (void*) new RelationalExpressionNode( (ShiftExpressionNode*) $1 );

	}
	| relational_expression '<' shift_expression { debugPrint("relational_expression '<' shift_expression -> relational_expression"); }
	{

		$$ = (void*) new RelationalExpressionNode( (RelationalExpressionNode*) $1 , (ShiftExpressionNode*) $3 , RelationalExpressionNode::Less );

	}
	| relational_expression '>' shift_expression { debugPrint("relational_expression '>' shift_expression -> relational_expression"); }
	{

		$$ = (void*) new RelationalExpressionNode( (RelationalExpressionNode*) $1 , (ShiftExpressionNode*) $3 , RelationalExpressionNode::Greater );

	}
	| relational_expression LE_OP shift_expression { debugPrint("relational_expression LE_OP shift_expression -> relational_expression"); }
	{

		$$ = (void*) new RelationalExpressionNode( (RelationalExpressionNode*) $1 , (ShiftExpressionNode*) $3 , RelationalExpressionNode::LessEqual );

	}
	| relational_expression GE_OP shift_expression { debugPrint("relational_expression GE_OP shift_expression -> relational_expression"); }
	{

		$$ = (void*) new RelationalExpressionNode( (RelationalExpressionNode*) $1 , (ShiftExpressionNode*) $3 , RelationalExpressionNode::GreaterEqual );

	}
	;

shift_expression
	: additive_expression { debugPrint("additive_expression -> shift_expression"); }
	{

		$$ = (void*) new ShiftExpressionNode( (AdditiveExpressionNode*) $1 );

	}
	| shift_expression LEFT_OP additive_expression { debugPrint("shift_expression LEFT_OP additive_expression -> shift_expression"); }
	{

		$$ = (void*) new ShiftExpressionNode( (ShiftExpressionNode*) $1 , (AdditiveExpressionNode*) $3 , ShiftExpressionNode::Left );

	}
	| shift_expression RIGHT_OP additive_expression { debugPrint("shift_expression RIGHT_OP additive_expression -> shift_expression"); }
	{

		$$ = (void*) new ShiftExpressionNode( (ShiftExpressionNode*) $1 , (AdditiveExpressionNode*) $3 , ShiftExpressionNode::Left );

	}
	;

additive_expression
	: multiplicative_expression { debugPrint("multiplicative_expression -> additive_expression"); }
	{

		$$ = (void*) new AdditiveExpressionNode( (MultiplicativeExpressionNode*) $1 );

	}
	| additive_expression '+' multiplicative_expression { debugPrint("additive_expression '+' multiplicative_expression -> additive_expression"); }
	{

		$$ = (void*) new AdditiveExpressionNode( (AdditiveExpressionNode*) $1 , (MultiplicativeExpressionNode*) $3 , AdditiveExpressionNode::Add );

	}
	| additive_expression '-' multiplicative_expression { debugPrint("additive_expression '-' multiplicative_expression -> additive_expression"); }
	{

		$$ = (void*) new AdditiveExpressionNode( (AdditiveExpressionNode*) $1 , (MultiplicativeExpressionNode*) $3 , AdditiveExpressionNode::Subtract );

	}
	;

multiplicative_expression
	: cast_expression { debugPrint("cast_expression -> multiplicative_expression"); }
	{

		$$ = (void*) new MultiplicativeExpressionNode( (CastExpressionNode*) $1 );

	}
	| multiplicative_expression '*' cast_expression { debugPrint("multiplicative_expression '*' cast_expression -> multiplicative_expression"); }
	{

		$$ = (void*) new MultiplicativeExpressionNode( (MultiplicativeExpressionNode*) $1 , (CastExpressionNode*) $3 , MultiplicativeExpressionNode::Multiply );

	}
	| multiplicative_expression '/' cast_expression { debugPrint("multiplicative_expression '/' cast_expression -> multiplicative_expression"); }
	{

		$$ = (void*) new MultiplicativeExpressionNode( (MultiplicativeExpressionNode*) $1 , (CastExpressionNode*) $3 , MultiplicativeExpressionNode::Divide );

	}
	| multiplicative_expression '%' cast_expression { debugPrint("multiplicative_expression '%' cast_expression -> multiplicative_expression"); }
	{

		$$ = (void*) new MultiplicativeExpressionNode( (MultiplicativeExpressionNode*) $1 , (CastExpressionNode*) $3 , MultiplicativeExpressionNode::Modulo );

	}
	;

cast_expression
	: unary_expression { debugPrint("unary_expression -> cast_expression"); }
	{

		$$ = (void*) new CastExpressionNode( (UnaryExpressionNode*) $1 );

	}
	| '(' type_name ')' cast_expression { debugPrint("'(' type_name ')' cast_expression -> cast_expression"); }
	{

		$$ = (void*) new CastExpressionNode( (TypeNameNode*) $2 , (CastExpressionNode*) $4 );

	}
	;

unary_expression
	: postfix_expression { debugPrint("postfix_expression -> unary_expression"); }
	{

		$$ = (void*) new UnaryExpressionNode( (PostfixExpressionNode*) $1 );	

	}
	| INC_OP unary_expression { debugPrint("INC_OP unary_expression -> unary_expression"); }
	{

		$$ = (void*) new UnaryExpressionNode( (UnaryExpressionNode*) $2 , UnaryExpressionNode::Increment );

	}
	| DEC_OP unary_expression { debugPrint("DEC_OP unary_expression -> unary_expression"); }
	{

		$$ = (void*) new UnaryExpressionNode( (UnaryExpressionNode*) $2 , UnaryExpressionNode::Decrement );

	}
	| unary_operator cast_expression { debugPrint("unary_operator cast_expression -> unary_expression"); }
	{

		$$ = (void*) new UnaryExpressionNode( (UnaryOperatorNode*) $1 , (CastExpressionNode*) $2 );

	}
	| SIZEOF unary_expression { debugPrint("SIZEOF unary_expression -> unary_expression"); }
	{

		$$ = (void*) new UnaryExpressionNode( (UnaryExpressionNode*) $1 , UnaryExpressionNode::SizeofExpression );

	}
	| SIZEOF '(' type_name ')' { debugPrint("SIZEOF '(' type_name ')' -> unary_expression"); }
	{

		// TODO BUG?  should insert sizeof ?
		$$ = (void*) new UnaryExpressionNode( (TypeNameNode*) $1  ); 

	}
	;

unary_operator
	: '&' { debugPrint("'&' -> unary_operator"); }
	{

		$$ = (void*) new UnaryOperatorNode( UnaryOperatorNode::Address );

	}
	| '*' { debugPrint("'*' -> unary_operator"); }
	{

		$$ = (void*) new UnaryOperatorNode( UnaryOperatorNode::Indirection );

	}
	| '+' { debugPrint("'+' -> unary_operator"); }
	{

		$$ = (void*) new UnaryOperatorNode( UnaryOperatorNode::Positive );

	}
	| '-' { debugPrint("'-' -> unary_operator"); }
	{

		$$ = (void*) new UnaryOperatorNode( UnaryOperatorNode::Negative );

	}
	| '~' { debugPrint("'~' -> unary_operator"); }
	{

		$$ = (void*) new UnaryOperatorNode( UnaryOperatorNode::BitwiseNot );

	}
	| '!' { debugPrint("'!' -> unary_operator"); }
	{

		$$ = (void*) new UnaryOperatorNode( UnaryOperatorNode::Address ); // BUG?

	}
	;

postfix_expression
	: primary_expression { debugPrint("primary_expression -> postfix_expression"); }
	{
	
		$$ = (void*) new PostfixExpressionNode( (PrimaryExpressionNode*) $1 );

	}
	| postfix_expression '[' expression ']' { debugPrint("postfix_expression '[' expression ']' -> postfix_expression"); }
	{

		$$ = (void*) new PostfixExpressionNode( (PostfixExpressionNode*) $1 , (ExpressionNode*) $3 );

	}
	| postfix_expression '(' ')' { debugPrint("postfix_expression '(' ')' -> postfix_expression"); }
	{

		$$ = (void*) new PostfixExpressionNode( (PostfixExpressionNode*) $1 , PostfixExpressionNode::FunctionCall );

	}
	| postfix_expression '(' argument_expression_list ')' { debugPrint("postfix_expression '(' argument_expression_list ')' -> postfix_expression"); }
	{

		$$ = (void*) new PostfixExpressionNode( (PostfixExpressionNode*) $1 , (ArgExpressionListNode*) $3 );

	}
	| postfix_expression '.' identifier { debugPrint("postfix_expression '.' identifier -> postfix_expression"); }
	{

		$$ = (void*) new PostfixExpressionNode( (PostfixExpressionNode*) $1 , (IdentifierNode*) $3 , PostfixExpressionNode::DirectMemberAccess );

	}
	| postfix_expression PTR_OP identifier { debugPrint("postfix_expression PTR_OP identifier -> postfix_expression"); }
	{

		$$ = (void*) new PostfixExpressionNode( (PostfixExpressionNode*) $1 , (IdentifierNode*) $3 , PostfixExpressionNode::PointerMemberAccess );

	}
	| postfix_expression INC_OP { debugPrint("postfix_expression INC_OP -> postfix_expression"); }
	{

		$$ = (void*) new PostfixExpressionNode( (PostfixExpressionNode*) $1 , PostfixExpressionNode::Increment );

	}
	| postfix_expression DEC_OP { debugPrint("postfix_expression DEC_OP -> postfix_expression"); }
	{

		$$ = (void*) new PostfixExpressionNode( (PostfixExpressionNode*) $1 , PostfixExpressionNode::Decrement );

	}
	;

primary_expression
	: identifier { debugPrint("identifier -> primary_expression"); } {
		$$ = (void*) new PrimaryExpressionNode( (IdentifierNode*) $1 );
		}
	| constant { debugPrint("constant -> primary_expression"); } { 
		$$ = (void*) new PrimaryExpressionNode( (ConstantNode*) $1 );
		}
	| string { debugPrint("string -> primary_expression"); }
	{
	
		$$ = (void*) new PrimaryExpressionNode( (StringNode*) $1 );
	
	}
	| '(' expression ')' { debugPrint("'(' expression ')' -> primary_expression"); } 
	{
	
		$$ = (void*) new PrimaryExpressionNode( (ExpressionNode*) $2 );
	
	}
	;

argument_expression_list
	: assignment_expression { debugPrint("assignment_expression -> argument_expression_list"); }
	{
	
		$$ = (void*) new ArgExpressionListNode( (AssignmentExpressionNode*) $1 );
	
	}
	| argument_expression_list ',' assignment_expression { debugPrint("argument_expression_list ',' assignment_expression -> argument_expression_list"); }
	{
	
		$$ = (void*) new ArgExpressionListNode( (ArgExpressionListNode*) $3 , (AssignmentExpressionNode*) $1 ); // $BUG
	
	}
	;

constant
	: I_CONSTANT /* includes character_constant */ { 

			// Convert the string integer constant to integer
			std::string match = scanner->matched();
			long long i = atoi( match.c_str() );
			
			$$ = (void*) new ConstantNode( new IntegerConstantNode( i ) );

			debugPrint("I_CONSTANT -> constant"); 
		}
	| F_CONSTANT { 
			// TODO should this be float or double ? atof returns double
			std::string match = scanner->matched();
			double f = atof( match.c_str() );
			
			$$ = (void*) new ConstantNode( new FloatConstantNode( f ) );

			debugPrint("F_CONSTANT -> constant"); 
		}
	| CHAR_LITERAL { 
			std::string match = scanner->matched();
			char c = ( match.c_str() )[0];

			$$ = (void*) new ConstantNode( new CharConstantNode( c ) );
		
			debugPrint("CHAR_LITERAL -> constant"); 
		}
	| ENUMERATION_CONSTANT	/* after it has been defined as such */ { 
		// MAYBE
		debugPrint("ENUMERATION_CONSTANT -> constant"); 
		}
	;

string
	: STRING_LITERAL { debugPrint("STRING_LITERAL -> string"); }
	{
	
	$$ = (void*) new StringNode( scanner->matched() );
	
	}
	;

identifier
	: IDENTIFIER { debugPrint("IDENTIFIER -> identifier"); }
	{

	if( isDeclarationMode() )
	{
		//setDeclarationLocation();
		pushIdentifier();

		Symbol* sym = new Symbol( scanner->matched() , scanner->getLoc() );
		symbolTable->insertSymbol( sym );

		$$ =  new IdentifierNode( symbolTable , scanner->matched() , true );
	}
	else
	{
	
		try {
		
			$$ =  new IdentifierNode( symbolTable , scanner->matched() , false );
		
		}
		
		catch( SymbolNotFoundException* e )
		{
		
			std::cout << e->mesg + " @ " << scanner->getLoc().lnum << ":" << scanner->getLoc().cnum << "\n";

			exit(1);

		}

	}

	}
	;
