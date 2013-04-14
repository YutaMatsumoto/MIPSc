/*
 * ExpressionStatementNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "ExpressionStatementNode.h"

ExpressionStatementNode::ExpressionStatementNode( )
{

}

ExpressionStatementNode::ExpressionStatementNode( ExpressionNode* _expression )
		: expression( _expression )
	{

	}

std::vector< Operation* >* ExpressionStatementNode::toOperations()
{
	std::vector< Operation* >* operations;

	return operations;
}

std::string ExpressionStatementNode::getNodeTypeAsString()
{

	return std::string( "expression statement" );

}


