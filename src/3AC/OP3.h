/*
 * OP3.h
 *
 *  Created on: Apr 3, 2013
 *      Author: njordan
 */

#ifndef OP3_H_
#define OP3_H_

#include "Operation.h"

class OP3: public Operation
{

public:

	inline OP3( Operand* _first , Operand* _second, Operand* _third ) : first( _first ) , second( _second ), third( _third )
	{

	}

	virtual ~OP3();

	virtual std::string toString() - 0;

protected:

	Operand* first;

	Operand* second;

	Operand* third;

};

#endif /* OP3_H_ */
