/*
 * Operation.h
 *
 *  Created on: Apr 3, 2013
 *      Author: njordan
 */

#ifndef OPERATION_H_
#define OPERATION_H_

#include "DescriptorTable.h"
#include "MipsCode.h"

#include <string>
#include "Symbol.h"

typedef Symbol Operand;

class Operation
{

public:

	virtual ~Operation();

	virtual std::string to3AC() = 0;

	// TODO
	virtual void produceMips();

	virtual std::vector< std::string > toMIPS();

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

	Operand* op1 = 0;

	Operand* op2 = 0;

	Operand* op3 = 0;

protected:

	std::string name;



	Operation( Operand* , Operand* , Operand* );

};

#endif /* OPERATION_H_ */
