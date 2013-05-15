/*
 * GetAddressOp.h
 *
 *  Created on: Apr 15, 2013
 *      Author: njordan
 */

#ifndef GETADDRESSOP_H_
#define GETADDRESSOP_H_

#include "Operation.h"

#include "BuiltinType.h"

#include <boost/format.hpp>
class GetAddressOp: public Operation {

public:

	inline GetAddressOp( Operand* destination , Operand* source ) : Operation(destination , source , 0 )
	{

	}

	virtual void produceMips();

	std::string to3AC()
	{

		return ( boost::format( "%-15s%-15s%-15s" ) % std::string( "LOADADDR") % (op1->getId() + ":" + op1->getTacTypeAsString()) % (op2->getId()+ ":" + op2->getTacTypeAsString())).str();
		//return "LOADA " + op1->getId() + ":" + op1->getTacTypeAsString() + " " + op2->getId() + ":" + op2->getTacTypeAsString();

	}

};

#endif /* GETADDRESSOP_H_ */
