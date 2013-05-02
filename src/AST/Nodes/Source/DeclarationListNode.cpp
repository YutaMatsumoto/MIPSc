/*
 * DeclarationListNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "DeclarationListNode.h"
#include "DeclarationNode.h"

DeclarationListNode::DeclarationListNode( DeclarationNode* _declaration ) : declaration(_declaration)
{
	nodeData = toOperations();
}

DeclarationListNode::DeclarationListNode( DeclarationListNode* _declarationList , DeclarationNode* _declaration ) : declarationList(_declarationList ), declaration(_declaration)
{
	nodeData = toOperations();
}

ASTData* DeclarationListNode::toOperations()
{
	if( declarationList == 0 )

		return declaration->nodeData;

	else
	{

		ASTData* data = new ASTData();

		std::vector< Operation* >* operations = new std::vector< Operation* >();

		//Gets the data for the first parameter
		ASTData* declarationData = declaration->nodeData;

		//gets the data for the second parameter
		ASTData* declarationListData = declarationList->nodeData;

		//create a new temporary name
		//std::string tempName = std::string("t") + std::to_string( IdTracker::getInstance()->getId() );

		//get the name of the first parameters temporary
		//Symbol* additiveResult = additiveData->result;

		//get the name of the second parameters temporary
		//Symbol* multiplicativeResult = multiplicativeData->result;

		//create a new temporary for our result
		//Symbol* temporary = new Symbol( tempName , *new SymbolLocation() , multiplicativeResult->symbolType );

		//create a new operation to compute the addition
		//AddOp* op = new AddOp( temporary , additiveResult , multiplicativeResult , type );

		//add the additive the multiplicative operations to what we will return
		operations->insert( operations->end() , declarationListData->code->begin() , declarationListData->code->end() );

		//Add the multiplicative operations to what we will return
		operations->insert( operations->end() , declarationData->code->begin() , declarationData->code->end() );

		//Add our 'add' operation to the end of the list
		//operations->push_back( op );

		//add the result of this expression to the data
		//data->result = temporary;

		//add the code used to compute this result
		data->code = operations;

		//return the result
		return data;

	}
}

//~PrimaryExpressionNode(){}

std::string DeclarationListNode::getNodeTypeAsString()
{

	return std::string( "unary operator" );

}


