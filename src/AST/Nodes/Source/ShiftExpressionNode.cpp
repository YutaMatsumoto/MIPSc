/*
 * ShiftExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "ShiftExpressionNode.h"

#include "IdTracker.h"
#include "BuiltinType.h"
#include "Symbol.h"
#include <vector>
#include "ShiftOp.h"

ShiftExpressionNode::ShiftExpressionNode( AdditiveExpressionNode* _additiveExpression ) : additiveExpression( _additiveExpression )
{
	nodeData = toOperations();
}

ShiftExpressionNode::ShiftExpressionNode( ShiftExpressionNode* _shiftExpression ,
		AdditiveExpressionNode* _additiveExpression ,
		ShiftExpressionType _type
		)
	: shiftExpression( _shiftExpression ), additiveExpression( _additiveExpression ), type( _type )
{
	nodeData = toOperations();
}

ASTData* ShiftExpressionNode::toOperations()
{
	if( shiftExpression == 0 )
		{

			return additiveExpression->nodeData;

		}

		ASTData* data = new ASTData();

		std::vector< Operation* >* operations = new std::vector< Operation* >();

		//Gets the data for the first parameter
		ASTData* shiftExpressionData = shiftExpression->nodeData;

		//gets the data for the second parameter
		ASTData* additiveExpressionData = additiveExpression->nodeData;

		//create a new temporary name
		std::string tempName = std::string("t") + std::to_string( IdTracker::getInstance()->getId() );

		//get the name of the first parameters temporary
		Symbol* shiftExpressionResult = shiftExpressionData->result;

		//get the name of the second parameters temporary
		Symbol* additiveExpressionResult = additiveExpressionData->result;

		//create a new temporary for our result
		Symbol* temporary = new Symbol( tempName , *new SymbolLocation() , shiftExpressionResult->symbolType );

		//create a new operation to compute the addition
		ShiftOp* op = new ShiftOp( temporary , shiftExpressionResult , additiveExpressionResult , type );

		//Add the multiplicative operations to what we will return
		operations->insert( operations->end() , shiftExpressionData->code->begin() , shiftExpressionData->code->end() );

		//add the additive the multiplicative operations to what we will return
		operations->insert( operations->end() , additiveExpressionData->code->begin() , additiveExpressionData->code->end() );

		//Add our 'mult' operation to the end of the list
		operations->push_back( op );

		//add the result of this expression to the data
		data->result = temporary;

		//add the code used to compute this result
		data->code = operations;

		//return the result
		return data;
}

//~PrimaryExpressionNode(){}

std::string ShiftExpressionNode::getNodeTypeAsString()
{

	return std::string( "shift expression" );

}


