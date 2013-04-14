/*
 * SelectionStatementNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "SelectionStatementNode.h"

SelectionStatementNode::SelectionStatementNode( ExpressionNode* _condition , StatementNode* _statement, SelectionStatementType _type )
	: condition( _condition ), statement( _statement ), type( _type )
{

}

SelectionStatementNode::SelectionStatementNode( ExpressionNode* _condition , StatementNode* _statement, StatementNode* _elseStatement )
		: condition( _condition ), statement( _statement )
{
	type = IfElse;
}

std::vector< Operation* >* SelectionStatementNode::toOperations()
{
	std::vector< Operation* >* operations;

	return operations;
}

std::string SelectionStatementNode::getNodeTypeAsString()
{

	return std::string( "selection statement" );

}


