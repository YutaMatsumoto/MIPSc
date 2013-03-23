%token <CHAR> CHAR_LITERAL

%token <STRING> IDENTIFIER
%token <INT> I_CONSTANT
%token <FLOAT> F_CONSTANT
%token <STRING> STRING_LITERAL
%token TYPEDEF_NAME
%token ENUMERATION_CONSTANT

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
	: external_declaration { std::cout << "Reduction: external_declaration -> translation_unit" << std::endl << std::endl; }
	| translation_unit external_declaration { std::cout << "Reduction: translation_unit external_declaration -> translation_unit" << std::endl << std::endl; }
	;

external_declaration
	: function_definition { std::cout << "Reduction: function_definition -> external_declaration" << std::endl << std::endl; }
	| declaration { std::cout << "Reduction: declaration -> external_declaration" << std::endl << std::endl; }
	;

function_definition
	: declarator compound_statement { std::cout << "Reduction: declarator compound_statement -> function_definition" << std::endl << std::endl; }
	| declarator declaration_list compound_statement { std::cout << "Reduction: declarator declaration_list compound_statement -> function_definition" << std::endl << std::endl; }
	| declaration_specifiers declarator compound_statement { std::cout << "Reduction: declaration_specifiers declarator compound_statement -> function_definition" << std::endl << std::endl; }
	| declaration_specifiers declarator declaration_list compound_statement { std::cout << "Reduction: declaration_specifiers declarator declaration_list compound_statement -> function_definition" << std::endl << std::endl; }
	;

declaration
	: declaration_specifiers ';' { std::cout << "Reduction: declaration_specifiers ';' -> declaration" << std::endl << std::endl; }
	| declaration_specifiers init_declarator_list ';' { std::cout << "Reduction: declaration_specifiers init_declarator_list ';' -> declaration" << std::endl << std::endl; }
	;

declaration_list
	: declaration { std::cout << "Reduction: declaration -> declaration_list" << std::endl << std::endl; }
	| declaration_list declaration { std::cout << "Reduction: declaration_list declaration -> declaration_list" << std::endl << std::endl; }
	;

declaration_specifiers
	: storage_class_specifier { std::cout << "Reduction: storage_class_specifier -> declaration_specifiers" << std::endl << std::endl; }
	| storage_class_specifier declaration_specifiers { std::cout << "Reduction: storage_class_specifier declaration_specifiers -> declaration_specifiers" << std::endl << std::endl; }
	| type_specifier { std::cout << "Reduction: type_specifier -> declaration_specifiers" << std::endl << std::endl; }
	| type_specifier declaration_specifiers { std::cout << "Reduction: type_specifier declaration_specifiers -> declaration_specifiers" << std::endl << std::endl; }
	| type_qualifier  { std::cout << "Reduction: type_qualifier  -> declaration_specifiers" << std::endl << std::endl; }
	| type_qualifier declaration_specifiers { std::cout << "Reduction: type_qualifier declaration_specifiers -> declaration_specifiers" << std::endl << std::endl; }
	;

storage_class_specifier
	: AUTO { std::cout << "Reduction: AUTO -> storage_class_specifier" << std::endl << std::endl; }
	| REGISTER { std::cout << "Reduction: REGISTER -> storage_class_specifier" << std::endl << std::endl; }
	| STATIC { std::cout << "Reduction: STATIC -> storage_class_specifier" << std::endl << std::endl; }
	| EXTERN { std::cout << "Reduction: EXTERN -> storage_class_specifier" << std::endl << std::endl; }
	| TYPEDEF { std::cout << "Reduction: TYPEDEF -> storage_class_specifier" << std::endl << std::endl; }
	;

