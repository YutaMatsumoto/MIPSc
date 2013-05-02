/*
 * StatementNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "StatementNode.h"

StatementNode::StatementNode( LabeledStatementNode* _labeledStatement )
	: labeledStatement( _labeledStatement )
{

}

StatementNode::StatementNode( ExpressionStatementNode* _expressionStatement )
	: expressionStatement( _expressionStatement )
{

}

StatementNode::StatementNode( CompoundStatementNode* _compoundStatement )
	: compoundStatement( _compoundStatement )
{

}

StatementNode::StatementNode( SelectionStatementNode* _selectionStatement )
	: selectionStatement( _selectionStatement )
{

}

StatementNode::StatementNode( IterationStatementNode* _iterationStatement )
	: iterationStatement( _iterationStatement )
{

}

StatementNode::StatementNode( JumpStatementNode* _jumpStatement )
	: jumpStatement( _jumpStatement )
{

}

ASTData* StatementNode::toOperations()
{
	//std::vector< Operation* >* operations;

	if( labeledStatement )
	{

		//return labeledStatement->toOperations();

	}

	if( compoundStatement )
	{

		return compoundStatement->toOperations();

	}

	if( expressionStatement )
	{

		return expressionStatement->toOperations();

	}

	if( selectionStatement )
	{

		//return selectionStatement->toOperations();

	}

	if( iterationStatement )
	{

		//return iterationStatement->toOperations();

	}

	if( jumpStatement )
	{

		//return jumpStatement->toOperations();

	}

	return 0;

}

std::string StatementNode::getNodeTypeAsString()
{

	return std::string( "statement" );

}


