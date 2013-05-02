/*
 * LogicalAndExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "LogicalAndExpressionNode.h"

LogicalAndExpressionNode::LogicalAndExpressionNode( InclusiveOrExpressionNode* _inclusiveOrExpression ) : inclusiveOrExpression( _inclusiveOrExpression )
{

}

LogicalAndExpressionNode::LogicalAndExpressionNode( LogicalAndExpressionNode* _logicalAndExpression,
		InclusiveOrExpressionNode* _inclusiveOrExpression
		)
	: logicalAndExpression( _logicalAndExpression ), inclusiveOrExpression( _inclusiveOrExpression )
{

}

ASTData* LogicalAndExpressionNode::toOperations()
{
	ASTData* data = new ASTData();

	if( logicalAndExpression == 0 )

		return inclusiveOrExpression->toOperations();

	return data;
}

std::string LogicalAndExpressionNode::getNodeTypeAsString()
{

	return std::string( "logical AND expression" );

}

LogicalAndExpressionNode::~LogicalAndExpressionNode() {}