type_specifier
	: VOID { std::cout << "Reduction: VOID -> type_specifier" << std::endl << std::endl; }
	| CHAR { std::cout << "Reduction: CHAR -> type_specifier" << std::endl << std::endl; }
	| SHORT { std::cout << "Reduction: SHORT -> type_specifier" << std::endl << std::endl; }
	| INT { std::cout << "Reduction: INT -> type_specifier" << std::endl << std::endl; }
	| LONG { std::cout << "Reduction: LONG -> type_specifier" << std::endl << std::endl; }
	| FLOAT  { std::cout << "Reduction: FLOAT  -> type_specifier" << std::endl << std::endl; }
	| DOUBLE { std::cout << "Reduction: DOUBLE -> type_specifier" << std::endl << std::endl; }
	| SIGNED { std::cout << "Reduction: SIGNED -> type_specifier" << std::endl << std::endl; }
	| UNSIGNED { std::cout << "Reduction: UNSIGNED -> type_specifier" << std::endl << std::endl; }
	| struct_or_union_specifier { std::cout << "Reduction: struct_or_union_specifier -> type_specifier" << std::endl << std::endl; }
	| enum_specifier { std::cout << "Reduction: enum_specifier -> type_specifier" << std::endl << std::endl; }
	| TYPEDEF_NAME { std::cout << "Reduction: TYPEDEF_NAME -> type_specifier" << std::endl << std::endl; }
	;

type_qualifier
	: CONST { std::cout << "Reduction: CONST -> type_qualifier" << std::endl << std::endl; }
	| VOLATILE { std::cout << "Reduction: VOLATILE -> type_qualifier" << std::endl << std::endl; }
	;

struct_or_union_specifier
	: struct_or_union identifier '{' struct_declaration_list '}' { std::cout << "Reduction: struct_or_union identifier '{' struct_declaration_list '}' -> struct_or_union_specifier" << std::endl << std::endl; }
	| struct_or_union '{' struct_declaration_list '}' { std::cout << "Reduction: struct_or_union '{' struct_declaration_list '}' -> struct_or_union_specifier" << std::endl << std::endl; }
	| struct_or_union identifier { std::cout << "Reduction: struct_or_union identifier -> struct_or_union_specifier" << std::endl << std::endl; }
	;

struct_or_union
	: STRUCT { std::cout << "Reduction: STRUCT -> struct_or_union" << std::endl << std::endl; }
	| UNION { std::cout << "Reduction: UNION -> struct_or_union" << std::endl << std::endl; }
	;

struct_declaration_list
	: struct_declaration { std::cout << "Reduction: struct_declaration -> struct_declaration_list" << std::endl << std::endl; }
	| struct_declaration_list struct_declaration { std::cout << "Reduction: struct_declaration_list struct_declaration -> struct_declaration_list" << std::endl << std::endl; }
	;

init_declarator_list
	: init_declarator { std::cout << "Reduction: init_declarator -> init_declarator_list" << std::endl << std::endl; }
	| init_declarator_list ',' init_declarator { std::cout << "Reduction: init_declarator_list ',' init_declarator -> init_declarator_list" << std::endl << std::endl; }
	;

init_declarator
	: declarator { std::cout << "Reduction: declarator -> init_declarator" << std::endl << std::endl; }
	| declarator '=' initializer { std::cout << "Reduction: declarator '=' initializer -> init_declarator" << std::endl << std::endl; }
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';' { std::cout << "Reduction: specifier_qualifier_list struct_declarator_list ';' -> struct_declaration" << std::endl << std::endl; }
	;

specifier_qualifier_list
	: type_specifier { std::cout << "Reduction: type_specifier -> specifier_qualifier_list" << std::endl << std::endl; }
	| type_specifier specifier_qualifier_list { std::cout << "Reduction: type_specifier specifier_qualifier_list -> specifier_qualifier_list" << std::endl << std::endl; }
	| type_qualifier { std::cout << "Reduction: type_qualifier -> specifier_qualifier_list" << std::endl << std::endl; }
	| type_qualifier specifier_qualifier_list { std::cout << "Reduction: type_qualifier specifier_qualifier_list -> specifier_qualifier_list" << std::endl << std::endl; }
	;

struct_declarator_list
	: struct_declarator { std::cout << "Reduction: struct_declarator -> struct_declarator_list" << std::endl << std::endl; }
	| struct_declarator_list ',' struct_declarator { std::cout << "Reduction: struct_declarator_list ',' struct_declarator -> struct_declarator_list" << std::endl << std::endl; }
	;

