//
//	This is a lexer definition file that will be fed into flexc++. Then,
//	flexc++ produces skelton files for C++ Scanner class :
//
//		Scannerbase.h : base class that Scanner class is supposed to extend from
//		Scanner.h     : interface for Scanner class
//		Scanner.ih    : implementation of Scanner class
//		lex.cc        : lex implementation which includes Scanner.h and Scanner.ih
//
//	In this lex definition file, we can use precedures defined in Scanner class
//
//	On each token extraction, Scanner::update() function is called unless
//	error happends to do bookkeeping such as keeping track of current location
//	of the source file the scanner is at. 
//

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
CHAR		"'"."'"

%%

%locations

"!!S"					{ update(); dumpSymbolTable(); }

<<EOF>>					{ update(); return( Parser::ENDOFFILE ); }

"/*"                    { update(); return Parser::COMMENT; } // TODO make matchher for multiline comment
"//".*                  { update(); return Parser::COMMENT; }

"auto"					{ update(); return(Parser::AUTO); }
"break"					{ update(); return(Parser::BREAK); }
"case"					{ update(); return(Parser::CASE); }
"char"					{ update(); return(Parser::CHAR); }
"const"					{ update(); return(Parser::CONST); }
"continue"				{ update(); return(Parser::CONTINUE); }
"default"				{ update(); return(Parser::DEFAULT); }
"do"					{ update(); return(Parser::DO); }
"double"				{ update(); return(Parser::DOUBLE); }
"else"					{ update(); return(Parser::ELSE); }
"enum"					{ update(); return(Parser::ENUM); }
"extern"				{ update(); return(Parser::EXTERN); }
"float"					{ update(); return(Parser::FLOAT); }
"for"					{ update(); return(Parser::FOR); }
"goto"					{ update(); return(Parser::GOTO); }
"if"					{ update(); return(Parser::IF); }
"inline"				{  }
"int"					{ update(); return(Parser::INT); }
"long"					{ update(); return(Parser::LONG); }
"register"				{ update(); return(Parser::REGISTER); }
"restrict"				{  }
"return"				{ update(); return(Parser::RETURN); }
"short"					{ update(); return(Parser::SHORT); }
"signed"				{ update(); return(Parser::SIGNED); }
"sizeof"				{ update(); return(Parser::SIZEOF); }
"static"				{ update(); return(Parser::STATIC); }
"struct"				{ update(); return(Parser::STRUCT); }
"switch"				{ update(); return(Parser::SWITCH); }
"typedef"				{ update(); return(Parser::TYPEDEF); }
"union"					{ update(); return(Parser::UNION); }
"unsigned"				{ update(); return(Parser::UNSIGNED); }
"void"					{ update(); return(Parser::VOID); }
"volatile"				{ update(); return(Parser::VOLATILE); }
"while"					{ update(); return(Parser::WHILE); }

{L}{A}*	                { update(); return(Parser::IDENTIFIER); }

{HP}{H}+{IS}?				    { return Parser::I_CONSTANT; }
{NZ}{D}*{IS}?				    { return Parser::I_CONSTANT; }
"0"{O}*{IS}?				    { return Parser::I_CONSTANT; }
{CP}?"'"([^'\\\n]|{ES})+"'"		{ return Parser::I_CONSTANT; }

{D}+{E}{FS}?				    { return Parser::F_CONSTANT; }
{D}*"."{D}+{E}?{FS}?			{ return Parser::F_CONSTANT; }
{D}+"."{E}?{FS}?			    { return Parser::F_CONSTANT; }
{HP}{H}+{P}{FS}?			    { return Parser::F_CONSTANT; }
{HP}{H}*"."{H}+{P}{FS}?			{ return Parser::F_CONSTANT; }
{HP}{H}+"."{P}{FS}?			    { return Parser::F_CONSTANT; }

L?\"(\\.|[^\\"])*\"  	{ return Parser::STRING_LITERAL; }

"..."			        { update(); return(Parser::ELLIPSIS); }
">>="			        { update(); return(Parser::RIGHT_ASSIGN); }
"<<="			        { update(); return(Parser::LEFT_ASSIGN); }
"+="			        { update(); return(Parser::ADD_ASSIGN); }
"-="			        { update(); return(Parser::SUB_ASSIGN); }
"*="			        { update(); return(Parser::MUL_ASSIGN); }
"/="			        { update(); return(Parser::DIV_ASSIGN); }
"%="			        { update(); return(Parser::MOD_ASSIGN); }
"&="			        { update(); return(Parser::AND_ASSIGN); }
"^="			        { update(); return(Parser::XOR_ASSIGN); }
"|="			        { update(); return(Parser::OR_ASSIGN); }
">>"			        { update(); return(Parser::RIGHT_OP); }
"<<"			        { update(); return(Parser::LEFT_OP); }
"++"			        { update(); return(Parser::INC_OP); }
"--"			        { update(); return(Parser::DEC_OP); }
"->"			        { update(); return(Parser::PTR_OP); }
"&&"			        { update(); return(Parser::AND_OP); }
"||"			        { update(); return(Parser::OR_OP); }
"<="			        { update(); return(Parser::LE_OP); }
">="			        { update(); return(Parser::GE_OP); }
"=="			        { update(); return(Parser::EQ_OP); }
"!="			        { update(); return(Parser::NE_OP); }
";"			            { update(); return(';'); }
("{"|"<%")		        { update(); return('{'); }
("}"|"%>")		        { update(); return('}'); }
//"'"					{ update(); return(Parser::SQUOTE); }
","			            { update(); return(','); }
":"			            { update(); return(':'); }
"="			            { update(); return('='); }
"("			            { update(); return('('); }
")"			            { update(); return(')'); }
("["|"<:")		        { update(); return('['); }
("]"|":>")		        { update(); return(']'); }
"."			            { update(); return('.'); }
"&"			            { update(); return('&'); }
"!"			            { update(); return('!'); }
"~"			            { update(); return('~'); }
"-"			            { update(); return('-'); }
"+"			            { update(); return('+'); }
"*"			            { update(); return('*'); }
"/"			            { update(); return('/'); }
"%"			            { update(); return('%'); }
"<"			            { update(); return('<'); }
">"			            { update(); return('>'); }
"^"			            { update(); return('^'); }
"|"			            { update(); return('|'); }
"?"			            { update(); return('?'); }

[\v\f]		        	{ update(); /* Eat useless whitespace */ }
[ ]				        { update(); }
[\t]				    { update(); }
[\n]				    { update(); }

{CHAR}				    { update(); return Parser::CHAR_LITERAL; }

.			            { scannerError(); }

