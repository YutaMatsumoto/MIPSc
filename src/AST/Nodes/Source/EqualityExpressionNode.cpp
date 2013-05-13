/*
 * EqualityExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "EqualityExpressionNode.h"

EqualityExpressionNode::EqualityExpressionNode( RelationalExpressionNode* _relationalExpression ) : relationalExpression( _relationalExpression )
{
	nodeData = toOperations();
}

EqualityExpressionNode::EqualityExpressionNode( EqualityExpressionNode* _equalityExpression ,
		RelationalExpressionNode* _relationalExpression ,
		EqualityExpressionType _type
		)
	: equalityExpression( _equalityExpression ), relationalExpression( _relationalExpression ), type( _type )
{
	nodeData = toOperations();
}

ASTData* EqualityExpressionNode::toOperations()
{
	ASTData* data = new ASTData();

	if( equalityExpression == 0 )

		return relationalExpression->nodeData;

	return data;
}


std::string EqualityExpressionNode::getNodeTypeAsString()
{

	return std::string( "equality expression" );

}

EqualityExpressionNode::~EqualityExpressionNode()
{

}