struct_declarator
	: declarator { std::cout << "Reduction: declarator -> struct_declarator" << std::endl << std::endl; }
	| ':' constant_expression { std::cout << "Reduction: ':' constant_expression -> struct_declarator" << std::endl << std::endl; }
	| declarator ':' constant_expression { std::cout << "Reduction: declarator ':' constant_expression -> struct_declarator" << std::endl << std::endl; }
	;

enum_specifier
	: ENUM '{' enumerator_list '}' { std::cout << "Reduction: ENUM '{' enumerator_list '}' -> enum_specifier" << std::endl << std::endl; }
	| ENUM identifier '{' enumerator_list '}' { std::cout << "Reduction: ENUM identifier '{' enumerator_list '}' -> enum_specifier" << std::endl << std::endl; }
	| ENUM identifier { std::cout << "Reduction: ENUM identifier -> enum_specifier" << std::endl << std::endl; }
	;

enumerator_list
	: enumerator { std::cout << "Reduction: enumerator -> enumerator_list" << std::endl << std::endl; }
	| enumerator_list ',' enumerator { std::cout << "Reduction: enumerator_list ',' enumerator -> enumerator_list" << std::endl << std::endl; }
	;

enumerator
	: identifier { std::cout << "Reduction: identifier -> enumerator" << std::endl << std::endl; }
	| identifier '=' constant_expression { std::cout << "Reduction: identifier '=' constant_expression -> enumerator" << std::endl << std::endl; }
	;

declarator
	: direct_declarator { std::cout << "Reduction: direct_declarator -> declarator" << std::endl << std::endl; }
	| pointer direct_declarator { std::cout << "Reduction: pointer direct_declarator -> declarator" << std::endl << std::endl; }
	;

direct_declarator
	: identifier { std::cout << "Reduction: identifier -> direct_declarator" << std::endl << std::endl; }
	| '(' declarator ')' { std::cout << "Reduction: '(' declarator ')' -> direct_declarator" << std::endl << std::endl; }
	| direct_declarator '[' ']' { std::cout << "Reduction: direct_declarator '[' ']' -> direct_declarator" << std::endl << std::endl; }
	| direct_declarator '[' constant_expression ']' { std::cout << "Reduction: direct_declarator '[' constant_expression ']' -> direct_declarator" << std::endl << std::endl; }
	| direct_declarator '(' ')' { std::cout << "Reduction: direct_declarator '(' ')' -> direct_declarator" << std::endl << std::endl; }
	| direct_declarator '(' parameter_type_list ')' { std::cout << "Reduction: direct_declarator '(' parameter_type_list ')' -> direct_declarator" << std::endl << std::endl; }
	| direct_declarator '(' identifier_list ')' { std::cout << "Reduction: direct_declarator '(' identifier_list ')' -> direct_declarator" << std::endl << std::endl; }
	;

pointer
	: '*' { std::cout << "Reduction: '*' -> pointer" << std::endl << std::endl; }
	| '*' type_qualifier_list { std::cout << "Reduction: '*' type_qualifier_list -> pointer" << std::endl << std::endl; }
	| '*' pointer { std::cout << "Reduction: '*' pointer -> pointer" << std::endl << std::endl; }
	| '*' type_qualifier_list pointer { std::cout << "Reduction: '*' type_qualifier_list pointer -> pointer" << std::endl << std::endl; }
	;

type_qualifier_list
	: type_qualifier { std::cout << "Reduction: type_qualifier -> type_qualifier_list" << std::endl << std::endl; }
	| type_qualifier_list type_qualifier { std::cout << "Reduction: type_qualifier_list type_qualifier -> type_qualifier_list" << std::endl << std::endl; }
	;

parameter_type_list
	: parameter_list { std::cout << "Reduction: parameter_list -> parameter_type_list" << std::endl << std::endl; }
	| parameter_list ',' ELLIPSIS { std::cout << "Reduction: parameter_list ',' ELLIPSIS -> parameter_type_list" << std::endl << std::endl; }
	;

parameter_list
	: parameter_declaration { std::cout << "Reduction: parameter_declaration -> parameter_list" << std::endl << std::endl; }
	| parameter_list ',' parameter_declaration { std::cout << "Reduction: parameter_list ',' parameter_declaration -> parameter_list" << std::endl << std::endl; }
	;

