/*
 * PrimaryExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "PrimaryExpressionNode.h"

PrimaryExpressionNode::PrimaryExpressionNode( IdentifierNode* _identifier ) : identifier( _identifier )
{
	nodeData = toOperations();
}

PrimaryExpressionNode::PrimaryExpressionNode( ConstantNode* _constant ) : constant( _constant )
{
	nodeData = toOperations();
}

PrimaryExpressionNode::PrimaryExpressionNode( StringNode* _string ) : string( _string )
{
	nodeData = toOperations();
}

PrimaryExpressionNode::PrimaryExpressionNode( ExpressionNode* _expression ) : expression( _expression )
{
	nodeData = toOperations();
}

ASTData* PrimaryExpressionNode::toOperations()
{

	if( identifier )

		return identifier->nodeData;

	if( constant )

		return constant->nodeData;

	if( string )

		return string->nodeData;

	if( expression )

		return expression->nodeData;

}

std::string PrimaryExpressionNode::getNodeTypeAsString()
{

	return std::string( "primary expression" );

}

