/*
 * ExclusiveOrExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "ExclusiveOrExpressionNode.h"

ExclusiveOrExpressionNode::ExclusiveOrExpressionNode(AndExpressionNode* _andExpression) :
		andExpression(_andExpression)
{
	nodeData = toOperations();
}

ExclusiveOrExpressionNode::ExclusiveOrExpressionNode(
		ExclusiveOrExpressionNode* _exclusiveOrExpression,
		AndExpressionNode* _andExpression) :
		exclusiveOrExpression(_exclusiveOrExpression), andExpression(
				_andExpression)
{
	nodeData = toOperations();
}

ASTData* ExclusiveOrExpressionNode::toOperations()
{

	ASTData* data = new ASTData();

	if( exclusiveOrExpression == 0 )

		return andExpression->nodeData;

	return data;
}

std::string ExclusiveOrExpressionNode::getNodeTypeAsString()
{

	return std::string("exclusive OR expression");

}