parameter_declaration
	: declaration_specifiers declarator { std::cout << "Reduction: declaration_specifiers declarator -> parameter_declaration" << std::endl << std::endl; }
	| declaration_specifiers { std::cout << "Reduction: declaration_specifiers -> parameter_declaration" << std::endl << std::endl; }
	| declaration_specifiers abstract_declarator { std::cout << "Reduction: declaration_specifiers abstract_declarator -> parameter_declaration" << std::endl << std::endl; }
	;

identifier_list
	: identifier { std::cout << "Reduction: identifier -> identifier_list" << std::endl << std::endl; }
	| identifier_list ',' identifier { std::cout << "Reduction: identifier_list ',' identifier -> identifier_list" << std::endl << std::endl; }
	;

initializer
	: assignment_expression { std::cout << "Reduction: assignment_expression -> initializer" << std::endl << std::endl; }
	| '{' initializer_list '}' { std::cout << "Reduction: '{' initializer_list '}' -> initializer" << std::endl << std::endl; }
	| '{' initializer_list ',' '}' { std::cout << "Reduction: '{' initializer_list ',' '}' -> initializer" << std::endl << std::endl; }
	;

initializer_list
	: initializer { std::cout << "Reduction: initializer -> initializer_list" << std::endl << std::endl; }
	| initializer_list ',' initializer { std::cout << "Reduction: initializer_list ',' initializer -> initializer_list" << std::endl << std::endl; }
	;

type_name
	: specifier_qualifier_list { std::cout << "Reduction: specifier_qualifier_list -> type_name" << std::endl << std::endl; }
	| specifier_qualifier_list abstract_declarator { std::cout << "Reduction: specifier_qualifier_list abstract_declarator -> type_name" << std::endl << std::endl; }
	;

abstract_declarator
	: pointer { std::cout << "Reduction: pointer -> abstract_declarator" << std::endl << std::endl; }
	| direct_abstract_declarator { std::cout << "Reduction: direct_abstract_declarator -> abstract_declarator" << std::endl << std::endl; }
	| pointer direct_abstract_declarator { std::cout << "Reduction: pointer direct_abstract_declarator -> abstract_declarator" << std::endl << std::endl; }
	;

direct_abstract_declarator
	: '(' abstract_declarator ')' { std::cout << "Reduction: '(' abstract_declarator ')' -> direct_abstract_declarator" << std::endl << std::endl; }
	| '[' ']' { std::cout << "Reduction: '[' ']' -> direct_abstract_declarator" << std::endl << std::endl; }
	| '[' constant_expression ']' { std::cout << "Reduction: '[' constant_expression ']' -> direct_abstract_declarator" << std::endl << std::endl; }
	| direct_abstract_declarator '[' ']' { std::cout << "Reduction: direct_abstract_declarator '[' ']' -> direct_abstract_declarator" << std::endl << std::endl; }
	| direct_abstract_declarator '[' constant_expression ']' { std::cout << "Reduction: direct_abstract_declarator '[' constant_expression ']' -> direct_abstract_declarator" << std::endl << std::endl; }
	| '(' ')' { std::cout << "Reduction: '(' ')' -> direct_abstract_declarator" << std::endl << std::endl; }
	| '(' parameter_type_list ')' { std::cout << "Reduction: '(' parameter_type_list ')' -> direct_abstract_declarator" << std::endl << std::endl; }
	| direct_abstract_declarator '(' ')' { std::cout << "Reduction: direct_abstract_declarator '(' ')' -> direct_abstract_declarator" << std::endl << std::endl; }
	| direct_abstract_declarator '(' parameter_type_list ')' { std::cout << "Reduction: direct_abstract_declarator '(' parameter_type_list ')' -> direct_abstract_declarator" << std::endl << std::endl; }
	;

statement
	: labeled_statement { std::cout << "Reduction: labeled_statement -> statement" << std::endl << std::endl; }
	| compound_statement { std::cout << "Reduction: compound_statement -> statement" << std::endl << std::endl; }
	| expression_statement { std::cout << "Reduction: expression_statement -> statement" << std::endl << std::endl; }
	| selection_statement { std::cout << "Reduction: selection_statement -> statement" << std::endl << std::endl; }
	| iteration_statement { std::cout << "Reduction: iteration_statement -> statement" << std::endl << std::endl; }
	| jump_statement { std::cout << "Reduction: jump_statement -> statement" << std::endl << std::endl; }
	;

