/*
 * AdditiveExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "AdditiveExpressionNode.h"

AdditiveExpressionNode::AdditiveExpressionNode( MultiplicativeExpressionNode* _multiplicativeExpression ) : multiplicativeExpression( _multiplicativeExpression )
{

}

AdditiveExpressionNode::AdditiveExpressionNode( AdditiveExpressionNode* _additiveExpression ,
		MultiplicativeExpressionNode* _multiplicativeExpression ,
		AdditiveExpressionType _type
		)
	: multiplicativeExpression( _multiplicativeExpression ), additiveExpression( _additiveExpression ), type( _type )
{

}

std::vector< Operation* >* AdditiveExpressionNode::toOperations()
{
	std::vector< Operation* >* operations = new std::vector< Operation* >();

}


std::string AdditiveExpressionNode::getNodeTypeAsString()
{

	return std::string( "additive expression" );

}

AdditiveExpressionNode::~AdditiveExpressionNode() {}
