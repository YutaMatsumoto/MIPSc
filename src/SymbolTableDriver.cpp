#include <iostream>

#include "SymbolTable.h"
#include "Parser.h"

int main(int argc, char** argv)
{

	SymbolTable stab;
	
	for(int i=0;i<argc;i++) {
		std::cout << argv[i] << std::endl;
	}

	// insertSymbol
	stab.insertSymbol("hello", SymbolLoc() );
	stab.insertSymbol("World", SymbolLoc() );

	// searchSymbol
	SymbolDetail sd = stab.searchSymbol("hello", stab.currentScope());
	SymbolScope sscope = sd.sscope; // Iteracotr
	SymbolData data = sd.sdata;
	std::cout << ( sscope[0] )["hello"] << std::cout ;

	// dumpTable
	stab.dumpTable( "stab.debug" );

}
