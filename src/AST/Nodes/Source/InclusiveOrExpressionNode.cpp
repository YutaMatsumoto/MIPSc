/*
 * InclusiveOrExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "InclusiveOrExpressionNode.h"

InclusiveOrExpressionNode::InclusiveOrExpressionNode( ExclusiveOrExpressionNode* _exclusiveOrExpression ) : exclusiveOrExpression( _exclusiveOrExpression )
{

}

InclusiveOrExpressionNode::InclusiveOrExpressionNode( InclusiveOrExpressionNode* _inclusiveOrExpression ,
		ExclusiveOrExpressionNode* _exclusiveOrExpression
		)
	: exclusiveOrExpression( _exclusiveOrExpression ), inclusiveOrExpression( _inclusiveOrExpression )
{

}

ASTData* InclusiveOrExpressionNode::toOperations()
{
	ASTData* data = new ASTData();

	if( inclusiveOrExpression == 0 )

		return exclusiveOrExpression->toOperations();

	return data;
}

std::string InclusiveOrExpressionNode::getNodeTypeAsString()
{

	return std::string( "inclusive OR expression" );

}

InclusiveOrExpressionNode::~InclusiveOrExpressionNode() {}


