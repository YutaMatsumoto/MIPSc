/*
 * LogicalAndExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "LogicalAndExpressionNode.h"

LogicalAndExpressionNode::LogicalAndExpressionNode( InclusiveOrExpressionNode* _inclusiveOrExpressionNode ) : inclusiveOrExpressionNode( _inclusiveOrExpressionNode )
{

}

LogicalAndExpressionNode::LogicalAndExpressionNode( LogicalAndExpressionNode* _logicalAndExpression,
		InclusiveOrExpressionNode* _inclusiveOrExpressionNode
		)
	: logicalAndExpression( _logicalAndExpression ), inclusiveOrExpressionNode( _inclusiveOrExpressionNode )
{

}

std::vector< Operation* >* LogicalAndExpressionNode::toOperations()
{
	std::vector< Operation* >* operations;

	return operations;
}

std::string LogicalAndExpressionNode::getNodeTypeAsString()
{

	return std::string( "logical AND expression" );

}

LogicalAndExpressionNode::~LogicalAndExpressionNode() {}

