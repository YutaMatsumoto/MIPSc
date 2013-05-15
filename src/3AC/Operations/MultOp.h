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

			return std::string("MULT ") + op1->getId()+ ":" + op1->getTacTypeAsString() + " " + op2->getId()+ ":" + op2->getTacTypeAsString() + " " + op3->getId()+ ":" + op3->getTacTypeAsString();

		if( type == MultiplicativeExpressionNode::Divide )

			return std::string("MULT ") + op1->getId()+ ":" + op1->getTacTypeAsString() + " " + op2->getId()+ ":" + op2->getTacTypeAsString() + " " + op3->getId()+ ":" + op3->getTacTypeAsString();

		else

			return std::string("MULT ") + op1->getId()+ ":" + op1->getTacTypeAsString() + " " + op2->getId()+ ":" + op2->getTacTypeAsString() + " " + op3->getId()+ ":" + op3->getTacTypeAsString();

	}

	MultiplicativeExpressionNode::MultiplicativeExpressionType type;

};

#endif /* MULTOP_H_ */
