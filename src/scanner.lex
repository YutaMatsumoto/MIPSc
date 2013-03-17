O   [0-7]
D   [0-9]
NZ  [1-9]
L   [a-zA-Z_]
A   [a-zA-Z_0-9]
H   [a-fA-F0-9]
HP  (0[xX])
E   ([Ee][+-]?{D}+)
P   ([Pp][+-]?{D}+)
FS  (f|F|l|L)
IS  (((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
CP  (u|U|L)
SP  (u8|u|U|L)
ES  (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WS  [ \t\v\n\f]

%%

"/*"                                    {  }
"//".*                                  {  }

"auto"					{ return(Parser::AUTO); }
"break"					{ return(Parser::BREAK); }
"case"					{ return(Parser::CASE); }
"char"					{ return(Parser::CHAR); }
"const"					{ return(Parser::CONST); }
"continue"				{ return(Parser::CONTINUE); }
"default"				{ return(Parser::DEFAULT); }
"do"					{ return(Parser::DO); }
"double"				{ return(Parser::DOUBLE); }
"else"					{ return(Parser::ELSE); }
"enum"					{ return(Parser::ENUM); }
"extern"				{ return(Parser::EXTERN); }
"float"					{ return(Parser::FLOAT); }
"for"					{ return(Parser::FOR); }
"goto"					{ return(Parser::GOTO); }
"if"					{ return(Parser::IF); }
"inline"				{ return(Parser::INLINE); }
"int"					{ return(Parser::INT); }
"long"					{ return(Parser::LONG); }
"register"				{ return(Parser::REGISTER); }
"restrict"				{ return(Parser::RESTRICT); }
"return"				{ return(Parser::RETURN); }
"short"					{ return(Parser::SHORT); }
"signed"				{ return(Parser::SIGNED); }
"sizeof"				{ return(Parser::SIZEOF); }
"static"				{ return(Parser::STATIC); }
"struct"				{ return(Parser::STRUCT); }
"switch"				{ return(Parser::SWITCH); }
"typedef"				{ return(Parser::TYPEDEF); }
"union"					{ return(Parser::UNION); }
"unsigned"				{ return(Parser::UNSIGNED); }
"void"					{ return(Parser::VOID); }
"volatile"				{ return(Parser::VOLATILE); }
"while"					{ return(Parser::WHILE); }
"_Alignas"                              { return Parser::ALIGNAS; }
"_Alignof"                              { return Parser::ALIGNOF; }
"_Atomic"                               { return Parser::ATOMIC; }
"_Bool"                                 { return Parser::BOOL; }
"_Complex"                              { return Parser::COMPLEX; }
"_Generic"                              { return Parser::GENERIC; }
"_Imaginary"                            { return Parser::IMAGINARY; }
"_Noreturn"                             { return Parser::NORETURN; }
"_Static_assert"                        { return Parser::STATIC_ASSERT; }
"_Thread_local"                         { return Parser::THREAD_LOCAL; }
"__func__"                              { return Parser::FUNC_NAME; }

{L}{A}*					{ return Parser::IDENTIFIER; }

{HP}{H}+{IS}?				{ return Parser::I_CONSTANT; }
{NZ}{D}*{IS}?				{ return Parser::I_CONSTANT; }
"0"{O}*{IS}?				{ return Parser::I_CONSTANT; }
{CP}?"'"([^'\\\n]|{ES})+"'"		{ return Parser::I_CONSTANT; }

{D}+{E}{FS}?				{ return Parser::F_CONSTANT; }
{D}*"."{D}+{E}?{FS}?			{ return Parser::F_CONSTANT; }
{D}+"."{E}?{FS}?			{ return Parser::F_CONSTANT; }
{HP}{H}+{P}{FS}?			{ return Parser::F_CONSTANT; }
{HP}{H}*"."{H}+{P}{FS}?			{ return Parser::F_CONSTANT; }
{HP}{H}+"."{P}{FS}?			{ return Parser::F_CONSTANT; }

({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+	{ return Parser::STRING_LITERAL; }

"..."					{ return Parser::ELLIPSIS; }
">>="					{ return Parser::RIGHT_ASSIGN; }
"<<="					{ return Parser::LEFT_ASSIGN; }
"+="					{ return Parser::ADD_ASSIGN; }
"-="					{ return Parser::SUB_ASSIGN; }
"*="					{ return Parser::MUL_ASSIGN; }
"/="					{ return Parser::DIV_ASSIGN; }
"%="					{ return Parser::MOD_ASSIGN; }
"&="					{ return Parser::AND_ASSIGN; }
"^="					{ return Parser::XOR_ASSIGN; }
"|="					{ return Parser::OR_ASSIGN; }
">>"					{ return Parser::RIGHT_OP; }
"<<"					{ return Parser::LEFT_OP; }
"++"					{ return Parser::INC_OP; }
"--"					{ return Parser::DEC_OP; }
"->"					{ return Parser::PTR_OP; }
"&&"					{ return Parser::AND_OP; }
"||"					{ return Parser::OR_OP; }
"<="					{ return Parser::LE_OP; }
">="					{ return Parser::GE_OP; }
"=="					{ return Parser::EQ_OP; }
"!="					{ return Parser::NE_OP; }
";"					{ return ';'; }
("{"|"<%")				{ return '{'; }
("}"|"%>")				{ return '}'; }
","					{ return ','; }
":"					{ return ':'; }
"="					{ return '='; }
"("					{ return '('; }
")"					{ return ')'; }
("["|"<:")				{ return '['; }
("]"|":>")				{ return ']'; }
"."					{ return '.'; }
"&"					{ return '&'; }
"!"					{ return '!'; }
"~"					{ return '~'; }
"-"					{ return '-'; }
"+"					{ return '+'; }
"*"					{ return '*'; }
"/"					{ return '/'; }
"%"					{ return '%'; }
"<"					{ return '<'; }
">"					{ return '>'; }
"^"					{ return '^'; }
"|"					{ return '|'; }
"?"					{ return '?'; }

{WS}					{ /* whitespace separates tokens */ }
.					{ return Parser::ERROR; }

