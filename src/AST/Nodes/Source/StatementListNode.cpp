/*
 * StatementListNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "StatementListNode.h"

StatementListNode::StatementListNode( StatementNode* _statement )
	: statement( _statement )
{

}

StatementListNode::StatementListNode( StatementListNode* _statementList, StatementNode* _statement )
		: statement( _statement ), statementList( _statementList )
{

}

std::vector< Operation* >* StatementListNode::toOperations()
{
	std::vector< Operation* >* operations;

	return operations;
}

std::string StatementListNode::getNodeTypeAsString()
{

	return std::string( "statement list" );

}

