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

	FunctionType() 
		: Type(Function)
	{}

	void setReturnType(Type* rtype)
	{
		this->returnType = rtype;
	}

	void addOperand(Type* type)
	{
		operands.push_back(type);
	}

	virtual ~FunctionType();

	std::vector< Type* > operands;

	Type* returnType;

	virtual int sizeInBytes();

};

#endif /* FUNCTIONTYPE_H_ */
