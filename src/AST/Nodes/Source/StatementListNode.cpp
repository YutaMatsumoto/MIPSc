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

ASTData* StatementListNode::toOperations()
{
	ASTData* data = new ASTData();

	return data;
}

std::string StatementListNode::getNodeTypeAsString()
{

	return std::string( "statement list" );

}

