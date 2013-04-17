/*
 * MultiplicativeExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "MultiplicativeExpressionNode.h"

MultiplicativeExpressionNode::MultiplicativeExpressionNode( CastExpressionNode* _castExpression ) : castExpression( _castExpression )
{

}

MultiplicativeExpressionNode::MultiplicativeExpressionNode( MultiplicativeExpressionNode* _multiplicativeExpression ,
		CastExpressionNode* _castExpression ,
		MultiplicativeExpressionType _type
		)
	: multiplicativeExpression( _multiplicativeExpression ), castExpression(_castExpression), type( _type )
{

}

ASTData* MultiplicativeExpressionNode::toOperations()
{
	ASTData* data = new ASTData();

	return data;
}

std::string MultiplicativeExpressionNode::getNodeTypeAsString()
{

	return std::string( "multiplicative expression" );

}


