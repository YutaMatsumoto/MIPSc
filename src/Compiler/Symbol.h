/*
 * Symbol.h
 *
 *  Created on: Mar 13, 2013
 *      Author: njordan
 */

#include <string>
#include "SymbolLocation.h"
#include "Type.h"
#include "TypeQualifierNode.h"

#ifndef SYMBOL_H_
#define SYMBOL_H_

typedef int address;

class Type;

class Symbol
{

public:

	enum TACOperandType
	{
		LOCAL = 0,
		GLOB = 1,
		ITEMP = 2,
		FTEMP = 3,
		CONS = 4,
		FCONS = 5,
		INDR = 6,
		LABEL = 7,
		REFAR = 8,
		VALARG = 9,
		STRING = 10,
		NONE = 11
	};

	std::string id;

	SymbolLocation location;
	
	Type* symbolType = 0;

	TACOperandType operandType = NONE;

	address addr = 0x0;

	//For 3AC
	TypeQualInfo tQualInfo;

	Symbol() 
	{}

	/*Symbol(std::string id, SymbolLocation location, Type* symbolType )
		: id(id), location(location), symbolType(symbolType)
	{}*/

	Symbol(std::string id, SymbolLocation location, Type* symbolType , TACOperandType _operandType )
		: id(id), location(location), symbolType(symbolType), operandType(_operandType)
	{}

	Symbol(std::string s, SymbolLocation location)
			: id(s), location(location)
		{}

	Symbol(std::string s, int l, int c)
		: id(s), location(l,c)
	{}

	std::string getId()
	{
		return id;
	}

	Type* getType()
	{
		return symbolType;
	}

	std::string getValueAsString()
	{
		//return symbolType->getType()->
		//return "implement getValueAsString";
		return "[a value]";
	}

	std::string getTypeAsString()
	{
		// return "";
		return symbolType->getTypeAsString();
	}


	void setTypeQualInfo(TypeQualInfo value)
	{
		tQualInfo = value;

		//return std::string();

	}

	std::string getTacTypeAsString()
	{

		switch( operandType )
		{

		case LOCAL:
			return std::string("LOCAL");
		case GLOB:
			return std::string("GLOB");
		case ITEMP:
			return std::string("ITEMP");
		case FTEMP:
			return std::string("FTEMP");
		case CONS:
			return std::string("CONS");
		case FCONS:
			return std::string("FCONS");
		case INDR:
			return std::string("INDR");
		case LABEL:
			return std::string("LABEL");
		case REFAR:
			return std::string("REFAR");
		case VALARG:
			return std::string("VALARG");
		case STRING:
			return std::string("STRING");
		default:
			return std::string("NONE");

		}

	}

};

inline std::ostream& operator<< (std::ostream &out, Symbol& sym)
{
	std::cout << sym.getId() << " : " << sym.getValueAsString();
	return out;
}


#endif /* SYMBOL_H_ */
