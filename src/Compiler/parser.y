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

%token <CHAR> CHAR_LITERAL

%token <STRING> IDENTIFIER
%token <INT> I_CONSTANT
%token <FLOAT> F_CONSTANT
%token <STRING> STRING_LITERAL
%token TYPEDEF_NAME
%token ENUMERATION_CONSTANT

%token COMMENT

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

%polymorphic INT: int; FLOAT: float; DOUBLE: double; STRING: std::string; CHAR: char;

%type <STRING> identifier
%type <STRING> string

%lsp-needed
%debug

%%

translation_unit
	: external_declaration { debugPrint("external_declaration -> translation_unit"); }
	| translation_unit external_declaration { debugPrint("translation_unit external_declaration -> translation_unit"); }
	;

external_declaration
	: function_definition { debugPrint("function_definition -> external_declaration"); }
	| declaration { debugPrint("declaration -> external_declaration"); }
	;

function_definition
	: declarator compound_statement { debugPrint("declarator compound_statement -> function_definition"); }
	| declarator declaration_list compound_statement { debugPrint("declarator declaration_list compound_statement -> function_definition"); }
	| declaration_specifiers declarator compound_statement { debugPrint("declaration_specifiers declarator compound_statement -> function_definition"); }
	| declaration_specifiers declarator declaration_list compound_statement { debugPrint("declaration_specifiers declarator declaration_list compound_statement -> function_definition"); }
	;

declaration
	: declaration_specifiers ';' { debugPrint("declaration_specifiers ';' -> declaration"); }
	| declaration_specifiers init_declarator_list ';' { debugPrint("declaration_specifiers init_declarator_list ';' -> declaration"); }
	;

declaration_list
	: declaration { debugPrint("declaration -> declaration_list"); }
	| declaration_list declaration { debugPrint("declaration_list declaration -> declaration_list"); }
	;

declaration_specifiers
	: storage_class_specifier { debugPrint("storage_class_specifier -> declaration_specifiers"); }
	| storage_class_specifier declaration_specifiers { debugPrint("storage_class_specifier declaration_specifiers -> declaration_specifiers"); }
	| type_specifier { debugPrint("type_specifier -> declaration_specifiers"); }
	| type_specifier declaration_specifiers { debugPrint("type_specifier declaration_specifiers -> declaration_specifiers"); }
	| type_qualifier  { debugPrint("type_qualifier  -> declaration_specifiers"); }
	| type_qualifier declaration_specifiers { debugPrint("type_qualifier declaration_specifiers -> declaration_specifiers"); }
	;

storage_class_specifier
	: AUTO { debugPrint("AUTO -> storage_class_specifier"); }
	| REGISTER { debugPrint("REGISTER -> storage_class_specifier"); }
	| STATIC { debugPrint("STATIC -> storage_class_specifier"); }
	| EXTERN { debugPrint("EXTERN -> storage_class_specifier"); }
	| TYPEDEF { debugPrint("TYPEDEF -> storage_class_specifier"); }
	;

type_specifier
	: VOID { debugPrint("VOID -> type_specifier"); }
	| CHAR { debugPrint("CHAR -> type_specifier"); }
	| SHORT { debugPrint("SHORT -> type_specifier"); }
	| INT { debugPrint("INT -> type_specifier"); }
	| LONG { debugPrint("LONG -> type_specifier"); }
	| FLOAT  { debugPrint("FLOAT  -> type_specifier"); }
	| DOUBLE { debugPrint("DOUBLE -> type_specifier"); }
	| SIGNED { debugPrint("SIGNED -> type_specifier"); }
	| UNSIGNED { debugPrint("UNSIGNED -> type_specifier"); }
	| struct_or_union_specifier { debugPrint("struct_or_union_specifier -> type_specifier"); }
	| enum_specifier { debugPrint("enum_specifier -> type_specifier"); }
	| TYPEDEF_NAME { debugPrint("TYPEDEF_NAME -> type_specifier"); }
	;

