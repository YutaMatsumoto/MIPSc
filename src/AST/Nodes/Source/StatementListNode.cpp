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
	nodeData = toOperations();
}

StatementListNode::StatementListNode( StatementListNode* _statementList, StatementNode* _statement )
		: statement( _statement ), statementList( _statementList )
{
	nodeData = toOperations();
}

ASTData* StatementListNode::toOperations()
{
	ASTData* data = new ASTData();

	if( statementList == 0 )

		return statement->nodeData;

	else
	{

		std::vector< Operation* >* operations = new std::vector< Operation* >();

		ASTData* statementData = statement->nodeData;

		ASTData* statementListData = statementList->nodeData;

		operations->insert( operations->end() , statementListData->code->begin() , statementListData->code->end() );

		operations->insert( operations->end() , statementData->code->begin() , statementData->code->end() );

		data->code = operations;

		return data;

	}

}

std::string StatementListNode::getNodeTypeAsString()
{

	return std::string( "statement list" );

}

