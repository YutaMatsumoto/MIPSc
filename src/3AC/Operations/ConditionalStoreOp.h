/*
 * Add.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef CONDITIONALSTOREOP_H_
#define CONDITIONALSTOREOP_H_

#include "Operation.h"
#include "RelationalExpressionNode.h"

#include "AdditiveExpressionNode.h"

class ConditionalStoreOp: public Operation {



public:

	inline ConditionalStoreOp( Operand* destination , Operand* first , Operand* second , RelationalExpressionNode::RelationalExpressionType _type )
		: Operation( destination, first, second ), type(_type)
	{

	}

	std::string to3AC()
	{

		std::string compareType = "";

		switch(type)
		{
		case RelationalExpressionNode::Greater:
			compareType = " > ";
			break;
		case RelationalExpressionNode::Less:
			compareType = " < ";
			break;
		case RelationalExpressionNode::GreaterEqual:
			compareType = " >= ";
			break;
		case RelationalExpressionNode::LessEqual:
			compareType = " <= ";
			break;
		}

		return "SET " + op1->getId() + " TO 1 IF " + op2->getId() + compareType + op3->getId();

	}

	RelationalExpressionNode::RelationalExpressionType type;

};

#endif /* CONDITIONALSTOREOP_H_ */
