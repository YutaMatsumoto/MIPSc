/*
 * FunctionType.h
 *
 *  Created on: Apr 1, 2013
 *      Author: njordan
 */

#ifndef FUNCTIONTYPE_H_
#define FUNCTIONTYPE_H_

#include "Type.h"

class FunctionType: public Type {
public:

	FunctionType();

	virtual ~FunctionType();

	std::vector< Type* > operands;

	Type* returnType;
};

#endif /* FUNCTIONTYPE_H_ */
