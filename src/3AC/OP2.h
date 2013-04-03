/*
 * OP2.h
 *
 *  Created on: Apr 3, 2013
 *      Author: njordan
 */

#ifndef OP2_H_
#define OP2_H_

#include "Operation.h"

class OP2: public Operation
{

public:

	inline OP2( Operand* _first, Operand* _second ) : first( _first ) , second( _second )
	{

	}

	virtual ~OP2();

	virtual std::string to3AC()
	{

	}

protected:

	Operand* first;

	Operand* second;


};

#endif /* OP2_H_ */
