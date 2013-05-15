/*
 * JumpStatementNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "JumpStatementNode.h"
#include "StoreOp.h"
#include "ReturnOp.h"
#include "BuiltinType.h"


JumpStatementNode::JumpStatementNode( ExpressionNode* _expression , SymbolTable* _stab ) : expression( _expression ),stab(_stab)
{
	type = Return;

	nodeData = toOperations();
}

JumpStatementNode::JumpStatementNode( IdentifierNode* _identifier , SymbolTable* _stab ) : identifier( _identifier ),stab(_stab)
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

		Symbol* retVal = new Symbol( std::string("retVal"),  *new SymbolLocation() , new BuiltinType( Type::Int ) , Symbol::LOCAL );

		//FunctionType* funcType = dynamic_cast<FunctionType*>(info.symbol->symbolType);

		//GetAddressOp* getAddr = new GetAddressOp( temporary , funcType->returnSymbol );

		StoreOp* writeToReturn = new StoreOp( retVal ,  expression->nodeData->result );

		data->code->push_back( writeToReturn );

		ReturnOp* op = new ReturnOp();

		data->code->push_back( op );

	}

	return data;
}


std::string JumpStatementNode::getNodeTypeAsString()
{

	return std::string( "jump statement" );

}

