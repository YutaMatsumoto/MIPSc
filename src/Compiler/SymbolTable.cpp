/*
 * SymbolTable.cpp
 *
 *  Created on: Mar 25, 2013
 *      Author: njordan
 */

#include "SymbolTable.h"
#include <map>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include "ArrayType.h"

bool SymbolTable::isGlobalScope()
{

	return ( scopeStack.size() == 1) ? true : false;
}

SymbolTableInfo SymbolTable::getSymbolInfo(std::string symbolName, bool currentScopeOnly)
{

	SymbolTableInfo info;

	info.status = NotFound;

	Symbol* s;

	for( Scope i : scopeStack )
	{

		try
		{

			s = i.symbolMap.at( symbolName );

		}

		catch( std::out_of_range& e )
		{

			continue;

		}

		if( info.symbol == 0 )
		{

			info.status = Found;

			info.symbol = s;

		}
		else
		{

			info.status = Shadowing;

			info.shadowList.push_front( s );

		}

	}

	return info;

}

void SymbolTable::insertSymbol(Symbol* symbol)
{

	bool conflict = false;

	Symbol* s = 0;

	try
	{

		s = scopeStack.front().symbolMap.at( symbol->getId() );

		conflict = true;

	}

	catch( std::out_of_range& e ) { }

	if( conflict )
	{

		conflictError( symbol , s );

	}

	scopeStack.front().symbolMap.insert(
			std::pair< std::string , Symbol* >( symbol->getId() , symbol ) );

	//For calculating function stack size
	functionScope.symbolMap.insert(
				std::pair< std::string , Symbol* >( symbol->getId() , symbol ) );

}

void SymbolTable::conflictError( Symbol* newSymbol , Symbol* previousSymbol )
{

	// TODO needs to show the two lines where each symbol is declared
	std::cerr << "Symbol '" << newSymbol->getId() << "' already declared here " << std::endl;

}

void SymbolTable::insertType(Type* type) {


	// TODO implement this
	scopeStack.front().typeMap.insert(
				std::pair< std::string , Type* >( type->getId() , type ) );
}

SymbolTable::SymbolTable()
{

	Scope s;

	scopeStack.push_front( s );

}

SymbolTable::~SymbolTable()
{


}

void SymbolTable::dumpTable( std::string filename )
{

	std::ofstream o;

	o.open( filename.c_str() );

	if( ! o.good() )
	{

		std::cerr << "Can't open symboltable file" << std::endl;

		exit( 1 );

	}

	for( auto i : scopeStack )
	{

		o << "---------------------------------------------------------------" << std::endl;

		for( auto& j : i.symbolMap )
		{

			Symbol* sym = j.second;
			Type* t = sym->getType();

			// ugly cast
			if (t && t->getType()==Type::Array) {
				t = dynamic_cast<ArrayType*>( t );
			}
			std::string typeStr = ( (t) ? t->toString() : "bad type" );

			// print
			o << sym->getId() 
				<< " : " 
				<< typeStr
				<< std::endl;
		}

	}

	o << "---------------------------------------------------------------" << std::endl;

}

void SymbolTable::beginScope( )
{

	std::cout << "---- Beginning Scope ----" << std::endl;

	Scope s;

	scopeStack.push_front( s );

}

void SymbolTable::endScope()
{
	std::cout << "---- Ending Scope ----" << std::endl;

	scopeStack.pop_front();

}

void SymbolTable::clearFunctionScope()
{

	functionScope.symbolMap.clear();

}

