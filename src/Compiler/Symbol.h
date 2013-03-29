/*
 * Symbol.h
 *
 *  Created on: Mar 13, 2013
 *      Author: njordan
 */

#ifndef SYMBOL_H_
#define SYMBOL_H_

#include <string>
#include "SymbolLocation.h"

class Type;

class Symbol
{
public:

	std::string id;

	SymbolLocation location;
	
	Type* symbolType;

	Symbol(std::string s, int l, int c)
		: id(s), location(l,c)
	{}

	std::string getId()
	{
		return id;
	}

};

#endif /* SYMBOL_H_ */
