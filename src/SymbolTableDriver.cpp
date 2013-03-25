#include <iostream>

#include "SymbolTable.h"
#include "Symbol.h"
// #include "Parser.h"

int main(int argc, char** argv)
{

	std::string foo = "foo";

	std::string bar = "bar";

	std::string abc = "abc";

	std::string def = "def";

	SymbolTable stab;

	Symbol* i = new Symbol( foo, 1 , 1 );

	stab.insertSymbol( i );

	Symbol* j = new Symbol( bar, 1 , 1 );

	stab.insertSymbol( j );

	stab.beginScope();

	Symbol* k = new Symbol( foo, 1 , 1 );

	stab.insertSymbol( k );

	Symbol* l = new Symbol( abc, 1 , 1 );

	stab.insertSymbol( l );

	Symbol* m = new Symbol( def, 1 , 1 );

	stab.insertSymbol( m );

	stab.insertSymbol( m );

	stab.dumpTable( "symboltabledebug.txt" );

}
