#include "SymbolTable.h"

SymbolInfo SymbolTable::insertSymbol( SymbolKey skey, SymbolLoc loc )
{
	// case : symbol table is empty
	if (ss.size() == 0 ) {
		pushScope();
		SymbolVal sval( loc, SymbolData() );
		cscope->insert( SymbolPair( skey, sval ) );
		// TODO Define and return SymbolLoc of NULL 
		return SymbolInfo( Healthy, SymbolLoc() ); 
	}
	
	// check conflict
	bool conflict = cscope->find( skey ) == cscope->end();
	if ( conflict ) {
		SymbolVal symbol = (*cscope)[skey];
		return SymbolInfo( Conflict, symbol.loc );
	}

	// check shadow
	bool shadow = false;
	SymbolCondition condition = Healthy;
	for ( auto scope = --cscope; cscope!=--ss.begin() ; scope-- ) {
		Scope::iterator symbol = scope->find( skey );
		if ( symbol != scope->end() ) {
			// shadow found
			SymbolInfo sinfo(Shadow, symbol->second.loc);
			SymbolVal sval( loc, SymbolData() );
			cscope->insert( SymbolPair( skey, sval ) );
			return sinfo;
		}
	}

	// no conflict/shadow occured
	SymbolVal sval( loc, SymbolData() );
	cscope->insert( SymbolPair ( skey, sval) );
	return SymbolInfo( Healthy, SymbolLoc() ); 
}


SymbolDetail SymbolTable::searchSymbol( SymbolKey skey, SymbolScope searchStart)
{
	// try to find the symbol from the current scope
	if (searchStart == ss.end() ) 
		// currentScope() == ss.end() ; symbol table is empty
		return SymbolDetail( ss.end(), SymbolData() );
	for ( auto scope = searchStart; scope!=--ss.begin() ; scope-- ) {
		auto symbol = scope->find( skey );
		if ( symbol != scope->end() ) {
			SymbolData data = symbol->second.data;
			return SymbolDetail( scope , data);
		}
	}

	// no such symbol
	return SymbolDetail( ss.end(), SymbolData() );
}

SymbolScope SymbolTable::currentScope()
{
	return (ss.begin() == --ss.end()) ? ss.end() : cscope ;
} 

void SymbolTable::pushScope()
{
	if (cscope==ss.end()) cscope = ss.begin();
	ss.insert(cscope, Scope());
	cscope--;
}

void SymbolTable::popScope()
{
	if (cscope==ss.end()) {
		std::cerr << "SymbolTable::popScope(): SymbolTable is empty." << std::endl;
	}
	else if (cscope==ss.begin()) {
		cscope = ss.end();	
	}
	else {
		cscope++;
	}
}

void SymbolTable::dumpTable( std::string filename )
{

	// Check if the file can be opened
	std::ofstream f( filename.c_str() );
	if( !f.good() ) {
		std::cerr << "<" << filename << ">" << " could not be opend." << std::endl;
		return;
	}

	f << "----Symbol Table------------------------------------" << std::endl;
	for( auto scope : ss ) {
		for( auto symbolpair : scope ) {
			f << symbolpair.first;
			f << std::endl;
		}
		f << "----------------------------------------------------" << std::endl;
	}

}