type_qualifier
	: CONST { debugPrint("CONST -> type_qualifier"); }
	| VOLATILE { debugPrint("VOLATILE -> type_qualifier"); }
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
	| declarator '=' initializer { debugPrint("declarator '=' initializer -> init_declarator"); }
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
	: identifier { debugPrint("identifier -> direct_declarator"); }
	| '(' declarator ')' { debugPrint("'(' declarator ')' -> direct_declarator"); }
	| direct_declarator '[' ']' { debugPrint("direct_declarator '[' ']' -> direct_declarator"); }
	| direct_declarator '[' constant_expression ']' { debugPrint("direct_declarator '[' constant_expression ']' -> direct_declarator"); }
	| direct_declarator '(' ')' { debugPrint("direct_declarator '(' ')' -> direct_declarator"); }
	| direct_declarator '(' parameter_type_list ')' { debugPrint("direct_declarator '(' parameter_type_list ')' -> direct_declarator"); }
	| direct_declarator '(' identifier_list ')' { debugPrint("direct_declarator '(' identifier_list ')' -> direct_declarator"); }
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
	| '{' initializer_list '}' { debugPrint("'{' initializer_list '}' -> initializer"); }
	| '{' initializer_list ',' '}' { debugPrint("'{' initializer_list ',' '}' -> initializer"); }
	;

initializer_list
	: initializer { debugPrint("initializer -> initializer_list"); }
	| initializer_list ',' initializer { debugPrint("initializer_list ',' initializer -> initializer_list"); }
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
	: '{' '}' { debugPrint("'{' '}' -> compound_statement"); }
	| '{' { /* declaration mode*/ } statement_list '}' { debugPrint("'{' statement_list '}' -> compound_statement"); }
	| '{' declaration_list '}' { debugPrint("'{' declaration_list '}' -> compound_statement"); }
	| '{' declaration_list statement_list '}' { debugPrint("'{' declaration_list statement_list '}' -> compound_statement"); }
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
	| logical_or_expression OR_OP logical_and_expression { debugPrint("logical_or_expression OR_OP logical_and_expression -> logical_or_expression"); }
	;

logical_and_expression
	: inclusive_or_expression { debugPrint("inclusive_or_expression -> logical_and_expression"); }
	| logical_and_expression AND_OP inclusive_or_expression { debugPrint("logical_and_expression AND_OP inclusive_or_expression -> logical_and_expression"); }
	;

inclusive_or_expression
	: exclusive_or_expression { debugPrint("exclusive_or_expression -> inclusive_or_expression"); }
	| inclusive_or_expression '|' exclusive_or_expression { debugPrint("inclusive_or_expression '|' exclusive_or_expression -> inclusive_or_expression"); }
	;

exclusive_or_expression
	: and_expression { debugPrint("and_expression -> exclusive_or_expression"); }
	| exclusive_or_expression '^' and_expression { debugPrint("exclusive_or_expression '^' and_expression -> exclusive_or_expression"); }
	;

and_expression
	: equality_expression { debugPrint("equality_expression -> and_expression"); }
	| and_expression '&' equality_expression { debugPrint("and_expression '&' equality_expression -> and_expression"); }
	;

equality_expression
	: relational_expression { debugPrint("relational_expression -> equality_expression"); }
	| equality_expression EQ_OP relational_expression { debugPrint("equality_expression EQ_OP relational_expression -> equality_expression"); }
	| equality_expression NE_OP relational_expression { debugPrint("equality_expression NE_OP relational_expression -> equality_expression"); }
	;

relational_expression
	: shift_expression { debugPrint("shift_expression -> relational_expression"); }
	| relational_expression '<' shift_expression { debugPrint("relational_expression '<' shift_expression -> relational_expression"); }
	| relational_expression '>' shift_expression { debugPrint("relational_expression '>' shift_expression -> relational_expression"); }
	| relational_expression LE_OP shift_expression { debugPrint("relational_expression LE_OP shift_expression -> relational_expression"); }
	| relational_expression GE_OP shift_expression { debugPrint("relational_expression GE_OP shift_expression -> relational_expression"); }
	;

shift_expression
	: additive_expression { debugPrint("additive_expression -> shift_expression"); }
	| shift_expression LEFT_OP additive_expression { debugPrint("shift_expression LEFT_OP additive_expression -> shift_expression"); }
	| shift_expression RIGHT_OP additive_expression { debugPrint("shift_expression RIGHT_OP additive_expression -> shift_expression"); }
	;

