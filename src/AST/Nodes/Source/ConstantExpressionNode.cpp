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


std::vector< Operation* >* ConstantExpressionNode::toOperations()
{
	std::vector< Operation* >* operations;

	return operations;
}

std::string ConstantExpressionNode::getNodeTypeAsString()
{

	return std::string( "constant expression" );

}


ConstantExpressionNode::~ConstantExpressionNode()
{

}
