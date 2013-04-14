/*
 * PrimaryExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "PrimaryExpressionNode.h"

PrimaryExpressionNode::PrimaryExpressionNode( IdentifierNode* _identifier ) : identifier( _identifier )
{

}

PrimaryExpressionNode::PrimaryExpressionNode( ConstantNode* _constant ) : constant( _constant )
{

}

PrimaryExpressionNode::PrimaryExpressionNode( StringNode* _string ) : string( _string )
{

}

PrimaryExpressionNode::PrimaryExpressionNode( ExpressionNode* _expression ) : expression( _expression )
{

}

std::vector< Operation* >* PrimaryExpressionNode::toOperations()
{
	std::vector< Operation* >* operations;

	return operations;
}

std::string PrimaryExpressionNode::getNodeTypeAsString()
{

	return std::string( "primary expression" );

}

