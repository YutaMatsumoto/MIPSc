/*
 * LabeledStatementNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "LabeledStatementNode.h"

LabeledStatementNode::LabeledStatementNode( IdentifierNode* _identifier, StatementNode* _statement )
	: identifier( _identifier ), statement( _statement )
{
	type = Label;
}

LabeledStatementNode::LabeledStatementNode( ConstantExpressionNode* _constantExpression, StatementNode* _statement )
		: constantExpression( _constantExpression ), statement( _statement )
{
	type = Case;
}

LabeledStatementNode::LabeledStatementNode( StatementNode* _statement )
		: statement( _statement )
{
	type = Default;
}

std::vector< Operation* >* LabeledStatementNode::toOperations()
{
	std::vector< Operation* >* operations = new std::vector< Operation* >();

	if( type == Label )
	{

		std::vector< Operation* >* temp = identifier->toOperations();

		operations->insert( operations->end() , temp->begin() , temp->end() );

		temp = statement->toOperations();

		operations->insert( operations->end() , temp->begin() , temp->end() );

	}

	if( type == Case )
	{

		std::vector< Operation* >* temp = constantExpression->toOperations();

		operations->insert( operations->end() , temp->begin() , temp->end() );

		temp = statement->toOperations();

		operations->insert( operations->end() , temp->begin() , temp->end() );

	}
}

std::string LabeledStatementNode::getNodeTypeAsString()
{

	return std::string( "labeled statement" );

}

