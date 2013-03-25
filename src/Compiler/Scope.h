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
#include "../Types/Type.h"

typedef std::string SymbolName;

typedef std::string TypeName;

class Scope {
public:
	Scope();
	virtual ~Scope();

	std::map< SymbolName , Symbol* > symbolMap;

	std::map< TypeName , Type* > typeMap;

};

#endif /* SCOPE_H_ */