labeled_statement
	: identifier ':' statement { std::cout << "Reduction: identifier ':' statement -> labeled_statement" << std::endl << std::endl; }
	| CASE constant_expression ':' statement { std::cout << "Reduction: CASE constant_expression ':' statement -> labeled_statement" << std::endl << std::endl; }
	| DEFAULT ':' statement { std::cout << "Reduction: DEFAULT ':' statement -> labeled_statement" << std::endl << std::endl; }
	;

expression_statement
	: ';' { std::cout << "Reduction: ';' -> expression_statement" << std::endl << std::endl; }
	| expression ';' { std::cout << "Reduction: expression ';' -> expression_statement" << std::endl << std::endl; }
	;

compound_statement
	: '{' '}' { std::cout << "Reduction: '{' '}' -> compound_statement" << std::endl << std::endl; }
	| '{' { /* declaration mode*/ } statement_list '}' { std::cout << "Reduction: '{' statement_list '}' -> compound_statement" << std::endl << std::endl; }
	| '{' declaration_list '}' { std::cout << "Reduction: '{' declaration_list '}' -> compound_statement" << std::endl << std::endl; }
	| '{' declaration_list statement_list '}' { std::cout << "Reduction: '{' declaration_list statement_list '}' -> compound_statement" << std::endl << std::endl; }
	;

statement_list
	: statement { std::cout << "Reduction: statement -> statement_list" << std::endl << std::endl; }
	| statement_list statement { std::cout << "Reduction: statement_list statement -> statement_list" << std::endl << std::endl; }
	;

selection_statement
	: IF '(' expression ')' statement { std::cout << "Reduction: IF '(' expression ')' statement -> selection_statement" << std::endl << std::endl; }
	| IF '(' expression ')' statement ELSE statement { std::cout << "Reduction: IF '(' expression ')' statement ELSE statement -> selection_statement" << std::endl << std::endl; }
	| SWITCH '(' expression ')' statement { std::cout << "Reduction: SWITCH '(' expression ')' statement -> selection_statement" << std::endl << std::endl; }
	;

iteration_statement
	: WHILE '(' expression ')' statement { std::cout << "Reduction: WHILE '(' expression ')' statement -> iteration_statement" << std::endl << std::endl; }
	| DO statement WHILE '(' expression ')' ';' { std::cout << "Reduction: DO statement WHILE '(' expression ')' ';' -> iteration_statement" << std::endl << std::endl; }
	| FOR '(' ';' ';' ')' statement { std::cout << "Reduction: FOR '(' ';' ';' ')' statement -> iteration_statement" << std::endl << std::endl; }
	| FOR '(' ';' ';' expression ')' statement { std::cout << "Reduction: FOR '(' ';' ';' expression ')' statement -> iteration_statement" << std::endl << std::endl; }
	| FOR '(' ';' expression ';' ')' statement { std::cout << "Reduction: FOR '(' ';' expression ';' ')' statement -> iteration_statement" << std::endl << std::endl; }
	| FOR '(' ';' expression ';' expression ')' statement { std::cout << "Reduction: FOR '(' ';' expression ';' expression ')' statement -> iteration_statement" << std::endl << std::endl; }
	| FOR '(' expression ';' ';' ')' statement { std::cout << "Reduction: FOR '(' expression ';' ';' ')' statement -> iteration_statement" << std::endl << std::endl; }
	| FOR '(' expression ';' ';' expression ')' statement { std::cout << "Reduction: FOR '(' expression ';' ';' expression ')' statement -> iteration_statement" << std::endl << std::endl; }
	| FOR '(' expression ';' expression ';' ')' statement { std::cout << "Reduction: FOR '(' expression ';' expression ';' ')' statement -> iteration_statement" << std::endl << std::endl; }
	| FOR '(' expression ';' expression ';' expression ')' statement { std::cout << "Reduction: FOR '(' expression ';' expression ';' expression ')' statement -> iteration_statement" << std::endl << std::endl; }
	;

