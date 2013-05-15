/*
 * StoreOp.h
 *
 *  Created on: Apr 15, 2013
 *      Author: njordan
 */

#ifndef STOREOP_H_
#define STOREOP_H_

#include "Operation.h"

#include <boost/format.hpp>
class StoreOp: public Operation {

public:

	inline StoreOp( Operand* destination , Operand* source ) : Operation(destination , source , 0 )
	{

	}

	std::string to3AC()
	{
		return ( boost::format( "%-15s%-15s%-15s" ) % std::string( "STORE") % (op1->getId() + ":" + op1->getTacTypeAsString()) % (op2->getId()+ ":" + op2->getTacTypeAsString())).str();
		//return "STORE @" + op1->getId() + ":" + op1->getTacTypeAsString() + " " + op2->getId() + ":" + op2->getTacTypeAsString();

	}


};

#endif /* STOREOP_H_ */
