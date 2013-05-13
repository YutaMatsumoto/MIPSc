/*
 * ReturnOp.h
 *
 *  Created on: Apr 26, 2013
 *      Author: njordan
 */

#ifndef RETURNOP_H_
#define RETURNOP_H_

#include "Operation.h"

class ReturnOp: public Operation {

public:

	inline ReturnOp( Operand* returnValue ) : Operation(returnValue,0,0)
	{

	}

	std::string to3AC()
	{

		return std::string("RETURN ") + op1->getId();

	}


};

#endif /* RETURNOP_H_ */
