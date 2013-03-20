//============================================================================
// Name        : c_compiler.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : C Compiler
//============================================================================

#include <iostream>
#include "Parser.h"

int main() {

	Parser p;
	
	p.setDebug( true );

	p.parse();

	return 0;
}
