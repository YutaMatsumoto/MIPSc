/*
 * MultiplicativeExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "MultiplicativeExpressionNode.h"

#include "IdTracker.h"
#include "BuiltinType.h"
#include "Symbol.h"
#include <vector>
#include "MultOp.h"

MultiplicativeExpressionNode::MultiplicativeExpressionNode( CastExpressionNode* _castExpression ) : castExpression( _castExpression )
{

}

MultiplicativeExpressionNode::MultiplicativeExpressionNode( MultiplicativeExpressionNode* _multiplicativeExpression ,
		CastExpressionNode* _castExpression ,
		MultiplicativeExpressionType _type
		)
	: multiplicativeExpression( _multiplicativeExpression ), castExpression(_castExpression), type( _type )
{

}

ASTData* MultiplicativeExpressionNode::toOperations()
{
	if( multiplicativeExpression == 0 )
		{

			return castExpression->toOperations();

		}

		ASTData* data = new ASTData();

		std::vector< Operation* >* operations = new std::vector< Operation* >();

		//Gets the data for the first parameter
		ASTData* multiplicativeData = multiplicativeExpression->toOperations();

		//gets the data for the second parameter
		ASTData* castExpressionData = castExpression->toOperations();

		//create a new temporary name
		std::string tempName = std::string("t") + std::to_string( IdTracker::getInstance()->getId() );

		//get the name of the first parameters temporary
		Symbol* multiplicativeResult = multiplicativeData->result;

		//get the name of the second parameters temporary
		Symbol* castExpressionResult = castExpressionData->result;

		//create a new temporary for our result
		Symbol* temporary = new Symbol( tempName , *new SymbolLocation() , castExpressionResult->symbolType );

		//create a new operation to compute the addition
		MultOp* op = new MultOp( temporary , multiplicativeResult , castExpressionResult );

		//Add the multiplicative operations to what we will return
		operations->insert( operations->end() , multiplicativeData->code->begin() , multiplicativeData->code->end() );

		//add the additive the multiplicative operations to what we will return
		operations->insert( operations->end() , castExpressionData->code->begin() , castExpressionData->code->end() );

		//Add our 'mult' operation to the end of the list
		operations->push_back( op );

		//add the result of this expression to the data
		data->result = temporary;

		//add the code used to compute this result
		data->code = operations;

		//return the result
		return data;
}

std::string MultiplicativeExpressionNode::getNodeTypeAsString()
{

	return std::string( "multiplicative expression" );

}


