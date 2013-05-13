/*
 * IterationStatementNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "IterationStatementNode.h"
#include "BranchZeroOp.h"
#include "UnconditionalJumpOp.h"
#include "IdTracker.h"

IterationStatementNode::IterationStatementNode( ExpressionNode* _condition , StatementNode* _statement, IterationStatementType _type )
	: condition( _condition ), statement( _statement ), type( _type )
{
	nodeData = toOperations();
}

IterationStatementNode::IterationStatementNode( ExpressionNode* _initialization ,ExpressionNode* _condition ,ExpressionNode* _increment ,StatementNode* _statement )
	: initialization( _initialization ), condition(_condition), increment(_increment), statement(_statement)
{
	type = For;

	nodeData = toOperations();
}

ASTData* IterationStatementNode::toOperations()
{
	ASTData* data = new ASTData();

	if( type == While )
	{

		int id = IdTracker::getInstance()->getId();

		Label* beginning = new Label( std::string("whilebegin") , id );

		id = IdTracker::getInstance()->getId();

		Label* end = new Label( std::string("whileend"), id );

		id = IdTracker::getInstance()->getId();

		Label* code = new Label( std::string("whilecode") , id );

		ASTData* conditionalData = condition->nodeData;

		ASTData* statementdata = statement->nodeData;

		data->code->push_back( beginning );

		data->code->insert( data->code->end() , conditionalData->code->begin() , conditionalData->code->end() );

		BranchZeroOp* branch1 = new BranchZeroOp( code , conditionalData->result );

		data->code->push_back( branch1 );

		UnconditionalJumpOp* jump = new UnconditionalJumpOp( end );

		data->code->push_back( jump );

		data->code->push_back( code );

		data->code->insert( data->code->end() , statementdata->code->begin() , statementdata->code->end() );

		UnconditionalJumpOp* back = new UnconditionalJumpOp( beginning );

		data->code->push_back( back );

		data->code->push_back( end );

		return data;

	}

	if( type != While )
	{

		int id = IdTracker::getInstance()->getId();

		Label* beginning = new Label( std::string("forbegin") + std::to_string(id) , id );

		id = IdTracker::getInstance()->getId();

		Label* end = new Label( std::string("forend") + std::to_string(id) , id );

		id = IdTracker::getInstance()->getId();

		Label* code = new Label( std::string("forcode") + std::to_string(id) , id );

		ASTData* initializationData = initialization->nodeData;

		ASTData* conditionalData = condition->nodeData;

		ASTData* statementdata = statement->nodeData;

		ASTData* incrementData = statement->nodeData;

		if( initializationData )

			data->code->insert( data->code->end() , initializationData->code->begin() , initializationData->code->end() );

		data->code->push_back( beginning );

		if( conditionalData )
		{

			data->code->insert( data->code->end() , conditionalData->code->begin() , conditionalData->code->end() );

			BranchZeroOp* branch1 = new BranchZeroOp( code , conditionalData->result );

			data->code->push_back( branch1 );

			UnconditionalJumpOp* jump = new UnconditionalJumpOp( end );

			data->code->push_back( jump );

			data->code->push_back( code );

		}

		data->code->insert( data->code->end() , statementdata->code->begin() , statementdata->code->end() );

		if( incrementData )

			data->code->insert( data->code->end() , incrementData->code->begin() , incrementData->code->end() );

		UnconditionalJumpOp* back = new UnconditionalJumpOp( beginning );

		data->code->push_back( back );

		data->code->push_back( end );

		return data;

	}

	return data;
}

std::string IterationStatementNode::getNodeTypeAsString()
{

	return std::string( "iteration statement" );

}

IterationStatementNode::~IterationStatementNode() {}

