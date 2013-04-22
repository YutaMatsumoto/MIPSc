/*
 * CompoundStatementNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "CompoundStatementNode.h"

CompoundStatementNode::CompoundStatementNode( DeclarationListNode* _declarationList )
	: declarationList( _declarationList )
{

}

CompoundStatementNode::CompoundStatementNode( StatementListNode* _statementList )
		: statementList( _statementList )
{

}

CompoundStatementNode::CompoundStatementNode( DeclarationListNode* _declarationList , StatementListNode* _statementList)
		: declarationList( _declarationList ), statementList( _statementList )
{

}

ASTData* CompoundStatementNode::toOperations()
{
	ASTData* data = new ASTData();

	std::vector< Operation* >* operations = new std::vector< Operation* >();

	if( declarationList )
	{

		ASTData* temp = declarationList->toOperations();

		operations->insert( operations->end() , temp->code->begin() , temp->code->end() );

	}

	if( statementList )
	{

		ASTData* temp = statementList->toOperations();

		operations->insert( operations->end() , temp->code->begin() , temp->code->end() );

	}

	data->code = operations;

	return data;
}

std::string CompoundStatementNode::getNodeTypeAsString()
{

	return std::string( "compound statement" );

}

