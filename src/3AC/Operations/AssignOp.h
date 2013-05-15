/*
 * AssignOp.h
 *
 *  Created on: Apr 15, 2013
 *      Author: njordan
 */

#ifndef ASSIGNOP_H_
#define ASSIGNOP_H_

#include "Operation.h"

#include "BuiltinType.h"

#include <boost/format.hpp>
#include "AssignmentOperatorNode.h"

class AssignOp: public Operation {

public:

	inline AssignOp( Operand* destination , Operand* source , AssignmentOperatorNode::AssignmentOperatorType _type ) : Operation(destination , source , 0 ), type( _type )
	{

	}

	virtual void produceMips();

	std::string to3AC()
	{

		return ( boost::format( "%-15s%-15s%-15s" ) % std::string( "LOADI ") % (op1->getId() + ":" + op1->getTacTypeAsString()) % (op2->getId()+ ":" + op2->getTacTypeAsString())).str();
		//return "LOADI " + op1->getId() + ":" + op1->getTacTypeAsString() + " " + op2->getId() + ":" + op2->getTacTypeAsString();

	}

	AssignmentOperatorNode::AssignmentOperatorType type;

};

#endif /* ASSIGNOP_H_ */
