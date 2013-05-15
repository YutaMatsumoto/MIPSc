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

#include <boost/format.hpp>
class ConditionalStoreOp: public Operation {



public:

	inline ConditionalStoreOp( Operand* destination , Operand* first , Operand* second , RelationalExpressionNode::RelationalExpressionType _type )
		: Operation( destination, first, second ), type(_type)
	{

	}

	virtual void produceMips();

	std::string to3AC()
	{

		switch(type)
		{
		case RelationalExpressionNode::Greater:
			return ( boost::format( "%-15s%-15s%-15s" ) % std::string( "SETGT ") % (op1->getId() + ":" + op1->getTacTypeAsString()) % (op2->getId()+ ":" + op2->getTacTypeAsString())).str();
			break;
		case RelationalExpressionNode::Less:
			return ( boost::format( "%-15s%-15s%-15s" ) % std::string( "SETLT ") % (op1->getId() + ":" + op1->getTacTypeAsString()) % (op2->getId()+ ":" + op2->getTacTypeAsString())).str();
			break;
		case RelationalExpressionNode::GreaterEqual:
			return ( boost::format( "%-15s%-15s%-15s" ) % std::string( "SETGE ") % (op1->getId() + ":" + op1->getTacTypeAsString()) % (op2->getId()+ ":" + op2->getTacTypeAsString())).str();
			break;
		case RelationalExpressionNode::LessEqual:
			return ( boost::format( "%-15s%-15s%-15s" ) % std::string( "SETLE ") % (op1->getId() + ":" + op1->getTacTypeAsString()) % (op2->getId()+ ":" + op2->getTacTypeAsString())).str();
			break;
		}


		//return ( boost::format( "%-15s%-15s%-15s" ) % std::string( "SET0GT ") % (op1->getId() + ":" + op1->getTacTypeAsString()) % (op2->getId()+ ":" + op2->getTacTypeAsString())).str();
		//return "SET " + op1->getId() + ":" + op1->getTacTypeAsString() + " TO 1 IF " + op2->getId() + ":" + op2->getTacTypeAsString() + compareType + op3->getId() + ":" + op3->getTacTypeAsString();

	}

	RelationalExpressionNode::RelationalExpressionType type;

	std::string compareType;

};

#endif /* CONDITIONALSTOREOP_H_ */
