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

ASTData* ExpressionStatementNode::toOperations()
{
	ASTData* data = new ASTData();

	return data;
}

std::string ExpressionStatementNode::getNodeTypeAsString()
{

	return std::string( "expression statement" );

}


