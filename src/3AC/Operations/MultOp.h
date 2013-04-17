/*
 * MultOp.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef MULTOP_H_
#define MULTOP_H_

#include "Operation.h"

class MultOp: public Operation {

public:

	inline MultOp( Operand* result , Operand* first , Operand* second ) : Operation( result, first, second )
	{

	}

	std::string to3AC()
	{

		return op1->getId() + " = " + op2->getId() + " * " + op3->getId();

	}

};

#endif /* MULTOP_H_ */