jump_statement
	: GOTO identifier ';' { std::cout << "Reduction: GOTO identifier ';' -> jump_statement" << std::endl << std::endl; }
	| CONTINUE ';' { std::cout << "Reduction: CONTINUE ';' -> jump_statement" << std::endl << std::endl; }
	| BREAK ';' { std::cout << "Reduction: BREAK ';' -> jump_statement" << std::endl << std::endl; }
	| RETURN ';' { std::cout << "Reduction: RETURN ';' -> jump_statement" << std::endl << std::endl; }
	| RETURN expression ';' { std::cout << "Reduction: RETURN expression ';' -> jump_statement" << std::endl << std::endl; }
	;

expression
	: assignment_expression { std::cout << "Reduction: assignment_expression -> expression" << std::endl << std::endl; }
	| expression ',' assignment_expression { std::cout << "Reduction: expression ',' assignment_expression -> expression" << std::endl << std::endl; }
	;

assignment_expression
	: conditional_expression { std::cout << "Reduction: conditional_expression -> assignment_expression" << std::endl << std::endl; }
	| unary_expression assignment_operator assignment_expression { std::cout << "Reduction: unary_expression assignment_operator assignment_expression -> assignment_expression" << std::endl << std::endl; }
	;

assignment_operator
	: '=' { std::cout << "Reduction: '=' -> assignment_operator" << std::endl << std::endl; }
	| MUL_ASSIGN { std::cout << "Reduction: MUL_ASSIGN -> assignment_operator" << std::endl << std::endl; }
	| DIV_ASSIGN { std::cout << "Reduction: DIV_ASSIGN -> assignment_operator" << std::endl << std::endl; }
	| MOD_ASSIGN { std::cout << "Reduction: MOD_ASSIGN -> assignment_operator" << std::endl << std::endl; }
	| ADD_ASSIGN { std::cout << "Reduction: ADD_ASSIGN -> assignment_operator" << std::endl << std::endl; }
	| SUB_ASSIGN { std::cout << "Reduction: SUB_ASSIGN -> assignment_operator" << std::endl << std::endl; }
	| LEFT_ASSIGN { std::cout << "Reduction: LEFT_ASSIGN -> assignment_operator" << std::endl << std::endl; }
	| RIGHT_ASSIGN { std::cout << "Reduction: RIGHT_ASSIGN -> assignment_operator" << std::endl << std::endl; }
	| AND_ASSIGN { std::cout << "Reduction: AND_ASSIGN -> assignment_operator" << std::endl << std::endl; }
	| XOR_ASSIGN { std::cout << "Reduction: XOR_ASSIGN -> assignment_operator" << std::endl << std::endl; }
	| OR_ASSIGN { std::cout << "Reduction: OR_ASSIGN -> assignment_operator" << std::endl << std::endl; }
	;

conditional_expression
	: logical_or_expression { std::cout << "Reduction: logical_or_expression -> conditional_expression" << std::endl << std::endl; }
	| logical_or_expression '?' expression ':' conditional_expression { std::cout << "Reduction: logical_or_expression '?' expression ':' conditional_expression -> conditional_expression" << std::endl << std::endl; }
	;

constant_expression
	: conditional_expression { std::cout << "Reduction: conditional_expression -> constant_expression" << std::endl << std::endl; }
	;

logical_or_expression
	: logical_and_expression { std::cout << "Reduction: logical_and_expression -> logical_or_expression" << std::endl << std::endl; }
	| logical_or_expression OR_OP logical_and_expression { std::cout << "Reduction: logical_or_expression OR_OP logical_and_expression -> logical_or_expression" << std::endl << std::endl; }
	;

logical_and_expression
	: inclusive_or_expression { std::cout << "Reduction: inclusive_or_expression -> logical_and_expression" << std::endl << std::endl; }
	| logical_and_expression AND_OP inclusive_or_expression { std::cout << "Reduction: logical_and_expression AND_OP inclusive_or_expression -> logical_and_expression" << std::endl << std::endl; }
	;

inclusive_or_expression
	: exclusive_or_expression { std::cout << "Reduction: exclusive_or_expression -> inclusive_or_expression" << std::endl << std::endl; }
	| inclusive_or_expression '|' exclusive_or_expression { std::cout << "Reduction: inclusive_or_expression '|' exclusive_or_expression -> inclusive_or_expression" << std::endl << std::endl; }
	;

