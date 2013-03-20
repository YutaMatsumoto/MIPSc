#include <iostream>

#include "SymbolTable.h"
#include "Parser.h"

int main(int argc, char** argv)
{

	SymbolTable stab;
	
	for(int i=0;i<argc;i++) {
		std::cout << argv[i] << std::endl;
	}

	stab.insertSymbol("hello", SymbolLoc() );
	stab.insertSymbol("World", SymbolLoc() );

	stab.dumpTable( "stab" );

}
