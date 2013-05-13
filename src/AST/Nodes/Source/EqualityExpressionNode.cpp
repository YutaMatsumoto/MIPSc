/*
 * EqualityExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "EqualityExpressionNode.h"
#include "AdditiveExpressionNode.h"
#include "AddOp.h"
#include "IdTracker.h"

EqualityExpressionNode::EqualityExpressionNode( RelationalExpressionNode* _relationalExpression ) : relationalExpression( _relationalExpression )
{
	nodeData = toOperations();
}

EqualityExpressionNode::EqualityExpressionNode( EqualityExpressionNode* _equalityExpression ,
		RelationalExpressionNode* _relationalExpression ,
		EqualityExpressionType _type
		)
	: equalityExpression( _equalityExpression ), relationalExpression( _relationalExpression ), type( _type )
{
	nodeData = toOperations();
}

ASTData* EqualityExpressionNode::toOperations()
{
	ASTData* data = new ASTData();

	if( equalityExpression == 0 )

		return relationalExpression->nodeData;

	data->code->insert( data->code->end() , equalityExpression->nodeData->code->begin() , equalityExpression->nodeData->code->end() );

	data->code->insert( data->code->end() , relationalExpression->nodeData->code->begin() , relationalExpression->nodeData->code->end() );

	//create a new temporary name
	std::string tempName = std::string("t") + std::to_string( IdTracker::getInstance()->getId() );

	//get the name of the first parameters temporary
	Symbol* compareresult = new Symbol( tempName , *new SymbolLocation() , equalityExpression->nodeData->result->symbolType , Symbol::ITEMP );

	AddOp* sub = new AddOp( compareresult , equalityExpression->nodeData->result , relationalExpression->nodeData->result , AdditiveExpressionNode::Subtract );

	data->code->push_back(sub);

	data->result = compareresult;

	return data;
}


std::string EqualityExpressionNode::getNodeTypeAsString()
{

	return std::string( "equality expression" );

}

EqualityExpressionNode::~EqualityExpressionNode()
{

}
