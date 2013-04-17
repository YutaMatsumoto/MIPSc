/*
 * UnaryExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "UnaryExpressionNode.h"

UnaryExpressionNode::UnaryExpressionNode( PostfixExpressionNode* _postfixExpression ) : postfixExpression( _postfixExpression )
{
	type = Postfix;
}

UnaryExpressionNode::UnaryExpressionNode( UnaryExpressionNode* _unaryExpression , UnaryExpressionType _type )
	: unaryExpression( _unaryExpression ), type(_type)
{

}

UnaryExpressionNode::UnaryExpressionNode( UnaryOperatorNode* _unaryOperator , CastExpressionNode* _castExpression )
			: unaryOperator( _unaryOperator ), castExpression(_castExpression)
{
	type = Cast;
}

UnaryExpressionNode::UnaryExpressionNode( TypeNameNode* _typeName )
				: typeName( _typeName )
{
	type = SizeofType;
}

ASTData* UnaryExpressionNode::toOperations()
{
	ASTData* data = new ASTData();

	if( type == Postfix )

		return postfixExpression->toOperations();


	return data;
}

//~PrimaryExpressionNode(){}

std::string UnaryExpressionNode::getNodeTypeAsString()
{

	return std::string( "unary expression" );

}

