/*
 * SelectionStatementNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "SelectionStatementNode.h"
#include "BranchZeroOp.h"
#include "UnconditionalJumpOp.h"
#include "IdTracker.h"

SelectionStatementNode::SelectionStatementNode( ExpressionNode* _condition , StatementNode* _statement, SelectionStatementType _type )
	: condition( _condition ), statement( _statement ), type( _type )
{
	nodeData = toOperations();
}

SelectionStatementNode::SelectionStatementNode( ExpressionNode* _condition , StatementNode* _statement, StatementNode* _elseStatement )
		: condition( _condition ), statement( _statement )
{
	type = IfElse;

	nodeData = toOperations();
}

ASTData* SelectionStatementNode::toOperations()
{
	ASTData* data = new ASTData();

	/*if( type == If )
	{

		int id = IdTracker::getInstance()->getId();

		Label* end = new Label( std::string("ifend"), id );

		ASTData* conditionalData = condition->nodeData;

		ASTData* statementdata = statement->nodeData;

		data->code->insert( data->code->end() , conditionalData->code->begin() , conditionalData->code->end() );

		BranchEqualOp* branch1 = new BranchEqualOp( end , conditionalData->result );

		data->code->push_back( branch1 );

		data->code->insert( data->code->end() , statementdata->code->begin() , statementdata->code->end() );

		data->code->push_back( end );

	}

	if( type == IfElse )
	{




	}*/

	int id = IdTracker::getInstance()->getId();

	Label* end = new Label( std::string("ifend"), id );

	id = IdTracker::getInstance()->getId();

	Label* ifstatement = new Label( std::string("ifstatement"), id );

	ASTData* conditionalData = condition->nodeData;

	ASTData* statementdata = statement->nodeData;

	data->code->insert( data->code->end() , conditionalData->code->begin() , conditionalData->code->end() );

	BranchZeroOp* branch1 = new BranchZeroOp( ifstatement , conditionalData->result );

	UnconditionalJumpOp* jump = new UnconditionalJumpOp( end );

	data->code->push_back( branch1 );

	data->code->push_back( jump );

	data->code->push_back( ifstatement );

	data->code->insert( data->code->end() , statementdata->code->begin() , statementdata->code->end() );

	data->code->push_back( end );

	if( type == IfElse )

		data->code->insert( data->code->end() , elseStatement->nodeData->code->begin() , elseStatement->nodeData->code->end() );

	return data;
}

std::string SelectionStatementNode::getNodeTypeAsString()
{

	return std::string( "selection statement" );

}


