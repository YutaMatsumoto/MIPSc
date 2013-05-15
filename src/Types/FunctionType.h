/*
 * FunctionType.h
 *
 *  Created on: Apr 1, 2013
 *      Author: njordan
 */

#ifndef FUNCTIONTYPE_H_
#define FUNCTIONTYPE_H_

#include "Type.h"
#include "Scope.h"

class FunctionType: public Type {
public:

	FunctionType() 
		: Type(Function)
	{}

	virtual ~FunctionType();

	std::vector< Symbol* > parameters;

	Symbol* returnSymbol = 0;

	virtual int sizeInBytes();

	unsigned int stackFrameSize = -1;

	int labelId = -1;

	Scope functionScope;

};

#endif /* FUNCTIONTYPE_H_ */
