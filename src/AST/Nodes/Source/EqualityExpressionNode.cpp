/*
 * EqualityExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "EqualityExpressionNode.h"

EqualityExpressionNode::EqualityExpressionNode( RelationalExpressionNode* _relationalExpression ) : relationalExpression( _relationalExpression )
{

}

EqualityExpressionNode::EqualityExpressionNode( EqualityExpressionNode* _equalityExpression ,
		RelationalExpressionNode* _relationalExpression ,
		EqualityExpressionType _type
		)
	: equalityExpression( _equalityExpression ), relationalExpression( _relationalExpression ), type( _type )
{

}

ASTData* EqualityExpressionNode::toOperations()
{
	ASTData* data = new ASTData();

	if( equalityExpression == 0 )

		return relationalExpression->toOperations();

	return data;
}


std::string EqualityExpressionNode::getNodeTypeAsString()
{

	return std::string( "equality expression" );

}

EqualityExpressionNode::~EqualityExpressionNode()
{

}
