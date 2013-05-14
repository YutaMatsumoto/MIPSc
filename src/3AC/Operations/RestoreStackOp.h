/*
 * RestoreStackOp.h
 *
 *  Created on: Apr 26, 2013
 *      Author: njordan
 */

#ifndef RESTORESTACKOP_H_
#define RESTORESTACKOP_H_

#include "Operation.h"

class RestoreStackOp: public Operation {

public:

	inline RestoreStackOp( Operand* function  ) : Operation(function,0,0)
	{

	}

	std::string to3AC()
	{

		return std::string("RESTORE_STACK FROM ") + op1->getId();

	}


};

#endif /* RESTORESTACKOP_H_ */
