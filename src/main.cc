//============================================================================
// Name        : c_compiler.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : C Compiler
//============================================================================

#include <iostream>
#include "Parser.h"
#include "SymbolTable.h"

int main() {
	
	SymbolTable* table = new SymbolTable();

	Parser p( std::cin , table );
	
	p.setDebug( false );

	p.parse();

	return 0;
}
