/*
 * CallOp.h
 *
 *  Created on: Apr 26, 2013
 *      Author: njordan
 */

#ifndef CALLOP_H_
#define CALLOP_H_

#include "Operation.h"

class CallOp: public Operation {

public:

	inline CallOp( Operand* function  ) : Operation(function,0,0)
	{

	}

	std::string to3AC()
	{

		return std::string("CALL @") + op1->getId() + ":" + op1->getTacTypeAsString();

	}


};

#endif /* CALLOP_H_ */
