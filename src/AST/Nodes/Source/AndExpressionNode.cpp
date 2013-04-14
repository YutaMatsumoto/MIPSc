/*
 * AndExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "AndExpressionNode.h"

AndExpressionNode::AndExpressionNode( EqualityExpressionNode* _equalityExpression ) : equalityExpression( _equalityExpression )
{

}

AndExpressionNode::AndExpressionNode( AndExpressionNode* _andExpression ,
		EqualityExpressionNode* _equalityExpression
		)
	: equalityExpression( _equalityExpression ), andExpression( _andExpression )
{

}

std::vector< Operation* >* AndExpressionNode::toOperations()
{
	std::vector< Operation* >* operations;

	return operations;
}

std::string AndExpressionNode::getNodeTypeAsString()
{

	return std::string( "AND expression" );

}

AndExpressionNode::~AndExpressionNode() {}


