#include <stack>
#include <unordered_map>
#include "Parserbase.h"

class SymbolTable
{
	
	public:
	
	// symbol is the symbol name (eg. mychar)
	void insertSymbol( std::string symbol , Meta__::SType value );
	bool hasSymbol( std::string symbol );

	void dumpTable( std::string filename );

	protected:
	
	std::stack< std::unordered_map< std::string , Meta__::SType > > tableStack;
	
	std::stack< std::unordered_map< std::string , Meta__::SType > > inverseTableStack;


};
