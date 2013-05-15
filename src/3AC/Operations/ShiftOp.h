/*
 * Add.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef SHIFTOP_H_
#define SHIFTOP_H_

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

			return op1->getId() + " = " + op2->getId() + " << " + op3->getId();

		else

			return op1->getId() + " = " + op2->getId() + " >> " + op3->getId();

	}

	ShiftExpressionNode::ShiftExpressionType type;

};

#endif /* ADDOP_H_ */
