/*
 * LoadOp.h
 *
 *  Created on: Apr 15, 2013
 *      Author: njordan
 */

#ifndef LOADOP_H_
#define LOADOP_H_

#include "Operation.h"

class LoadOp: public Operation {

public:

	inline LoadOp( Operand* destination , Operand* source ) : Operation(destination , source , 0 )
	{

	}

	std::string to3AC()
	{

		return "LOAD " + op2->getId() + " into " + op1->getId();

	}


};

#endif /* LOADOP_H_ */
