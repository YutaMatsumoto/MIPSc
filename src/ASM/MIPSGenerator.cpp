/*
 * MIPSGenerator.cpp
 *
 *  Created on: Apr 3, 2013
 *      Author: njordan
 */

#include "MIPSGenerator.h"
#include "Symbol.h"
#include "FunctionType.h"
#include "BuiltinType.h"
#include "ArrayType.h"

MIPSGenerator::~MIPSGenerator() {
	// TODO Auto-generated destructor stub
}

MIPSGenerator::MIPSGenerator()
{

}

void MIPSGenerator::generateMIPS()
{

	mipsData.push_back( std::string("spill: .space 256") );

	//Data First
	for( Symbol* i : functions )
	{

		FunctionType* f = dynamic_cast<FunctionType*>( i->symbolType );

		mipsData.push_back( std::string("#") + i->getId() );

		for( auto j : f->functionScope.symbolMap )
		{

			Symbol* k = j.second;

			BuiltinType* b = dynamic_cast<BuiltinType*>( k->symbolType );

			ArrayType* t = dynamic_cast<ArrayType*>( k->symbolType );

			FunctionType* ff = dynamic_cast<FunctionType*>( k->symbolType );

			if( ff )

				continue;

			if( b )
			{

				std::string l = k->getId() + ":" + " .word 0";

				mipsData.push_back( l );

			}

			if( t )
			{

				int size = t->sizes.at(0) * 4;

				std::string l = k->getId() + ":" + " .space " + std::to_string( size );

				mipsData.push_back( l );

			}

		}

		std::string l = f->returnSymbol->getId() + ":" + " .word 0";

		mipsData.push_back( l );

	}

	for( Operation* i : *tac )
	{

		std::vector< std::string > result = i->toMIPS();

		mipsText.insert( mipsText.end() , result.begin() , result.end() );

	}

}

void MIPSGenerator::addFunction( Symbol* func )
{

	functions.push_back( func );

}


void MIPSGenerator::setTAC( std::vector< Operation* >* _tac )
{

	tac = _tac;

}

void MIPSGenerator::writeMIPS( std::ostream& o )
{

	for( auto i : mipsData )

		o << i << std::endl;

}
