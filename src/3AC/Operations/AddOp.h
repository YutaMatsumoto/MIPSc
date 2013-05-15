/*
 * Add.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef ADDOP_H_
#define ADDOP_H_

#include "Operation.h"

#include "AdditiveExpressionNode.h"

#include "MipsVariable.h"
#include "MipsCode.h"
#include "DescriptorTable.h"

class AddOp: public Operation {

public:

	inline AddOp( Operand* result , Operand* first , Operand* second , AdditiveExpressionNode::AdditiveExpressionType _type )
		: Operation( result, first, second ), type(_type)
	{

	}

	virtual void produceMips();

	std::string to3AC()
	{

		if( type == AdditiveExpressionNode::Add )

			return "ADD " + op1->getId() + ":" + op1->getTacTypeAsString() + " " + op2->getId()+ ":" + op2->getTacTypeAsString() + " " + op3->getId()+ ":" + op3->getTacTypeAsString();

		else

			return "SUB " + op1->getId() + " " + op2->getId() + " " + op3->getId();

	}

	AdditiveExpressionNode::AdditiveExpressionType type;

};

#endif /* ADDOP_H_ */