exclusive_or_expression
	: and_expression { std::cout << "Reduction: and_expression -> exclusive_or_expression" << std::endl << std::endl; }
	| exclusive_or_expression '^' and_expression { std::cout << "Reduction: exclusive_or_expression '^' and_expression -> exclusive_or_expression" << std::endl << std::endl; }
	;

and_expression
	: equality_expression { std::cout << "Reduction: equality_expression -> and_expression" << std::endl << std::endl; }
	| and_expression '&' equality_expression { std::cout << "Reduction: and_expression '&' equality_expression -> and_expression" << std::endl << std::endl; }
	;

equality_expression
	: relational_expression { std::cout << "Reduction: relational_expression -> equality_expression" << std::endl << std::endl; }
	| equality_expression EQ_OP relational_expression { std::cout << "Reduction: equality_expression EQ_OP relational_expression -> equality_expression" << std::endl << std::endl; }
	| equality_expression NE_OP relational_expression { std::cout << "Reduction: equality_expression NE_OP relational_expression -> equality_expression" << std::endl << std::endl; }
	;

relational_expression
	: shift_expression { std::cout << "Reduction: shift_expression -> relational_expression" << std::endl << std::endl; }
	| relational_expression '<' shift_expression { std::cout << "Reduction: relational_expression '<' shift_expression -> relational_expression" << std::endl << std::endl; }
	| relational_expression '>' shift_expression { std::cout << "Reduction: relational_expression '>' shift_expression -> relational_expression" << std::endl << std::endl; }
	| relational_expression LE_OP shift_expression { std::cout << "Reduction: relational_expression LE_OP shift_expression -> relational_expression" << std::endl << std::endl; }
	| relational_expression GE_OP shift_expression { std::cout << "Reduction: relational_expression GE_OP shift_expression -> relational_expression" << std::endl << std::endl; }
	;

shift_expression
	: additive_expression { std::cout << "Reduction: additive_expression -> shift_expression" << std::endl << std::endl; }
	| shift_expression LEFT_OP additive_expression { std::cout << "Reduction: shift_expression LEFT_OP additive_expression -> shift_expression" << std::endl << std::endl; }
	| shift_expression RIGHT_OP additive_expression { std::cout << "Reduction: shift_expression RIGHT_OP additive_expression -> shift_expression" << std::endl << std::endl; }
	;

additive_expression
	: multiplicative_expression { std::cout << "Reduction: multiplicative_expression -> additive_expression" << std::endl << std::endl; }
	| additive_expression '+' multiplicative_expression { std::cout << "Reduction: additive_expression '+' multiplicative_expression -> additive_expression" << std::endl << std::endl; }
	| additive_expression '-' multiplicative_expression { std::cout << "Reduction: additive_expression '-' multiplicative_expression -> additive_expression" << std::endl << std::endl; }
	;

multiplicative_expression
	: cast_expression { std::cout << "Reduction: cast_expression -> multiplicative_expression" << std::endl << std::endl; }
	| multiplicative_expression '*' cast_expression { std::cout << "Reduction: multiplicative_expression '*' cast_expression -> multiplicative_expression" << std::endl << std::endl; }
	| multiplicative_expression '/' cast_expression { std::cout << "Reduction: multiplicative_expression '/' cast_expression -> multiplicative_expression" << std::endl << std::endl; }
	| multiplicative_expression '%' cast_expression { std::cout << "Reduction: multiplicative_expression '%' cast_expression -> multiplicative_expression" << std::endl << std::endl; }
	;

cast_expression
	: unary_expression { std::cout << "Reduction: unary_expression -> cast_expression" << std::endl << std::endl; }
	| '(' type_name ')' cast_expression { std::cout << "Reduction: '(' type_name ')' cast_expression -> cast_expression" << std::endl << std::endl; }
	;

