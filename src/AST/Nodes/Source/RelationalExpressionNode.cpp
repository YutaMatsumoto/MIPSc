/*
 * RelationalExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "RelationalExpressionNode.h"
#include "AdditiveExpressionNode.h"
#include "ConditionalStoreOp.h"
#include "AddOp.h"
#include "IdTracker.h"

RelationalExpressionNode::RelationalExpressionNode( ShiftExpressionNode* _shiftExpression ) : shiftExpression( _shiftExpression )
{
	nodeData = toOperations();
}

RelationalExpressionNode::RelationalExpressionNode( RelationalExpressionNode* _relationalExpression ,
		ShiftExpressionNode* _shiftExpression ,
		RelationalExpressionType _type
		)
	: shiftExpression( _shiftExpression ), relationalExpression( _relationalExpression ), type( _type )
{
	nodeData = toOperations();
}

ASTData* RelationalExpressionNode::toOperations()
{
	ASTData* data = new ASTData();

	if( relationalExpression == 0 )

		return shiftExpression->nodeData;

	ASTData* relationalData = relationalExpression->nodeData;

	ASTData* shiftData = shiftExpression->nodeData;

	//create a new temporary name
	std::string tempName = std::string("t") + std::to_string( IdTracker::getInstance()->getId() );

	//create a new temporary for our result
	Symbol* temporary = new Symbol( tempName , *new SymbolLocation() , relationalData->result->symbolType , Symbol::ITEMP );

	data->code->insert( data->code->end() , relationalData->code->begin() , relationalData->code->end() );

	data->code->insert( data->code->end() , shiftData->code->begin() , shiftData->code->end() );

	ConditionalStoreOp* op = new ConditionalStoreOp( temporary , relationalData->result , shiftData->result , type );

	data->code->push_back( op );

	data->result = temporary;

	return data;
}

std::string RelationalExpressionNode::getNodeTypeAsString()
{

	return std::string( "relational expression" );

}

