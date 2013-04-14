/*
 * CastExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "CastExpressionNode.h"

CastExpressionNode::CastExpressionNode( UnaryExpressionNode* _unaryExpression ) : unaryExpression( _unaryExpression )
{

}

CastExpressionNode::CastExpressionNode( TypeNameNode* _typeName , CastExpressionNode* _castExpression )
	: typeName( _typeName ), castExpression(_castExpression)
{

}

std::vector< Operation* >* CastExpressionNode::toOperations()
{
	std::vector< Operation* >* operations;

	return operations;
}

std::string CastExpressionNode::getNodeTypeAsString()
{

	return std::string( "cast expression" );

}


