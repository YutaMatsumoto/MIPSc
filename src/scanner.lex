D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%%

%locations

"!!S"					{ return( Parser::SYMBOL_DUMP ); }

<<EOF>>					{ return( Parser::ENDOFFILE ); }

"/*"                    {  }
"//".*                  {  }

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
"inline"				{  }
"int"					{ return(Parser::INT); }
"long"					{ return(Parser::LONG); }
"register"				{ return(Parser::REGISTER); }
"restrict"				{  }
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

{L}({L}|{D})*	        { return(Parser::IDENTIFIER); }
0(x|X){H}+(u|l)?	    { return Parser::I_CONSTANT; }
{D}+(u|l)?	            { return Parser::I_CONSTANT; }

{D}+(f|l)?	            { return Parser::F_CONSTANT; }
{D}*"."{D}(f|l)?	    { return Parser::F_CONSTANT; }

\"(\\.|[^\\"])*\"       { return Parser::STRING_LITERAL; }

"..."			        { return(Parser::ELLIPSIS); }
">>="			        { return(Parser::RIGHT_ASSIGN); }
"<<="			        { return(Parser::LEFT_ASSIGN); }
"+="			        { return(Parser::ADD_ASSIGN); }
"-="			        { return(Parser::SUB_ASSIGN); }
"*="			        { return(Parser::MUL_ASSIGN); }
"/="			        { return(Parser::DIV_ASSIGN); }
"%="			        { return(Parser::MOD_ASSIGN); }
"&="			        { return(Parser::AND_ASSIGN); }
"^="			        { return(Parser::XOR_ASSIGN); }
"|="			        { return(Parser::OR_ASSIGN); }
">>"			        { return(Parser::RIGHT_OP); }
"<<"			        { return(Parser::LEFT_OP); }
"++"			        { return(Parser::INC_OP); }
"--"			        { return(Parser::DEC_OP); }
"->"			        { return(Parser::PTR_OP); }
"&&"			        { return(Parser::AND_OP); }
"||"			        { return(Parser::OR_OP); }
"<="			        { return(Parser::LE_OP); }
">="			        { return(Parser::GE_OP); }
"=="			        { return(Parser::EQ_OP); }
"!="			        { return(Parser::NE_OP); }
";"			            { return(';'); }
("{"|"<%")		        { return('{'); }
("}"|"%>")		        { return('}'); }
"'"						{ return(Parser::SQUOTE); }
","			            { return(','); }
":"			            { return(':'); }
"="			            { return('='); }
"("			            { return('('); }
")"			            { return(')'); }
("["|"<:")		        { return('['); }
("]"|":>")		        { return(']'); }
"."			            { return('.'); }
"&"			            { return('&'); }
"!"			            { return('!'); }
"~"			            { return('~'); }
"-"			            { return('-'); }
"+"			            { return('+'); }
"*"			            { return('*'); }
"/"			            { return('/'); }
"%"			            { return('%'); }
"<"			            { return('<'); }
">"			            { return('>'); }
"^"			            { return('^'); }
"|"			            { return('|'); }
"?"			            { return('?'); }

[ \t\v\n\f]		        { }
.			            { scannerError(); }