unary_expression
	: postfix_expression { std::cout << "Reduction: postfix_expression -> unary_expression" << std::endl << std::endl; }
	| INC_OP unary_expression { std::cout << "Reduction: INC_OP unary_expression -> unary_expression" << std::endl << std::endl; }
	| DEC_OP unary_expression { std::cout << "Reduction: DEC_OP unary_expression -> unary_expression" << std::endl << std::endl; }
	| unary_operator cast_expression { std::cout << "Reduction: unary_operator cast_expression -> unary_expression" << std::endl << std::endl; }
	| SIZEOF unary_expression { std::cout << "Reduction: SIZEOF unary_expression -> unary_expression" << std::endl << std::endl; }
	| SIZEOF '(' type_name ')' { std::cout << "Reduction: SIZEOF '(' type_name ')' -> unary_expression" << std::endl << std::endl; }
	;

unary_operator
	: '&' { std::cout << "Reduction: '&' -> unary_operator" << std::endl << std::endl; }
	| '*' { std::cout << "Reduction: '*' -> unary_operator" << std::endl << std::endl; }
	| '+' { std::cout << "Reduction: '+' -> unary_operator" << std::endl << std::endl; }
	| '-' { std::cout << "Reduction: '-' -> unary_operator" << std::endl << std::endl; }
	| '~' { std::cout << "Reduction: '~' -> unary_operator" << std::endl << std::endl; }
	| '!' { std::cout << "Reduction: '!' -> unary_operator" << std::endl << std::endl; }
	;

postfix_expression
	: primary_expression { std::cout << "Reduction: primary_expression -> postfix_expression" << std::endl << std::endl; }
	| postfix_expression '[' expression ']' { std::cout << "Reduction: postfix_expression '[' expression ']' -> postfix_expression" << std::endl << std::endl; }
	| postfix_expression '(' ')' { std::cout << "Reduction: postfix_expression '(' ')' -> postfix_expression" << std::endl << std::endl; }
	| postfix_expression '(' argument_expression_list ')' { std::cout << "Reduction: postfix_expression '(' argument_expression_list ')' -> postfix_expression" << std::endl << std::endl; }
	| postfix_expression '.' identifier { std::cout << "Reduction: postfix_expression '.' identifier -> postfix_expression" << std::endl << std::endl; }
	| postfix_expression PTR_OP identifier { std::cout << "Reduction: postfix_expression PTR_OP identifier -> postfix_expression" << std::endl << std::endl; }
	| postfix_expression INC_OP { std::cout << "Reduction: postfix_expression INC_OP -> postfix_expression" << std::endl << std::endl; }
	| postfix_expression DEC_OP { std::cout << "Reduction: postfix_expression DEC_OP -> postfix_expression" << std::endl << std::endl; }
	;

primary_expression
	: identifier { std::cout << "Reduction: identifier -> primary_expression" << std::endl << std::endl; }
	| constant { std::cout << "Reduction: constant -> primary_expression" << std::endl << std::endl; }
	| string { std::cout << "Reduction: string -> primary_expression" << std::endl << std::endl; }
	| '(' expression ')' { std::cout << "Reduction: '(' expression ')' -> primary_expression" << std::endl << std::endl; }
	;

argument_expression_list
	: assignment_expression { std::cout << "Reduction: assignment_expression -> argument_expression_list" << std::endl << std::endl; }
	| argument_expression_list ',' assignment_expression { std::cout << "Reduction: argument_expression_list ',' assignment_expression -> argument_expression_list" << std::endl << std::endl; }
	;

constant
	: I_CONSTANT /* includes character_constant */ { std::cout << "Reduction: I_CONSTANT -> constant" << std::endl << std::endl; }
	| F_CONSTANT { std::cout << "Reduction: F_CONSTANT -> constant" << std::endl << std::endl; }
	| CHAR_LITERAL { std::cout << "Reduction: CHAR_LITERAL -> constant" << std::endl << std::endl; }
	| ENUMERATION_CONSTANT /* after it has been defined as such */ { std::cout << "Reduction: ENUMERATION_CONSTANT-> constant" << std::endl << std::endl; }
	;

string
	: STRING_LITERAL { std::cout << "Reduction: STRING_LITERAL -> string" << std::endl << std::endl; }
	;

identifier
	: IDENTIFIER { std::cout << "Reduction: IDENTIFIER -> identifier" << std::endl << std::endl; }
	{
	$$ = scanner->matched();
	}
	;

