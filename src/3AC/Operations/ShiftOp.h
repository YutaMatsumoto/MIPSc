/*
 * Add.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef ADDOP_H_
#define ADDOP_H_

#include "Operation.h"
#include "ShiftExpressionNode.h"

class ShiftOp: public Operation {

public:

	inline ShiftOp( Operand* result , Operand* first , Operand* second , ShiftExpressionNode::ShiftExpressionType _type)
		: Operation( result, first, second ), type( _type )
	{

	}

	std::string to3AC()
	{
		if( type == ShiftExpressionNode::Left )

			return op1->getId()+ ":" + op1->getTacTypeAsString() + " = " + op2->getId()+ ":" + op2->getTacTypeAsString() + " << " + op3->getId()+ ":" + op3->getTacTypeAsString();

		else

			return op1->getId()+ ":" + op1->getTacTypeAsString() + " = " + op2->getId()+ ":" + op2->getTacTypeAsString() + " >> " + op3->getId()+ ":" + op3->getTacTypeAsString();

	}

	ShiftExpressionNode::ShiftExpressionType type;

};

#endif /* ADDOP_H_ */
