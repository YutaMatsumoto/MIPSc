/*
 * GetAddressOp.h
 *
 *  Created on: Apr 15, 2013
 *      Author: njordan
 */

#ifndef GETADDRESSOP_H_
#define GETADDRESSOP_H_

#include "Operation.h"

class GetAddressOp: public Operation {

public:

	inline GetAddressOp( Operand* destination , Operand* source ) : Operation(destination , source , 0 )
	{

	}

	std::string to3AC()
	{

		return "ADDR of " + op2->getId() + " -> " + op1->getId();

	}

};

#endif /* GETADDRESSOP_H_ */
