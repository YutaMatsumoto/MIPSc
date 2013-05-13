/*
 * JumpStatementNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "JumpStatementNode.h"
#include "ReturnOp.h"

JumpStatementNode::JumpStatementNode( ExpressionNode* _expression ) : expression( _expression )
{
	type = Return;

	nodeData = toOperations();
}

JumpStatementNode::JumpStatementNode( IdentifierNode* _identifier ) : identifier( _identifier )
{
	type = Goto;

	nodeData = toOperations();
}

JumpStatementNode::JumpStatementNode( JumpStatementType _type ) : type( _type )
{

}


ASTData* JumpStatementNode::toOperations()
{
	ASTData* data = new ASTData();

	if( type == Return )
	{

		if( expression )
		{

			data->code->insert( data->code->end() , expression->nodeData->code->begin() , expression->nodeData->code->end() );

		}

		ReturnOp* op = new ReturnOp( expression->nodeData->result );

		data->code->push_back( op );

	}

	return data;
}


std::string JumpStatementNode::getNodeTypeAsString()
{

	return std::string( "jump statement" );

}

