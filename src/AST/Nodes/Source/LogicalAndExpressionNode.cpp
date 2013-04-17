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

ASTData* LogicalAndExpressionNode::toOperations()
{
	ASTData* data = new ASTData();

	return data;
}

std::string LogicalAndExpressionNode::getNodeTypeAsString()
{

	return std::string( "logical AND expression" );

}

LogicalAndExpressionNode::~LogicalAndExpressionNode() {}

