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

	if( statementList == 0 )

		return statement->toOperations();

	else
	{

		std::vector< Operation* >* operations = new std::vector< Operation* >();

		ASTData* statementData = statement->toOperations();

		ASTData* statementListData = statementList->toOperations();

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

