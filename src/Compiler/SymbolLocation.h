#ifndef SYMBOL_LOCATION_GUARD
#define SYMBOL_LOCATION_GUARD

#include <iostream>

struct SymbolLocation {

	SymbolLocation() : lnum(1), cnum(1), lastNewlinePos(-1), currNewLinePos(-1), numBytesRead(0) {} 

	void print()
	{
		std::cout << "( lnum, cnum, lastNewlinePos, currNewLinePos, numBytesRead " << std::endl;
		std::cout << "("
			<< lnum << ", "
			<< cnum << ", "
			<< lastNewlinePos << ", "
			<< currNewLinePos << ", "
			<< numBytesRead
			<< ")" 
			<< std::endl;
	}

	int lnum;

	int cnum;

	int lastNewlinePos;

	int currNewLinePos;

	int numBytesRead;

};

#endif
