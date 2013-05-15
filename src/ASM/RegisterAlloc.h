/*
 * RegisterAlloc.h
 *
 *  Created on: May 15, 2013
 *      Author: njordan
 */

#ifndef REGISTERALLOC_H_
#define REGISTERALLOC_H_

#include "BuiltinType.h"
#include "Type.h"
#include <stdexcept>

class RegisterAlloc {
public:

	enum Reg
	{
		$t1 = 1,
		$t2 = 2,
		$t3 = 3,
		$t4 = 4,
		$t5 = 5,
		$t6 = 6,
		$t7 = 7,
	};

	static RegisterAlloc& getInstance()
	{

		static RegisterAlloc instance;
		return instance;

	}

	Reg getRegister( Symbol* sym , std::vector< std::string >& code )
	{

		try
		{

			Reg i = registerMap.at( sym );

			return i;

		}
		catch(std::exception& e)
		{

		}

		try
		{

			auto i = inverseRegisterMap.at( currentRegister );

			spill( currentRegister );

			try
			{

				int spillLocation = spillMap.at( sym );

				spillLocation *= 4;

				//create a new temporary name
				std::string tempName = std::string("t") + std::to_string( IdTracker::getInstance()->getId() );

				//create a new temporary for our result
				Symbol* temporary = new Symbol( tempName , *new SymbolLocation() , new BuiltinType( Type::Int ) , Type::ITEMP );

				tempName = std::string("t") + std::to_string( IdTracker::getInstance()->getId() );

				//create a new temporary for our result
				Symbol* temporary2 = new Symbol( tempName , *new SymbolLocation() , new BuiltinType( Type::Int ) , Type::ITEMP );

				nextRegister();

				spill( currentRegister );

				Reg i = getRegister( temporary , code );

				code.push_back( std::string("li $t") + std::to_string( i ) + std::string(",") + std::to_string( spillLocation ) );

				nextRegister();

				spill( currentRegister );

				Reg j = getRegister( temporary2 , code );

				code.push_back( std::string("lw $t") + std::to_string( j ) + std::string(", spill($t") + std::to_string( i ) );

				return currentRegister;

			}
			catch(std::exception& e)
			{

			}

			return currentRegister++;

		}
		catch(std::exception& e)
		{

		}


	}

	Reg currentRegister = $t1;

	std::map< Symbol* , int > spillMap;

	std::map< Symbol* , Reg > registerMap;

	std::map< Reg , Symbol* > inverseRegisterMap;

	//64 spill vacancies by default
	bool spillVacancies[64]

private:

	RegisterAlloc()
	{

		for( int i = 0 ; i < 64 ; i++ )

			spillVacancies[ i ] = true;

	}

	void spill( Reg r )
	{

		Symbol* i = inverseRegisterMap.at( currentRegister );

		int spot = findVacancy();

		spillMap.insert( std::pair< Symbol* , int >( i , spot ) );

	}

	int findVacancy()
	{

		for( int i = 0 ; i < 64 ; i++ )

			if( spillVacancies[ i ] )

					return i;

		std::cerr << "Couldn't find spill vacancy!" << std::endl;

		exit(1);
	}

	void nextRegister()
	{

		currentRegister = (currentRegister + 1) % 7;

	}

};

#endif /* REGISTERALLOC_H_ */
