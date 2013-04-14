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

std::vector< Operation* >* InclusiveOrExpressionNode::toOperations()
{
	std::vector< Operation* >* operations;

	return operations;
}

std::string InclusiveOrExpressionNode::getNodeTypeAsString()
{

	return std::string( "inclusive OR expression" );

}

InclusiveOrExpressionNode::~InclusiveOrExpressionNode() {}


