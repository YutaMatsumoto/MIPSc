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
%stype Node*

%lsp-needed
%debug

%%

translation_unit
	: external_declaration { debugPrint("external_declaration -> translation_unit"); }
	| translation_unit external_declaration { debugPrint("translation_unit external_declaration -> translation_unit"); }
	;

external_declaration
	: function_definition { debugPrint("function_definition -> external_declaration"); }
	| declaration { 
		debugPrint("declaration -> external_declaration"); 
	  }
	;

function_definition
	: declarator compound_statement { 
		debugPrint("----to function_definition by production 1----"); 
		debugPrint("declarator compound_statement -> function_definition"); 
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
	  }
	| declaration_specifiers declarator compound_statement { 
		debugPrint("----to function_definition by production 3----"); 
	  	debugPrint("declaration_specifiers declarator compound_statement -> function_definition"); 
	  }
	| declaration_specifiers declarator {
		// declaration mode start
	  } 
	  declaration_list {
		// declaration mode end
	  }
	  compound_statement { 
		debugPrint("----to function definition production 4----"); 
	    debugPrint("declaration_specifiers declarator declaration_list compound_statement -> function_definition"); 
	  }
	;

declaration
	: declaration_specifiers ';' { 
		// TODO : Is this legal???
		
		debugPrint("declaration_specifiers ';' -> declaration"); 
	  }
	| declaration_specifiers init_declarator_list ';' { 
		declare();
		debugPrint("declaration_specifiers init_declarator_list ';' -> declaration"); 
	  }
	;

declaration_list
	: declaration { 
		//endDeclarationSection();
		debugPrint("declaration -> declaration_list"); 
	  }
	| declaration_list declaration { debugPrint("declaration_list declaration -> declaration_list"); }
	;

declaration_specifiers
	: storage_class_specifier { 
		// TODO : is this legal???
		determineType();
		debugPrint("storage_class_specifier -> declaration_specifiers"); 
	  }
	| storage_class_specifier declaration_specifiers { debugPrint("storage_class_specifier declaration_specifiers -> declaration_specifiers"); }
	| type_specifier { 
		TypeSpecifierNode* ts = static_cast<TypeSpecifierNode*>( $1 );
		determineType();
		debugPrint("type_specifier -> declaration_specifiers"); 
	  }
	| type_specifier declaration_specifiers { debugPrint("type_specifier declaration_specifiers -> declaration_specifiers"); }
	| type_qualifier  { 
		// TODO : is this legal???
		determineType();
		debugPrint("type_qualifier  -> declaration_specifiers"); 
	  }
	| type_qualifier declaration_specifiers { debugPrint("type_qualifier declaration_specifiers -> declaration_specifiers"); }
	;

storage_class_specifier
	: AUTO { 
		$$ = (Node*) new StorageSpecifierNode(StorageSpecifierNode::Auto);
		debugPrint("AUTO -> storage_class_specifier"); 
		}
	| REGISTER { 
		$$ = (Node*) new StorageSpecifierNode(StorageSpecifierNode::Register);
		debugPrint("REGISTER -> storage_class_specifier"); 
		}
	| STATIC { 
		$$ = (Node*) new StorageSpecifierNode(StorageSpecifierNode::Static);
		debugPrint("STATIC -> storage_class_specifier"); 
		}
	| EXTERN { 
		$$ = (Node*) new StorageSpecifierNode(StorageSpecifierNode::Extern);
		debugPrint("EXTERN -> storage_class_specifier"); 
		}
	| TYPEDEF { 
		$$ = (Node*) new StorageSpecifierNode(StorageSpecifierNode::Typedef);
		debugPrint("TYPEDEF -> storage_class_specifier"); 
		}
	;

