/*
 * OP1.h
 *
 *  Created on: Apr 3, 2013
 *      Author: njordan
 */

#ifndef OP1_H_
#define OP1_H_

#include "Operation.h"

class OP1: public Operation
{

public:

	inline OP1( Operand* _first ) : first( _first )
	{

	}

	virtual ~OP1();

	inline virtual std::string to3AC()
	{

	}

protected:

	Operand* first;


};

#endif /* OP1_H_ */
