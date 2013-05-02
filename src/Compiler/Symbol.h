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

class Symbol
{

public:

	std::string id;

	SymbolLocation location;
	
	Type* symbolType;

	TypeQualInfo tQualInfo;

	Symbol() 
	{}

	Symbol(std::string id, SymbolLocation location, Type* symbolType )
		: id(id), location(location), symbolType(symbolType)
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
	}

};

inline std::ostream& operator<< (std::ostream &out, Symbol& sym)
{
	std::cout << sym.getId() << " : " << sym.getValueAsString();
	return out;
}


#endif /* SYMBOL_H_ */
