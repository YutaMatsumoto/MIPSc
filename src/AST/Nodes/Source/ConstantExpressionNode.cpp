/*
 * ConstantExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "ConstantExpressionNode.h"

ConstantExpressionNode::ConstantExpressionNode( ConditionalExpressionNode* _conditionalExpression ) : conditionalExpression( _conditionalExpression )
{

}


ASTData* ConstantExpressionNode::toOperations()
{
	return conditionalExpression->toOperations();
}

std::string ConstantExpressionNode::getNodeTypeAsString()
{

	return std::string( "constant expression" );

}


ConstantExpressionNode::~ConstantExpressionNode()
{

}
