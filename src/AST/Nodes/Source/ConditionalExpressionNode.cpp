/*
 * ConditionalExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "ConditionalExpressionNode.h"

ConditionalExpressionNode::ConditionalExpressionNode( LogicalOrExpressionNode* _logicalOrExpression ) : logicalOrExpression( _logicalOrExpression )
{
	nodeData = toOperations();
}

ConditionalExpressionNode::ConditionalExpressionNode(
		LogicalOrExpressionNode* _logicalOrExpression,
		ExpressionNode* _expression,
		ConditionalExpressionNode* _conditionalExpression
	) : logicalOrExpression( _logicalOrExpression ), expression(_expression), conditionalExpression(_conditionalExpression)
{
	nodeData = toOperations();
}


ASTData*ConditionalExpressionNode::toOperations()
{
	ASTData* data = new ASTData();

	if( expression == 0 )

		return logicalOrExpression->nodeData;

	return data;
}

std::string ConditionalExpressionNode::getNodeTypeAsString()
{

	return std::string( "conditional expression" );

}

ConditionalExpressionNode::~ConditionalExpressionNode()
{

}


