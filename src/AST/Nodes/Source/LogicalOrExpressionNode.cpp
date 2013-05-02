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

ASTData* LogicalOrExpressionNode::toOperations()
{
	ASTData* data = new ASTData();

	if( logicalOrExpression == 0 )

		return logicalAndExpression->toOperations();

	return data;
}

std::string LogicalOrExpressionNode::getNodeTypeAsString()
{

	return std::string( "logical OR expression" );

}