type_specifier
	: VOID { 
		debugPrint("VOID -> type_specifier");
		$$ = new TypeSpecifierNode( TypeSpecifierNode::Void );
		/* addTypeSpecifier(); */
	  } // { /*currentDeclaration*/ }
	| CHAR { 
		/* addTypeSpecifier(); */
		$$ = new TypeSpecifierNode( TypeSpecifierNode::Char );
		debugPrint("CHAR -> type_specifier"); 
	  }
	| SHORT { debugPrint("SHORT -> type_specifier"); 
		$$ = new TypeSpecifierNode( TypeSpecifierNode::Short );
		addTypeSpecifier();
	  }
	| INT { 
		/* addTypeSpecifier(); */
		$$ = new TypeSpecifierNode( TypeSpecifierNode::Int );
		debugPrint("INT -> type_specifier"); 
	  }
	| LONG {
		/* addTypeSpecifier(); */
		$$ = new TypeSpecifierNode( TypeSpecifierNode::Long );
		debugPrint("LONG -> type_specifier"); 
	  }
	| FLOAT  {
		/* addTypeSpecifier(); */
		$$ = new TypeSpecifierNode( TypeSpecifierNode::Float );
		 debugPrint("FLOAT  -> type_specifier"); 
	  }
	| DOUBLE {
		/* addTypeSpecifier(); */
		$$ = new TypeSpecifierNode( TypeSpecifierNode::Double );
		debugPrint("DOUBLE -> type_specifier"); 
	  }
	| SIGNED {
		addTypeSpecifier();
		$$ = new TypeSpecifierNode( TypeSpecifierNode::Signed );
		debugPrint("SIGNED -> type_specifier"); 
	  }
	| UNSIGNED {
		addTypeSpecifier();
		$$ = new TypeSpecifierNode( TypeSpecifierNode::Unsigned );
		debugPrint("UNSIGNED -> type_specifier"); 
	  }
	| struct_or_union_specifier {
		// TODO 
		// addTypeSpecifier();
		//throw ParserError(ParserError::NotImplemented, "Sturuct/Union is not implemented");
		debugPrint("struct_or_union_specifier -> type_specifier"); 
	  }
	| enum_specifier {
		// TODO 
		// addTypeSpecifier();
		//throw ParserError(ParserError::NotImplemented, "enum is not implemented");
		debugPrint("enum_specifier -> type_specifier"); 
	  }
	| TYPEDEF_NAME {
		$$ = new TypeSpecifierNode( TypeSpecifierNode::Typedef );
		debugPrint("TYPEDEF_NAME -> type_specifier"); 
	  }
	;

