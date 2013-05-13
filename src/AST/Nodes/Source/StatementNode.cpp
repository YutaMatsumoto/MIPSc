/*
 * StatementNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "StatementNode.h"

#include "Comment.h"
#include <boost/algorithm/string.hpp>

StatementNode::StatementNode( LabeledStatementNode* _labeledStatement , std::string _lineInfo )
	: labeledStatement( _labeledStatement ) , lineInfo(_lineInfo)
{
	nodeData = toOperations();
}

StatementNode::StatementNode( ExpressionStatementNode* _expressionStatement, std::string _lineInfo )
	: expressionStatement( _expressionStatement ) , lineInfo(_lineInfo)
{
	nodeData = toOperations();
}

StatementNode::StatementNode( CompoundStatementNode* _compoundStatement, std::string _lineInfo )
	: compoundStatement( _compoundStatement ) , lineInfo(_lineInfo)
{
	nodeData = toOperations();
}

StatementNode::StatementNode( SelectionStatementNode* _selectionStatement, std::string _lineInfo )
	: selectionStatement( _selectionStatement ) , lineInfo(_lineInfo)
{
	nodeData = toOperations();
}

StatementNode::StatementNode( IterationStatementNode* _iterationStatement, std::string _lineInfo )
	: iterationStatement( _iterationStatement ) , lineInfo(_lineInfo)
{
	nodeData = toOperations();
}

StatementNode::StatementNode( JumpStatementNode* _jumpStatement , std::string _lineInfo)
	: jumpStatement( _jumpStatement ) , lineInfo(_lineInfo)
{
	nodeData = toOperations();
}

ASTData* StatementNode::toOperations()
{
	ASTData* data = new ASTData();

	std::vector< Operation* >* operations = new std::vector< Operation* >();

	boost::algorithm::trim( lineInfo );

	Comment* com = new Comment( lineInfo );

	if( labeledStatement )
	{

		operations->push_back( com );

		operations->insert( operations->end() , labeledStatement->nodeData->code->begin() , labeledStatement->nodeData->code->end() );

		data->code = operations;

		return data;

	}

	if( compoundStatement )
	{

		operations->push_back( com );

		operations->insert( operations->end() , compoundStatement->nodeData->code->begin() , compoundStatement->nodeData->code->end() );

		data->code = operations;

		return data;

	}

	if( expressionStatement )
	{

		operations->push_back( com );

		operations->insert( operations->end() , expressionStatement->nodeData->code->begin() , expressionStatement->nodeData->code->end() );

		data->code = operations;

		return data;

	}

	if( selectionStatement )
	{

		//return selectionStatement->toOperations();

	}

	if( iterationStatement )
	{

		return iterationStatement->toOperations();

	}

	if( jumpStatement )
	{

		return jumpStatement->toOperations();

	}

	return 0;

}

std::string StatementNode::getNodeTypeAsString()
{

	return std::string( "statement" );

}


