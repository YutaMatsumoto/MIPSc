/*
 * PostfixExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "PostfixExpressionNode.h"

#include "ArrayType.h"
#include "CallOp.h"
#include "LoadOp.h"
#include "AddOp.h"
#include "GetAddressOp.h"
#include "AdditiveExpressionNode.h"
#include "IdTracker.h"

//Primary Expression
PostfixExpressionNode::PostfixExpressionNode( PrimaryExpressionNode* _primaryExpression )
	: primaryExpression( _primaryExpression )
{
	type = PrimaryExpression;

	nodeData = toOperations();
}

//Array Access
PostfixExpressionNode::PostfixExpressionNode( PostfixExpressionNode* _postfixExpression , ExpressionNode* arrayExpression )
	: postfixExpression( _postfixExpression )
{
	type = ArrayAccess;

	nodeData = toOperations();
}

//Function Call, No arguments =OR= Increment =OR= Dcrement
PostfixExpressionNode::PostfixExpressionNode( PostfixExpressionNode* _postfixExpression , PostfixExpressionType _type )
	: postfixExpression( _postfixExpression ), type(_type)
{
	nodeData = toOperations();
}

//Function Call, w/ arguments
PostfixExpressionNode::PostfixExpressionNode( PostfixExpressionNode* _postfixExpression , ArgExpressionListNode* _argExpressionList )
	: postfixExpression( _postfixExpression ), argExpressionList( _argExpressionList )
{
	type = FunctionCall;

	nodeData = toOperations();
}

//Direct Member Access
PostfixExpressionNode::PostfixExpressionNode( PostfixExpressionNode* _postfixExpression , IdentifierNode* _memberIdentifier , PostfixExpressionType _type )
	: postfixExpression( _postfixExpression ), memberIdentifier( _memberIdentifier ), type( _type )
{
	type = DirectMemberAccess;

	nodeData = toOperations();
}

ASTData* PostfixExpressionNode::toOperations()
{
	ASTData* data = new ASTData();

	//std::vector< Operation* >* operations = new std::vector< Operation* >();

	if( type ==  PrimaryExpression )

		return primaryExpression->nodeData;

	if( type == ArrayAccess )
	{
		//Various errors will be thrown here (eg: accessing a non-array type)
		ASTData* arrayData = postfixExpression->nodeData;

		Symbol* arrayId = arrayData->result;

		Type* arrayType = arrayId->symbolType;

		ArrayType* array = (ArrayType*) arrayType;

		//create a new temporary name
		std::string tempName = std::string("t") + std::to_string( IdTracker::getInstance()->getId() );

		Symbol* temporary = new Symbol( tempName , *new SymbolLocation() , array->elementType , Operand::ITEMP );

		data->code->insert( data->code->end() , arrayExpression->nodeData->code->begin() , arrayExpression->nodeData->code->end() );

		//create a new temporary name
		tempName = std::string("t") + std::to_string( IdTracker::getInstance()->getId() );

		Symbol* temporary2 = new Symbol( tempName , *new SymbolLocation() , array->elementType , Operand::ITEMP );

		tempName = std::string("t") + std::to_string( IdTracker::getInstance()->getId() );

		Symbol* temporary3 = new Symbol( tempName , *new SymbolLocation() , array->elementType , Operand::ITEMP );

		GetAddressOp* loadArrAddr = new GetAddressOp( temporary, arrayId );

		data->code->push_back( loadArrAddr );

		AddOp* add = new AddOp( temporary2 , temporary , arrayExpression->nodeData->result , AdditiveExpressionNode::Add );

		LoadOp* load = new LoadOp( temporary3 , temporary2 );

		data->code->push_back(add);

		data->code->push_back(load);

		data->result = temporary3;

	}

	if( type == FunctionCall )
	{
		//TODO: Implement function calls

		std::vector< Operation* >* operations = data->code;

		Symbol* function = postfixExpression->nodeData->result;

		CallOp* op = new CallOp( function );

		for( unsigned int i = 0 ; i < postfixExpression->nodeData->code->size() ; i++ )
		{

			LoadOp* j = dynamic_cast<LoadOp*>( postfixExpression->nodeData->code->at( i ) );

			if( j )

				postfixExpression->nodeData->code->erase(  postfixExpression->nodeData->code->begin() + i );

		}

		operations->insert( operations->end() , postfixExpression->nodeData->code->begin() , postfixExpression->nodeData->code->end() );

		operations->push_back( op );

		return data;

	}

	if( type == DirectMemberAccess )
	{



	}

	if( type == PointerMemberAccess )
	{



	}

	if( type == Increment )
	{



	}

	if( type == Decrement )
	{



	}

	return data;
}

std::string PostfixExpressionNode::getNodeTypeAsString()
{

	return std::string( "postfix expression" );

}

