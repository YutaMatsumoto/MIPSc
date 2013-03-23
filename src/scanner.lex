D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*
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

{L}({L}|{D})*	        { update(); return(Parser::IDENTIFIER); }
0(x|X){H}+(u|l)?	    { update(); return Parser::I_CONSTANT; }
{D}+(u|l)?	            { update(); return Parser::I_CONSTANT; }

{D}+(f|l)?	            { update(); return Parser::F_CONSTANT; }
{D}*"."{D}(f|l)?	    { update(); return Parser::F_CONSTANT; }


\"(\\.|[^\\"])*\"       { update(); return Parser::STRING_LITERAL; }

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

