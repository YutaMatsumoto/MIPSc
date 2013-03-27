/*
 * Symbol.h
 *
 *  Created on: Mar 13, 2013
 *      Author: njordan
 */

#ifndef SYMBOL_H_
#define SYMBOL_H_

#include <string>
#include "../Types/Type.h"
#include "SymbolLocation.h"

class Symbol
{
public:

	std::string id;

	SymbolLocation location;
	
	Type* symbolType;

};

#endif /* SYMBOL_H_ */
