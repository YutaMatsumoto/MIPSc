/*
 * AdditiveExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "AdditiveExpressionNode.h"
#include "IdTracker.h"
#include "BuiltinType.h"
#include "Symbol.h"
#include <vector>
#include "AddOp.h"

AdditiveExpressionNode::AdditiveExpressionNode( MultiplicativeExpressionNode* _multiplicativeExpression ) : multiplicativeExpression( _multiplicativeExpression )
{

}

AdditiveExpressionNode::AdditiveExpressionNode( AdditiveExpressionNode* _additiveExpression ,
		MultiplicativeExpressionNode* _multiplicativeExpression ,
		AdditiveExpressionType _type
		)
	: multiplicativeExpression( _multiplicativeExpression ), additiveExpression( _additiveExpression ), type( _type )
{

}

ASTData* AdditiveExpressionNode::toOperations()
{

	if( additiveExpression == 0 )
	{

		return multiplicativeExpression->toOperations();

	}

	ASTData* data = new ASTData();

	std::vector< Operation* >* operations = new std::vector< Operation* >();

	//Gets the data for the first parameter
	ASTData* additiveData = additiveExpression->toOperations();

	//gets the data for the second parameter
	ASTData* multiplicativeData = multiplicativeExpression->toOperations();

	//create a new temporary name
	std::string tempName = std::string("t") + std::to_string( IdTracker::getInstance()->getId() );

	//get the name of the first parameters temporary
	Symbol* additiveResult = additiveData->result;

	//get the name of the second parameters temporary
	Symbol* multiplicativeResult = multiplicativeData->result;

	//create a new temporary for our result
	Symbol* temporary = new Symbol( tempName , *new SymbolLocation() , multiplicativeResult->symbolType );

	//create a new operation to compute the addition
	AddOp* op = new AddOp( temporary , additiveResult , multiplicativeResult );

	//Add the multiplicative operations to what we will return
	operations->insert( operations->end() , multiplicativeData->code->begin() , multiplicativeData->code->end() );

	//add the additive the multiplicative operations to what we will return
	operations->insert( operations->end() , additiveData->code->begin() , additiveData->code->end() );

	//Add our 'add' operation to the end of the list
	operations->push_back( op );

	//add the result of this expression to the data
	data->result = temporary;

	//add the code used to compute this result
	data->code = operations;

	//return the result
	return data;

}


std::string AdditiveExpressionNode::getNodeTypeAsString()
{

	return std::string( "additive expression" );

}

AdditiveExpressionNode::~AdditiveExpressionNode() {}
