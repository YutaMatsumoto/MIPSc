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

ASTData* AndExpressionNode::toOperations()
{
	ASTData* data = new ASTData();

	return data;
}

std::string AndExpressionNode::getNodeTypeAsString()
{

	return std::string( "AND expression" );

}

AndExpressionNode::~AndExpressionNode() {}