type_qualifier
	: CONST { 
		setConst();
		debugPrint("CONST -> type_qualifier"); 
	  }
	| VOLATILE { 
		setVolitle();
		debugPrint("VOLATILE -> type_qualifier"); 
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
	: init_declarator { debugPrint("init_declarator -> init_declarator_list"); }
	| init_declarator_list ',' init_declarator { debugPrint("init_declarator_list ',' init_declarator -> init_declarator_list"); }
	;

init_declarator
	: declarator { debugPrint("declarator -> init_declarator"); }
	| declarator '=' initializer { 
		// TODO : initialize here or even before when something reduces to initializer ?
		/* initializeValue(); */
		debugPrint("declarator '=' initializer -> init_declarator"); 
	  }
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';' { debugPrint("specifier_qualifier_list struct_declarator_list ';' -> struct_declaration"); }
	;

specifier_qualifier_list
	: type_specifier { debugPrint("type_specifier -> specifier_qualifier_list"); }
	| type_specifier specifier_qualifier_list { debugPrint("type_specifier specifier_qualifier_list -> specifier_qualifier_list"); }
	| type_qualifier { debugPrint("type_qualifier -> specifier_qualifier_list"); }
	| type_qualifier specifier_qualifier_list { debugPrint("type_qualifier specifier_qualifier_list -> specifier_qualifier_list"); }
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
	: direct_declarator { debugPrint("direct_declarator -> declarator"); }
	| pointer direct_declarator { debugPrint("pointer direct_declarator -> declarator"); }
	;

direct_declarator
	: identifier { 
			//^^ Can the scanner match on a non-terminal?
			//pushIdentifier();
			debugPrint("identifier -> direct_declarator"); 
		}
	| '(' declarator ')' { 
			// TODO : what's this guy???
			debugPrint("'(' declarator ')' -> direct_declarator"); 
		}
	| direct_declarator '[' ']' { 
			specifyArray();
			debugPrint("direct_declarator '[' ']' -> direct_declarator"); 
		}
	| direct_declarator '[' constant_expression ']' { 
			// TODO : harness constant_expression
			specifyArray();
			debugPrint("direct_declarator '[' constant_expression ']' -> direct_declarator"); 
		}
	| direct_declarator '(' ')' { 
			// TODO : function call or structure instantiation ?
			debugPrint("direct_declarator '(' ')' -> direct_declarator"); 
		}
	| direct_declarator '(' parameter_type_list ')' { 
			specifyFunction();
			debugPrint("direct_declarator '(' parameter_type_list ')' -> direct_declarator"); 
		}
	| direct_declarator '(' identifier_list ')' { 
			specifyFunctionCall();	// TODO : or structure instantiation ?
			debugPrint("direct_declarator '(' identifier_list ')' -> direct_declarator"); 
		}
	;

pointer
	: '*' { debugPrint("'*' -> pointer"); }
	| '*' type_qualifier_list { debugPrint("'*' type_qualifier_list -> pointer"); }
	| '*' pointer { debugPrint("'*' pointer -> pointer"); }
	| '*' type_qualifier_list pointer { debugPrint("'*' type_qualifier_list pointer -> pointer"); }
	;

type_qualifier_list
	: type_qualifier { debugPrint("type_qualifier -> type_qualifier_list"); }
	| type_qualifier_list type_qualifier { debugPrint("type_qualifier_list type_qualifier -> type_qualifier_list"); }
	;

parameter_type_list
	: parameter_list { debugPrint("parameter_list -> parameter_type_list"); }
	| parameter_list ',' ELLIPSIS { debugPrint("parameter_list ',' ELLIPSIS -> parameter_type_list"); }
	;

parameter_list
	: parameter_declaration { debugPrint("parameter_declaration -> parameter_list"); }
	| parameter_list ',' parameter_declaration { debugPrint("parameter_list ',' parameter_declaration -> parameter_list"); }
	;

parameter_declaration
	: declaration_specifiers declarator { debugPrint("declaration_specifiers declarator -> parameter_declaration"); }
	| declaration_specifiers { debugPrint("declaration_specifiers -> parameter_declaration"); }
	| declaration_specifiers abstract_declarator { debugPrint("declaration_specifiers abstract_declarator -> parameter_declaration"); }
	;

identifier_list
	: identifier { debugPrint("identifier -> identifier_list"); }
	| identifier_list ',' identifier { debugPrint("identifier_list ',' identifier -> identifier_list"); }
	;

initializer
	: assignment_expression { debugPrint("assignment_expression -> initializer"); }
	| '{' initializer_list '}' { 
			initializeArray();
			debugPrint("'{' initializer_list ' }' -> initializer"); 
		}
	| '{' initializer_list ',' '}' { 
			initializeArray();
			debugPrint("'{' initializer_list ',' '}' -> initializer"); 
		}
	;

initializer_list
	: initializer { 
			addValueToArray();
			debugPrint("initializer -> initializer_list"); 
		}
	| initializer_list ',' initializer { 
			addValueToArray();
			debugPrint("initializer_list ',' initializer -> initializer_list"); 
		}
	;

type_name
	: specifier_qualifier_list { debugPrint("specifier_qualifier_list -> type_name"); }
	| specifier_qualifier_list abstract_declarator { debugPrint("specifier_qualifier_list abstract_declarator -> type_name"); }
	;

abstract_declarator
	: pointer { debugPrint("pointer -> abstract_declarator"); }
	| direct_abstract_declarator { debugPrint("direct_abstract_declarator -> abstract_declarator"); }
	| pointer direct_abstract_declarator { debugPrint("pointer direct_abstract_declarator -> abstract_declarator"); }
	;

direct_abstract_declarator
	: '(' abstract_declarator ')' { debugPrint("'(' abstract_declarator ')' -> direct_abstract_declarator"); }
	| '[' ']' { debugPrint("'[' ']' -> direct_abstract_declarator"); }
	| '[' constant_expression ']' { debugPrint("'[' constant_expression ']' -> direct_abstract_declarator"); }
	| direct_abstract_declarator '[' ']' { debugPrint("direct_abstract_declarator '[' ']' -> direct_abstract_declarator"); }
	| direct_abstract_declarator '[' constant_expression ']' { debugPrint("direct_abstract_declarator '[' constant_expression ']' -> direct_abstract_declarator"); }
	| '(' ')' { debugPrint("'(' ')' -> direct_abstract_declarator"); }
	| '(' parameter_type_list ')' { debugPrint("'(' parameter_type_list ')' -> direct_abstract_declarator"); }
	| direct_abstract_declarator '(' ')' { debugPrint("direct_abstract_declarator '(' ')' -> direct_abstract_declarator"); }
	| direct_abstract_declarator '(' parameter_type_list ')' { debugPrint("direct_abstract_declarator '(' parameter_type_list ')' -> direct_abstract_declarator"); }
	;

statement
	: labeled_statement { debugPrint("labeled_statement -> statement"); }
	| compound_statement { debugPrint("compound_statement -> statement"); }
	| expression_statement { debugPrint("expression_statement -> statement"); }
	| selection_statement { debugPrint("selection_statement -> statement"); }
	| iteration_statement { debugPrint("iteration_statement -> statement"); }
	| jump_statement { debugPrint("jump_statement -> statement"); }
	;

labeled_statement
	: identifier ':' statement { debugPrint("identifier ':' statement -> labeled_statement"); }
	| CASE constant_expression ':' statement { debugPrint("CASE constant_expression ':' statement -> labeled_statement"); }
	| DEFAULT ':' statement { debugPrint("DEFAULT ':' statement -> labeled_statement"); }
	;

expression_statement
	: ';' { debugPrint("';' -> expression_statement"); }
	| expression ';' { debugPrint("expression ';' -> expression_statement"); }
	;

compound_statement
	: '{' '}' { 
		debugPrint("'{' '}' -> compound_statement"); 
	  }
	/* declaration mode*/ 
	| '{' { beginLookupSection();
		symbolTable->beginScope(); } statement_list '}' { 
		symbolTable->endScope();
		debugPrint("'{' statement_list '}' -> compound_statement"); 
	  }
	| '{' {
		symbolTable->beginScope();
		beginDeclarationSection();
		debugPrint("---- Declaration Mode Start ----");
	  } 
	  declaration_list '}' { 
	  	symbolTable->endScope();
		debugPrint("---- Declaration Mode Done  ----");
		debugPrint("'{' declaration_list '}' -> compound_statement"); 
	  }
	| '{' {
		symbolTable->beginScope();
		beginDeclarationSection();
		debugPrint("Declaration Mode Start");
	  }
	  declaration_list {
		debugPrint("Declaration Mode Done");
		beginLookupSection();
	  }
	  statement_list '}' { 
		debugPrint("'{' declaration_list statement_list '}' -> compound_statement"); 
	  }
	;

statement_list
	: statement { debugPrint("statement -> statement_list"); }
	| statement_list statement { debugPrint("statement_list statement -> statement_list"); }
	;

selection_statement
	: IF '(' expression ')' statement { debugPrint("IF '(' expression ')' statement -> selection_statement"); }
	| IF '(' expression ')' statement ELSE statement { debugPrint("IF '(' expression ')' statement ELSE statement -> selection_statement"); }
	| SWITCH '(' expression ')' statement { debugPrint("SWITCH '(' expression ')' statement -> selection_statement"); }
	;

iteration_statement
	: WHILE '(' expression ')' statement { debugPrint("WHILE '(' expression ')' statement -> iteration_statement"); }
	| DO statement WHILE '(' expression ')' ';' { debugPrint("DO statement WHILE '(' expression ')' ';' -> iteration_statement"); }
	| FOR '(' ';' ';' ')' statement { debugPrint("FOR '(' ';' ';' ')' statement -> iteration_statement"); }
	| FOR '(' ';' ';' expression ')' statement { debugPrint("FOR '(' ';' ';' expression ')' statement -> iteration_statement"); }
	| FOR '(' ';' expression ';' ')' statement { debugPrint("FOR '(' ';' expression ';' ')' statement -> iteration_statement"); }
	| FOR '(' ';' expression ';' expression ')' statement { debugPrint("FOR '(' ';' expression ';' expression ')' statement -> iteration_statement"); }
	| FOR '(' expression ';' ';' ')' statement { debugPrint("FOR '(' expression ';' ';' ')' statement -> iteration_statement"); }
	| FOR '(' expression ';' ';' expression ')' statement { debugPrint("FOR '(' expression ';' ';' expression ')' statement -> iteration_statement"); }
	| FOR '(' expression ';' expression ';' ')' statement { debugPrint("FOR '(' expression ';' expression ';' ')' statement -> iteration_statement"); }
	| FOR '(' expression ';' expression ';' expression ')' statement { debugPrint("FOR '(' expression ';' expression ';' expression ')' statement -> iteration_statement"); }
	;

jump_statement
	: GOTO identifier ';' { debugPrint("GOTO identifier ';' -> jump_statement"); }
	| CONTINUE ';' { debugPrint("CONTINUE ';' -> jump_statement"); }
	| BREAK ';' { debugPrint("BREAK ';' -> jump_statement"); }
	| RETURN ';' { debugPrint("RETURN ';' -> jump_statement"); }
	| RETURN expression ';' { debugPrint("RETURN expression ';' -> jump_statement"); }
	;

expression
	: assignment_expression { debugPrint("assignment_expression -> expression"); }
	| expression ',' assignment_expression { debugPrint("expression ',' assignment_expression -> expression"); }
	;

assignment_expression
	: conditional_expression { debugPrint("conditional_expression -> assignment_expression"); }
	| unary_expression assignment_operator assignment_expression { debugPrint("unary_expression assignment_operator assignment_expression -> assignment_expression"); }
	;

assignment_operator
	: '=' { debugPrint("'=' -> assignment_operator"); }
	| MUL_ASSIGN { debugPrint("MUL_ASSIGN -> assignment_operator"); }
	| DIV_ASSIGN { debugPrint("DIV_ASSIGN -> assignment_operator"); }
	| MOD_ASSIGN { debugPrint("MOD_ASSIGN -> assignment_operator"); }
	| ADD_ASSIGN { debugPrint("ADD_ASSIGN -> assignment_operator"); }
	| SUB_ASSIGN { debugPrint("SUB_ASSIGN -> assignment_operator"); }
	| LEFT_ASSIGN { debugPrint("LEFT_ASSIGN -> assignment_operator"); }
	| RIGHT_ASSIGN { debugPrint("RIGHT_ASSIGN -> assignment_operator"); }
	| AND_ASSIGN { debugPrint("AND_ASSIGN -> assignment_operator"); }
	| XOR_ASSIGN { debugPrint("XOR_ASSIGN -> assignment_operator"); }
	| OR_ASSIGN { debugPrint("OR_ASSIGN -> assignment_operator"); }
	;

conditional_expression
	: logical_or_expression { debugPrint("logical_or_expression -> conditional_expression"); }
	| logical_or_expression '?' expression ':' conditional_expression { debugPrint("logical_or_expression '?' expression ':' conditional_expression -> conditional_expression"); }
	;

constant_expression
	: conditional_expression { debugPrint("conditional_expression -> constant_expression"); }
	;

logical_or_expression
	: logical_and_expression { debugPrint("logical_and_expression -> logical_or_expression"); }
	{
	
		$$ = new LogicalOrExpressionNode( (LogicalAndExpressionNode*) $1 );
	
	}
	| logical_or_expression OR_OP logical_and_expression { debugPrint("logical_or_expression OR_OP logical_and_expression -> logical_or_expression"); }
	{
	
		$$ = new LogicalOrExpressionNode( (InclusiveOrExpressionNode*) $1 , (LogicalAndExpressionNode*) $3 );
	
	}
	;

logical_and_expression
	: inclusive_or_expression { debugPrint("inclusive_or_expression -> logical_and_expression"); }
	{
	
		$$ = new LogicalAndExpressionNode( (InclusiveOrExpressionNode*) $1 );
	
	}
	| logical_and_expression AND_OP inclusive_or_expression { debugPrint("logical_and_expression AND_OP inclusive_or_expression -> logical_and_expression"); }
	{
	
		$$ = new LogicalAndExpressionNode( (InclusiveOrExpressionNode*) $1 , (LogicalAndExpressionNode*) $3 );
	
	}
	;

inclusive_or_expression
	: exclusive_or_expression { debugPrint("exclusive_or_expression -> inclusive_or_expression"); }
	{

		$$ = new InclusiveOrExpressionNode( (ExclusiveOrExpressionNode*) $1 );

	}
	| inclusive_or_expression '|' exclusive_or_expression { debugPrint("inclusive_or_expression '|' exclusive_or_expression -> inclusive_or_expression"); }
	{

		$$ = new InclusiveOrExpressionNode( (InclusiveOrExpressionNode*) $1 , (ExclusiveOrExpressionNode*) $3 );

	}
	;

exclusive_or_expression
	: and_expression { debugPrint("and_expression -> exclusive_or_expression"); }
	{

		$$ = new ExclusiveOrExpressionNode( (AndExpressionNode*) $1 );

	}
	| exclusive_or_expression '^' and_expression { debugPrint("exclusive_or_expression '^' and_expression -> exclusive_or_expression"); }
	{

		$$ = new ExclusiveOrExpressionNode( (ExclusiveOrExpressionNode*) $1 , (AndExpressionNode*) $3 );

	}
	;

and_expression
	: equality_expression { debugPrint("equality_expression -> and_expression"); }
	{

		$$ = new AndExpressionNode( (EqualityExpressionNode*) $1 );

	}
	| and_expression '&' equality_expression { debugPrint("and_expression '&' equality_expression -> and_expression"); }
	{

		$$ = new AndExpressionNode( (AndExpressionNode*) $1 , (EqualityExpressionNode*) $3 );

	}
	;

equality_expression
	: relational_expression { debugPrint("relational_expression -> equality_expression"); }
	{

		$$ = new EqualityExpressionNode( (RelationalExpressionNode*) $1 );

	}
	| equality_expression EQ_OP relational_expression { debugPrint("equality_expression EQ_OP relational_expression -> equality_expression"); }
	{

		$$ = new EqualityExpressionNode( (EqualityExpressionNode*) $1 , (RelationalExpressionNode*) $3 , EqualityExpressionNode::Equal );

	}
	| equality_expression NE_OP relational_expression { debugPrint("equality_expression NE_OP relational_expression -> equality_expression"); }
	{

		$$ = new EqualityExpressionNode( (EqualityExpressionNode*) $1 , (RelationalExpressionNode*) $3 , EqualityExpressionNode::NotEqual );

	}
	;

relational_expression
	: shift_expression { debugPrint("shift_expression -> relational_expression"); }
	{

		$$ = new RelationalExpressionNode( (ShiftExpressionNode*) $1 );

	}
	| relational_expression '<' shift_expression { debugPrint("relational_expression '<' shift_expression -> relational_expression"); }
	{

		$$ = new RelationalExpressionNode( (RelationalExpressionNode*) $1 , (ShiftExpressionNode*) $3 , RelationalExpressionNode::Less );

	}
	| relational_expression '>' shift_expression { debugPrint("relational_expression '>' shift_expression -> relational_expression"); }
	{

		$$ = new RelationalExpressionNode( (RelationalExpressionNode*) $1 , (ShiftExpressionNode*) $3 , RelationalExpressionNode::Greater );

	}
	| relational_expression LE_OP shift_expression { debugPrint("relational_expression LE_OP shift_expression -> relational_expression"); }
	{

		$$ = new RelationalExpressionNode( (RelationalExpressionNode*) $1 , (ShiftExpressionNode*) $3 , RelationalExpressionNode::LessEqual );

	}
	| relational_expression GE_OP shift_expression { debugPrint("relational_expression GE_OP shift_expression -> relational_expression"); }
	{

		$$ = new RelationalExpressionNode( (RelationalExpressionNode*) $1 , (ShiftExpressionNode*) $3 , RelationalExpressionNode::GreaterEqual );

	}
	;

shift_expression
	: additive_expression { debugPrint("additive_expression -> shift_expression"); }
	{

		$$ = new ShiftExpressionNode( (AdditiveExpressionNode*) $1 );

	}
	| shift_expression LEFT_OP additive_expression { debugPrint("shift_expression LEFT_OP additive_expression -> shift_expression"); }
	{

		$$ = new ShiftExpressionNode( (ShiftExpressionNode*) $1 , (AdditiveExpressionNode*) $3 , ShiftExpressionNode::Left );

	}
	| shift_expression RIGHT_OP additive_expression { debugPrint("shift_expression RIGHT_OP additive_expression -> shift_expression"); }
	{

		$$ = new ShiftExpressionNode( (ShiftExpressionNode*) $1 , (AdditiveExpressionNode*) $3 , ShiftExpressionNode::Left );

	}
	;

additive_expression
	: multiplicative_expression { debugPrint("multiplicative_expression -> additive_expression"); }
	{

		$$ = new AdditiveExpressionNode( (MultiplicativeExpressionNode*) $1 );

	}
	| additive_expression '+' multiplicative_expression { debugPrint("additive_expression '+' multiplicative_expression -> additive_expression"); }
	{

		$$ = new AdditiveExpressionNode( (AdditiveExpressionNode*) $1 , (MultiplicativeExpressionNode*) $3 , AdditiveExpressionNode::Add );

	}
	| additive_expression '-' multiplicative_expression { debugPrint("additive_expression '-' multiplicative_expression -> additive_expression"); }
	{

		$$ = new AdditiveExpressionNode( (AdditiveExpressionNode*) $1 , (MultiplicativeExpressionNode*) $3 , AdditiveExpressionNode::Subtract );

	}
	;

multiplicative_expression
	: cast_expression { debugPrint("cast_expression -> multiplicative_expression"); }
	{

		$$ = new MultiplicativeExpressionNode( (CastExpressionNode*) $1 );

	}
	| multiplicative_expression '*' cast_expression { debugPrint("multiplicative_expression '*' cast_expression -> multiplicative_expression"); }
	{

		$$ = new MultiplicativeExpressionNode( (MultiplicativeExpressionNode*) $1 , (CastExpressionNode*) $3 , MultiplicativeExpressionNode::Multiply );

	}
	| multiplicative_expression '/' cast_expression { debugPrint("multiplicative_expression '/' cast_expression -> multiplicative_expression"); }
	{

		$$ = new MultiplicativeExpressionNode( (MultiplicativeExpressionNode*) $1 , (CastExpressionNode*) $3 , MultiplicativeExpressionNode::Divide );

	}
	| multiplicative_expression '%' cast_expression { debugPrint("multiplicative_expression '%' cast_expression -> multiplicative_expression"); }
	{

		$$ = new MultiplicativeExpressionNode( (MultiplicativeExpressionNode*) $1 , (CastExpressionNode*) $3 , MultiplicativeExpressionNode::Modulo );

	}
	;

cast_expression
	: unary_expression { debugPrint("unary_expression -> cast_expression"); }
	{

		$$ = new CastExpressionNode( (UnaryExpressionNode*) $1 );

	}
	| '(' type_name ')' cast_expression { debugPrint("'(' type_name ')' cast_expression -> cast_expression"); }
	{

		$$ = new CastExpressionNode( (TypeNameNode*) $2 , (CastExpressionNode*) $4 );

	}
	;

unary_expression
	: postfix_expression { debugPrint("postfix_expression -> unary_expression"); }
	{

		$$ = new UnaryExpressionNode( (PostfixExpressionNode*) $1 );	

	}
	| INC_OP unary_expression { debugPrint("INC_OP unary_expression -> unary_expression"); }
	{

		$$ = new UnaryExpressionNode( (UnaryExpressionNode*) $2 , UnaryExpressionNode::Increment );

	}
	| DEC_OP unary_expression { debugPrint("DEC_OP unary_expression -> unary_expression"); }
	{

		$$ = new UnaryExpressionNode( (UnaryExpressionNode*) $2 , UnaryExpressionNode::Decrement );

	}
	| unary_operator cast_expression { debugPrint("unary_operator cast_expression -> unary_expression"); }
	{

		$$ = new UnaryExpressionNode( (UnaryOperatorNode*) $1 , (CastExpressionNode*) $2 );

	}
	| SIZEOF unary_expression { debugPrint("SIZEOF unary_expression -> unary_expression"); }
	{

		$$ = new UnaryExpressionNode( (UnaryExpressionNode*) $1 , UnaryExpressionNode::SizeofExpression );

	}
	| SIZEOF '(' type_name ')' { debugPrint("SIZEOF '(' type_name ')' -> unary_expression"); }
	{

		$$ = new UnaryExpressionNode( (TypeNameNode*) $1  );

	}
	;

unary_operator
	: '&' { debugPrint("'&' -> unary_operator"); }
	{

		$$ = new UnaryOperatorNode( UnaryOperatorNode::Address );

	}
	| '*' { debugPrint("'*' -> unary_operator"); }
	{

		$$ = new UnaryOperatorNode( UnaryOperatorNode::Indirection );

	}
	| '+' { debugPrint("'+' -> unary_operator"); }
	{

		$$ = new UnaryOperatorNode( UnaryOperatorNode::Positive );

	}
	| '-' { debugPrint("'-' -> unary_operator"); }
	{

		$$ = new UnaryOperatorNode( UnaryOperatorNode::Negative );

	}
	| '~' { debugPrint("'~' -> unary_operator"); }
	{

		$$ = new UnaryOperatorNode( UnaryOperatorNode::BitwiseNot );

	}
	| '!' { debugPrint("'!' -> unary_operator"); }
	{

		$$ = new UnaryOperatorNode( UnaryOperatorNode::Address );

	}
	;

postfix_expression
	: primary_expression { debugPrint("primary_expression -> postfix_expression"); }
	{
	
		$$ = new PostfixExpressionNode( (PrimaryExpressionNode*) $1 );

	}
	| postfix_expression '[' expression ']' { debugPrint("postfix_expression '[' expression ']' -> postfix_expression"); }
	{

		$$ = new PostfixExpressionNode( (PostfixExpressionNode*) $1 , (ExpressionNode*) $3 );

	}
	| postfix_expression '(' ')' { debugPrint("postfix_expression '(' ')' -> postfix_expression"); }
	{

		$$ = new PostfixExpressionNode( (PostfixExpressionNode*) $1 , PostfixExpressionNode::FunctionCall );

	}
	| postfix_expression '(' argument_expression_list ')' { debugPrint("postfix_expression '(' argument_expression_list ')' -> postfix_expression"); }
	{

		$$ = new PostfixExpressionNode( (PostfixExpressionNode*) $1 , (ArgExpressionListNode*) $3 );

	}
	| postfix_expression '.' identifier { debugPrint("postfix_expression '.' identifier -> postfix_expression"); }
	{

		$$ = new PostfixExpressionNode( (PostfixExpressionNode*) $1 , (IdentifierNode*) $3 , PostfixExpressionNode::DirectMemberAccess );

	}
	| postfix_expression PTR_OP identifier { debugPrint("postfix_expression PTR_OP identifier -> postfix_expression"); }
	{

		$$ = new PostfixExpressionNode( (PostfixExpressionNode*) $1 , (IdentifierNode*) $3 , PostfixExpressionNode::PointerMemberAccess );

	}
	| postfix_expression INC_OP { debugPrint("postfix_expression INC_OP -> postfix_expression"); }
	{

		$$ = new PostfixExpressionNode( (PostfixExpressionNode*) $1 , PostfixExpressionNode::Increment );

	}
	| postfix_expression DEC_OP { debugPrint("postfix_expression DEC_OP -> postfix_expression"); }
	{

		$$ = new PostfixExpressionNode( (PostfixExpressionNode*) $1 , PostfixExpressionNode::Decrement );

	}
	;

primary_expression
	: identifier { 
		$$ = new PrimaryExpressionNode( (IdentifierNode*) $1 );
		}
	| constant { 
		$$ = new PrimaryExpressionNode( (ConstantNode*) $1 );
		
		debugPrint("constant -> primary_expression"); 
		}
	| string { debugPrint("string -> primary_expression"); }
	{
	
		$$ = new PrimaryExpressionNode( (StringNode*) $1 );
	
	}
	| '(' expression ')' { debugPrint("'(' expression ')' -> primary_expression"); } 
	{
	
		$$ = new PrimaryExpressionNode( (ExpressionNode*) $2 );
	
	}
	;

argument_expression_list
	: assignment_expression { debugPrint("assignment_expression -> argument_expression_list"); }
	{
	
		$$ = new ArgExpressionListNode( (AssignmentExpressionNode*) $1 );
	
	}
	| argument_expression_list ',' assignment_expression { debugPrint("argument_expression_list ',' assignment_expression -> argument_expression_list"); }
	{
	
		$$ = new ArgExpressionListNode( (ArgExpressionListNode*) $3 , (AssignmentExpressionNode*) $1 );
	
	}
	;

constant
	: I_CONSTANT /* includes character_constant */ { 
			// Create expression which will propagate up the grammar
			// Type should not be made here but data of a symbol is held within type currently...

			// Convert the string integer constant to integer
			std::string match = scanner->matched();
			long long i = atoi( match.c_str() );
			
			$$ = new ConstantNode( new IntegerConstantNode( i ) );

			debugPrint("I_CONSTANT -> constant"); 
		}
	| F_CONSTANT { 
			// TODO should this be float or double ? atof returns double
			std::string match = scanner->matched();
			double f = atof( match.c_str() );
			
			$$ = new ConstantNode( new FloatConstantNode( f ) );

			debugPrint("F_CONSTANT -> constant"); 
		}
	| CHAR_LITERAL { 
			std::string match = scanner->matched();
			char c = ( match.c_str() )[0];

			$$ = new ConstantNode( new CharConstantNode( c ) );
		
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
	
	$$ = new StringNode( scanner->matched() );
	
	}
	;

identifier
	: IDENTIFIER { debugPrint("IDENTIFIER -> identifier"); }
	{

	if( isDeclarationMode() )
	{
		//setDeclarationLocation();
		pushIdentifier();
	}
	else
	{
	
		$$ =  new IdentifierNode( scanner->matched() );
	
	}

	}
	;

