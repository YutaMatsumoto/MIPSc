/*
 * LogicalOrExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "LogicalOrExpressionNode.h"

LogicalOrExpressionNode::LogicalOrExpressionNode( LogicalAndExpressionNode* _logicalAndExpression ) : logicalAndExpression( _logicalAndExpression )
{

}

LogicalOrExpressionNode::LogicalOrExpressionNode( LogicalOrExpressionNode* _logicalOrExpression ,
		LogicalAndExpressionNode* _logicalAndExpression )
	: logicalOrExpression( _logicalOrExpression ), logicalAndExpression( _logicalAndExpression )
{

}

std::vector< Operation* >* LogicalOrExpressionNode::toOperations()
{
	std::vector< Operation* >* operations;

	return operations;
}

std::string LogicalOrExpressionNode::getNodeTypeAsString()
{

	return std::string( "logical OR expression" );

}


