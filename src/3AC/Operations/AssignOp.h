/*
 * AssignOp.h
 *
 *  Created on: Apr 15, 2013
 *      Author: njordan
 */

#ifndef ASSIGNOP_H_
#define ASSIGNOP_H_

#include "Operation.h"

class AssignOp: public Operation {

public:

	inline AssignOp( Operand* destination , Operand* source ) : Operation(destination , source , 0 )
	{

	}

	std::string to3AC()
	{

		return op1->getId() + " = " + op2->getId();

	}

};

#endif /* ASSIGNOP_H_ */
