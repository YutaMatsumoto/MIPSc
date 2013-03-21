D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*
CHAR		"'"."'"

%%

%locations

"!!S"					{ updateLocation(); dumpSymbolTable(); }

<<EOF>>					{ updateLocation(); return( Parser::ENDOFFILE ); }

"/*"                    {  }
"//".*                  {  }

"auto"					{ updateLocation(); return(Parser::AUTO); }
"break"					{ updateLocation(); return(Parser::BREAK); }
"case"					{ updateLocation(); return(Parser::CASE); }
"char"					{ updateLocation(); return(Parser::CHAR); }
"const"					{ updateLocation(); return(Parser::CONST); }
"continue"				{ updateLocation(); return(Parser::CONTINUE); }
"default"				{ updateLocation(); return(Parser::DEFAULT); }
"do"					{ updateLocation(); return(Parser::DO); }
"double"				{ updateLocation(); return(Parser::DOUBLE); }
"else"					{ updateLocation(); return(Parser::ELSE); }
"enum"					{ updateLocation(); return(Parser::ENUM); }
"extern"				{ updateLocation(); return(Parser::EXTERN); }
"float"					{ updateLocation(); return(Parser::FLOAT); }
"for"					{ updateLocation(); return(Parser::FOR); }
"goto"					{ updateLocation(); return(Parser::GOTO); }
"if"					{ updateLocation(); return(Parser::IF); }
"inline"				{  }
"int"					{ updateLocation(); return(Parser::INT); }
"long"					{ updateLocation(); return(Parser::LONG); }
"register"				{ updateLocation(); return(Parser::REGISTER); }
"restrict"				{  }
"return"				{ updateLocation(); return(Parser::RETURN); }
"short"					{ updateLocation(); return(Parser::SHORT); }
"signed"				{ updateLocation(); return(Parser::SIGNED); }
"sizeof"				{ updateLocation(); return(Parser::SIZEOF); }
"static"				{ updateLocation(); return(Parser::STATIC); }
"struct"				{ updateLocation(); return(Parser::STRUCT); }
"switch"				{ updateLocation(); return(Parser::SWITCH); }
"typedef"				{ updateLocation(); return(Parser::TYPEDEF); }
"union"					{ updateLocation(); return(Parser::UNION); }
"unsigned"				{ updateLocation(); return(Parser::UNSIGNED); }
"void"					{ updateLocation(); return(Parser::VOID); }
"volatile"				{ updateLocation(); return(Parser::VOLATILE); }
"while"					{ updateLocation(); return(Parser::WHILE); }

{L}({L}|{D})*	        { updateLocation(); return(Parser::IDENTIFIER); }
0(x|X){H}+(u|l)?	    { updateLocation(); return Parser::I_CONSTANT; }
{D}+(u|l)?	            { updateLocation(); return Parser::I_CONSTANT; }

{D}+(f|l)?	            { updateLocation(); return Parser::F_CONSTANT; }
{D}*"."{D}(f|l)?	    { updateLocation(); return Parser::F_CONSTANT; }


\"(\\.|[^\\"])*\"       { updateLocation(); return Parser::STRING_LITERAL; }

"..."			        { updateLocation(); return(Parser::ELLIPSIS); }
">>="			        { updateLocation(); return(Parser::RIGHT_ASSIGN); }
"<<="			        { updateLocation(); return(Parser::LEFT_ASSIGN); }
"+="			        { updateLocation(); return(Parser::ADD_ASSIGN); }
"-="			        { updateLocation(); return(Parser::SUB_ASSIGN); }
"*="			        { updateLocation(); return(Parser::MUL_ASSIGN); }
"/="			        { updateLocation(); return(Parser::DIV_ASSIGN); }
"%="			        { updateLocation(); return(Parser::MOD_ASSIGN); }
"&="			        { updateLocation(); return(Parser::AND_ASSIGN); }
"^="			        { updateLocation(); return(Parser::XOR_ASSIGN); }
"|="			        { updateLocation(); return(Parser::OR_ASSIGN); }
">>"			        { updateLocation(); return(Parser::RIGHT_OP); }
"<<"			        { updateLocation(); return(Parser::LEFT_OP); }
"++"			        { updateLocation(); return(Parser::INC_OP); }
"--"			        { updateLocation(); return(Parser::DEC_OP); }
"->"			        { updateLocation(); return(Parser::PTR_OP); }
"&&"			        { updateLocation(); return(Parser::AND_OP); }
"||"			        { updateLocation(); return(Parser::OR_OP); }
"<="			        { updateLocation(); return(Parser::LE_OP); }
">="			        { updateLocation(); return(Parser::GE_OP); }
"=="			        { updateLocation(); return(Parser::EQ_OP); }
"!="			        { updateLocation(); return(Parser::NE_OP); }
";"			            { updateLocation(); return(';'); }
("{"|"<%")		        { updateLocation(); return('{'); }
("}"|"%>")		        { updateLocation(); return('}'); }
//"'"						{ updateLocation(); return(Parser::SQUOTE); }
","			            { updateLocation(); return(','); }
":"			            { updateLocation(); return(':'); }
"="			            { updateLocation(); return('='); }
"("			            { updateLocation(); return('('); }
")"			            { updateLocation(); return(')'); }
("["|"<:")		        { updateLocation(); return('['); }
("]"|":>")		        { updateLocation(); return(']'); }
"."			            { updateLocation(); return('.'); }
"&"			            { updateLocation(); return('&'); }
"!"			            { updateLocation(); return('!'); }
"~"			            { updateLocation(); return('~'); }
"-"			            { updateLocation(); return('-'); }
"+"			            { updateLocation(); return('+'); }
"*"			            { updateLocation(); return('*'); }
"/"			            { updateLocation(); return('/'); }
"%"			            { updateLocation(); return('%'); }
"<"			            { updateLocation(); return('<'); }
">"			            { updateLocation(); return('>'); }
"^"			            { updateLocation(); return('^'); }
"|"			            { updateLocation(); return('|'); }
"?"			            { updateLocation(); return('?'); }


[\v\f]		        	{ /* Eat useless whitespace */ }
[ ]				        { updateLocation(); }
[\t]				    { updateLocation(); }
[\n]				    { updateLocation(); }

{CHAR}				    { updateLocation(); return Parser::CHAR_LITERAL; }

.			            { updateLocation(); scannerError(); }

