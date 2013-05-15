/*
 * LoadOp.h
 *
 *  Created on: Apr 15, 2013
 *      Author: njordan
 */

#ifndef LOADOP_H_
#define LOADOP_H_

#include "Operation.h"

#include <boost/format.hpp>
class LoadOp: public Operation {

public:

	inline LoadOp( Operand* destination , Operand* source ) : Operation(destination , source , 0 )
	{

	}

	std::string to3AC()
	{

		return ( boost::format( "%-15s%-15s%-15s" ) % std::string( "LOAD") % (op1->getId() + ":" + op1->getTacTypeAsString()) % (op2->getId()+ ":" + op2->getTacTypeAsString())).str();
		//turn "LOAD " + op1->getId() + ":" + op1->getTacTypeAsString() + " @" + op2->getId() + ":" + op2->getTacTypeAsString();

	}


};

#endif /* LOADOP_H_ */
