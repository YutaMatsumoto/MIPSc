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

InclusiveOrExpressionNode::InclusiveOrExpressionNode( InclusiveOrExpressionNode* _inclusiveOrExpressionNode ,
		ExclusiveOrExpressionNode* _exclusiveOrExpression
		)
	: exclusiveOrExpression( _exclusiveOrExpression ), inclusiveOrExpressionNode( _inclusiveOrExpressionNode )
{

}

ASTData* InclusiveOrExpressionNode::toOperations()
{
	ASTData* data = new ASTData();

	return data;
}

std::string InclusiveOrExpressionNode::getNodeTypeAsString()
{

	return std::string( "inclusive OR expression" );

}

InclusiveOrExpressionNode::~InclusiveOrExpressionNode() {}


