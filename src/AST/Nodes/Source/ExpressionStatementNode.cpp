/*
 * ExpressionStatementNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "ExpressionStatementNode.h"

ExpressionStatementNode::ExpressionStatementNode( )
{
	nodeData = toOperations();
}

ExpressionStatementNode::ExpressionStatementNode( ExpressionNode* _expression )
		: expression( _expression )
{
	nodeData = toOperations();
}

ASTData* ExpressionStatementNode::toOperations()
{
	ASTData* data = new ASTData();

	if( expression )

		return expression->nodeData;

	return data;
}

std::string ExpressionStatementNode::getNodeTypeAsString()
{

	return std::string( "expression statement" );

}


