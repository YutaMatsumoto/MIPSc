/*
 * MultOp.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef MULTOP_H_
#define MULTOP_H_

#include "Operation.h"
#include "MultiplicativeExpressionNode.h"

class MultOp: public Operation {

public:

	inline MultOp( Operand* result , Operand* first , Operand* second, MultiplicativeExpressionNode::MultiplicativeExpressionType _type )
		: Operation( result, first, second ), type(_type)
	{

	}

	std::string to3AC()
	{

		if( type == MultiplicativeExpressionNode::Multiply )

			return op1->getId() + " = " + op2->getId() + " * " + op3->getId();

		if( type == MultiplicativeExpressionNode::Divide )

			return op1->getId() + " = " + op2->getId() + " / " + op3->getId();

		else

			return op1->getId() + " = " + op2->getId() + " % " + op3->getId();

	}

	MultiplicativeExpressionNode::MultiplicativeExpressionType type;

};

#endif /* MULTOP_H_ */
