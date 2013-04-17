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
/*
	std::vector< Operation* >* operations = new std::vector< Operation* >();

	//Gets the code for the first parameter
	std::vector< Operation* >* additiveOperations = additiveExpression->toOperations();

	//gets the code for the second parameter
	std::vector< Operation* >* multiplicativeOperations = multiplicativeExpression->toOperations();

	//create a new temporary name
	std::string tempName = std::string("t") + std::to_string( IdTracker::getInstance()->getId() );

	//get the name of the first parameters temporary
	Symbol* additiveResult = additiveOperations->at( additiveOperations->size() - 1 )->getOp1();

	//get the name of the second parameters temporary
	Symbol* multiplicativeResult = multiplicativeOperations->at( multiplicativeOperations->size() - 1 )->getOp1();

	//create a new temporary for our result
	Symbol* temporary = new Symbol( tempName , *new SymbolLocation() , multiplicativeResult->symbolType );

	//create a new operation to compute the addition
	AddOp* op = new AddOp( temporary , additiveResult , multiplicativeResult );

	//Add the multiplicative operations to what we will return
	operations->insert( operations->end() , multiplicativeOperations->begin() , multiplicativeOperations->end() );

	//add the additive the multiplicative operations to what we will return
	operations->insert( operations->end() , additiveOperations->begin() , additiveOperations->end() );

	//Add our 'add' operation to the end of the list
	operations->push_back( op );
*/
	//return the result
	return data;

}


std::string AdditiveExpressionNode::getNodeTypeAsString()
{

	return std::string( "additive expression" );

}

AdditiveExpressionNode::~AdditiveExpressionNode() {}
