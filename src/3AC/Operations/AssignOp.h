/*
 * AssignOp.h
 *
 *  Created on: Apr 15, 2013
 *      Author: njordan
 */

#ifndef ASSIGNOP_H_
#define ASSIGNOP_H_

#include "Operation.h"

#include "AssignmentOperatorNode.h"

class AssignOp: public Operation {

public:

	inline AssignOp( Operand* destination , Operand* source , AssignmentOperatorNode::AssignmentOperatorType _type ) : Operation(destination , source , 0 ), type( _type )
	{

	}

	std::string to3AC()
	{

		return op1->getId() + " = " + op2->getId();

	}

	AssignmentOperatorNode::AssignmentOperatorType type;

};

#endif /* ASSIGNOP_H_ */