additive_expression
	: multiplicative_expression { debugPrint("multiplicative_expression -> additive_expression"); }
	| additive_expression '+' multiplicative_expression { debugPrint("additive_expression '+' multiplicative_expression -> additive_expression"); }
	| additive_expression '-' multiplicative_expression { debugPrint("additive_expression '-' multiplicative_expression -> additive_expression"); }
	;

multiplicative_expression
	: cast_expression { debugPrint("cast_expression -> multiplicative_expression"); }
	| multiplicative_expression '*' cast_expression { debugPrint("multiplicative_expression '*' cast_expression -> multiplicative_expression"); }
	| multiplicative_expression '/' cast_expression { debugPrint("multiplicative_expression '/' cast_expression -> multiplicative_expression"); }
	| multiplicative_expression '%' cast_expression { debugPrint("multiplicative_expression '%' cast_expression -> multiplicative_expression"); }
	;

cast_expression
	: unary_expression { debugPrint("unary_expression -> cast_expression"); }
	| '(' type_name ')' cast_expression { debugPrint("'(' type_name ')' cast_expression -> cast_expression"); }
	;

unary_expression
	: postfix_expression { debugPrint("postfix_expression -> unary_expression"); }
	| INC_OP unary_expression { debugPrint("INC_OP unary_expression -> unary_expression"); }
	| DEC_OP unary_expression { debugPrint("DEC_OP unary_expression -> unary_expression"); }
	| unary_operator cast_expression { debugPrint("unary_operator cast_expression -> unary_expression"); }
	| SIZEOF unary_expression { debugPrint("SIZEOF unary_expression -> unary_expression"); }
	| SIZEOF '(' type_name ')' { debugPrint("SIZEOF '(' type_name ')' -> unary_expression"); }
	;

unary_operator
	: '&' { debugPrint("'&' -> unary_operator"); }
	| '*' { debugPrint("'*' -> unary_operator"); }
	| '+' { debugPrint("'+' -> unary_operator"); }
	| '-' { debugPrint("'-' -> unary_operator"); }
	| '~' { debugPrint("'~' -> unary_operator"); }
	| '!' { debugPrint("'!' -> unary_operator"); }
	;

postfix_expression
	: primary_expression { debugPrint("primary_expression -> postfix_expression"); }
	| postfix_expression '[' expression ']' { debugPrint("postfix_expression '[' expression ']' -> postfix_expression"); }
	| postfix_expression '(' ')' { debugPrint("postfix_expression '(' ')' -> postfix_expression"); }
	| postfix_expression '(' argument_expression_list ')' { debugPrint("postfix_expression '(' argument_expression_list ')' -> postfix_expression"); }
	| postfix_expression '.' identifier { debugPrint("postfix_expression '.' identifier -> postfix_expression"); }
	| postfix_expression PTR_OP identifier { debugPrint("postfix_expression PTR_OP identifier -> postfix_expression"); }
	| postfix_expression INC_OP { debugPrint("postfix_expression INC_OP -> postfix_expression"); }
	| postfix_expression DEC_OP { debugPrint("postfix_expression DEC_OP -> postfix_expression"); }
	;

primary_expression
	: identifier { debugPrint("identifier -> primary_expression"); }
	| constant { debugPrint("constant -> primary_expression"); }
	| string { debugPrint("string -> primary_expression"); }
	| '(' expression ')' { debugPrint("'(' expression ')' -> primary_expression"); }
	;

argument_expression_list
	: assignment_expression { debugPrint("assignment_expression -> argument_expression_list"); }
	| argument_expression_list ',' assignment_expression { debugPrint("argument_expression_list ',' assignment_expression -> argument_expression_list"); }
	;

constant
	: I_CONSTANT		/* includes character_constant */ { debugPrint("I_CONSTANT -> constant"); }
	| F_CONSTANT { debugPrint("F_CONSTANT -> constant"); }
	| CHAR_LITERAL { debugPrint("CHAR_LITERAL -> constant"); }
	| ENUMERATION_CONSTANT	/* after it has been defined as such */ { debugPrint("ENUMERATION_CONSTANT -> constant"); }
	;

string
	: STRING_LITERAL { debugPrint("STRING_LITERAL -> string"); }
	;

identifier
	: IDENTIFIER { debugPrint("IDENTIFIER -> identifier"); }
	{
	$$ = scanner->matched();
	}
	;

