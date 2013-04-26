#include "InitDeclaratorNode.h"
#include "StoreOp.h"
#include "common.h"
#include "AllASTNodes.h"

std::string InitDeclaratorNode::toString()
{
	string s = "InitDeclaratorNode: " + declarationNode->toString();
	return s;
}

ASTData* InitDeclaratorNode::toOperations()
{
	ASTData* data = new ASTData();

	if( initializerNode != 0 )
	{

		std::vector< Operation* >* operations = new std::vector< Operation* >();

		//Gets the data for the first parameter
		ASTData* declaratorData = declarationNode->toOperations();

		//gets the data for the second parameter
		ASTData* initializerData = initializerNode->toOperations();

		//create a new temporary name
		//std::string tempName = std::string("t") + std::to_string( IdTracker::getInstance()->getId() );

		//get the name of the first parameters temporary
		Symbol* declaratorResult = declaratorData->result;

		//get the name of the second parameters temporary
		Symbol* initializerResult = initializerData->result;

		//create a new temporary for our result
		//Symbol* temporary = new Symbol( tempName , *new SymbolLocation() , multiplicativeResult->symbolType );

		//create a new operation to compute the addition
		StoreOp* op = new StoreOp( declaratorResult , initializerResult );

		//Add the multiplicative operations to what we will return
		//operations->insert( operations->end() , multiplicativeData->code->begin() , multiplicativeData->code->end() );

		//add the additive the multiplicative operations to what we will return
		operations->insert( operations->end() , initializerData->code->begin() , initializerData->code->end() );

		//Add our 'add' operation to the end of the list
		operations->push_back( op );

		//add the result of this expression to the data
		//data->result = temporary;

		//add the code used to compute this result
		data->code = operations;

	}

	return data;
}

std::string InitDeclaratorNode::getNodeTypeAsString()
{

	return std::string( "init declarator node" );

}