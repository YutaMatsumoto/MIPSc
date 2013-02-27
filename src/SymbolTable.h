#include <stack>
#include <unordered_map>
#include "Parserbase.h"

class SymbolTable
{
	
	public:
	
	// symbol is the symbol name (eg. mychar)
	void insertSymbol( std::string symbol , Meta__::SType value );
	
	//Has this symbol been defined yet
	bool hasSymbol( std::string symbol );
	
	//dumps the symbol table to a file
	void dumpTable( std::string filename );

	protected:
	
	//This is the stack of Hash Maps
	std::stack< std::unordered_map< std::string , Meta__::SType > > tableStack;
	
	//This is another stack of hash maps, when you pop a HashMap off the 
	//  first stack, we push it on here to preserve the stack ordering
	std::stack< std::unordered_map< std::string , Meta__::SType > > inverseTableStack;


};
