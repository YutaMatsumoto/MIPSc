/*
 * Add.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef ADD_H_
#define ADD_H_

#include "OP3.h"
#include "Operation.h"

class Add: public OP3 {

	inline Add( Operand* result , Operand* first , Operand* second ) : OP3( result, first, second )
	{

	}

	std::string toString()
	{

		return std::string("");

	}

};

#endif /* ADD_H_ */
