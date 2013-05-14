/*
 * Scope.h
 *
 *  Created on: Mar 25, 2013
 *      Author: njordan
 */

#ifndef SCOPE_H_
#define SCOPE_H_

#include <map>
#include <string>
#include "Symbol.h"
#include "Type.h"

typedef std::string SymbolName;

typedef std::string TypeName;

class Scope {
public:

	Scope();

	virtual ~Scope();

	std::map< SymbolName , Symbol* > symbolMap;

	std::map< TypeName , Type* > typeMap;

	//For a function, this helps calculate the address of each symbol on the stack
	//unsigned int offsetCounter = 0;

};

#endif /* SCOPE_H_ */
