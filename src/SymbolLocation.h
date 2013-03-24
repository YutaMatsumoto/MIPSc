#ifndef SYMBOL_LOCATION_GUARD
#define SYMBOL_LOCATION_GUARD

struct Loc {

	Loc() : lnum(1), cnum(1), lastNewlinePos(-1), currNewLinePos(-1), numBytesRead(0) {} 

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

	int lnum; // line number
	int cnum; // column number
	int lastNewlinePos;
	int currNewLinePos;
	int numBytesRead;
};

#endif
