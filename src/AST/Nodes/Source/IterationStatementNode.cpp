/*
 * IterationStatementNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "IterationStatementNode.h"

IterationStatementNode::IterationStatementNode( ExpressionNode* _condition , StatementNode* _statement, IterationStatementType _type )
	: condition( _condition ), statement( _statement ), type( _type )
{

}

IterationStatementNode::IterationStatementNode( ExpressionNode* _initialization ,ExpressionNode* _condition ,ExpressionNode* _increment ,StatementNode* _statement )
	: initialization( _initialization ), condition(_condition), increment(_increment), statement(_statement)
{
	type = For;
}

std::vector< Operation* >* IterationStatementNode::toOperations()
{
	std::vector< Operation* >* operations;

	return operations;
}

std::string IterationStatementNode::getNodeTypeAsString()
{

	return std::string( "iteration statement" );

}

IterationStatementNode::~IterationStatementNode() {}

