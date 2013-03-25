/*
 * SymbolTableInfo.h
 *
 *  Created on: Mar 25, 2013
 *      Author: njordan
 */

#ifndef SYMBOLTABLEINFO_H_
#define SYMBOLTABLEINFO_H_

#include <list>
#include "Symbol.h"

enum SymbolStatus
{

	Found,
	NotFound,
	Shadowing

};

class SymbolTableInfo {
public:
	SymbolTableInfo();
	virtual ~SymbolTableInfo();

	Symbol* symbol;

	Symbol* conflict;

	SymbolStatus status;

	std::list< Symbol* > shadowList;

};

#endif /* SYMBOLTABLEINFO_H_ */
