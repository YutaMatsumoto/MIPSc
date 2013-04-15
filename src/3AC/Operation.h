/*
 * Operation.h
 *
 *  Created on: Apr 3, 2013
 *      Author: njordan
 */

#ifndef OPERATION_H_
#define OPERATION_H_

#include <string>
#include "Symbol.h"

typedef Symbol Operand;

class Operation
{

public:

	virtual ~Operation();

	virtual std::string to3AC() = 0;

	std::string getName() const {
		return name;
	}

	Operand* getOp1() const {
		return op1;
	}

	Operand* getOp2() const {
		return op2;
	}

	Operand* getOp3() const {
		return op3;
	}

protected:

	std::string name;

	Operand* op1;

	Operand* op2;

	Operand* op3;

	Operation( Operand* , Operand* , Operand* );

};

#endif /* OPERATION_H_ */
