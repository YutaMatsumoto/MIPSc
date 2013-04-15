/*
 * Add.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef ADDOP_H_
#define ADDOP_H_

#include "Operation.h"

class AddOp: public Operation {

public:

	inline AddOp( Operand* result , Operand* first , Operand* second ) : Operation( result, first, second )
	{

	}

	std::string to3AC()
	{

		return op1->getId() + " = " + op2->getId() + " + " + op3->getId();

	}

};

#endif /* ADDOP_H_ */
