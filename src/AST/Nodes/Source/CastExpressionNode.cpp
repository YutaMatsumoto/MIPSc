/*
 * CastExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "CastExpressionNode.h"

CastExpressionNode::CastExpressionNode( UnaryExpressionNode* _unaryExpression ) : unaryExpression( _unaryExpression )
{
	nodeData = toOperations();
}

CastExpressionNode::CastExpressionNode( TypeNameNode* _typeName , CastExpressionNode* _castExpression )
	: typeName( _typeName ), castExpression(_castExpression)
{
	nodeData = toOperations();
}

ASTData* CastExpressionNode::toOperations()
{
	ASTData* data = new ASTData();

	if( unaryExpression )

		return unaryExpression->nodeData;

	return data;
}

std::string CastExpressionNode::getNodeTypeAsString()
{

	return std::string( "cast expression" );

}


