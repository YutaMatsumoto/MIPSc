#include "InitDeclaratorNode.h"
#include "StoreOp.h"
#include "IdTracker.h"
#include "GetAddressOp.h"

InitDeclaratorNode::InitDeclaratorNode(DeclaratorNode* _declarationNode , SymbolTable* _table) : declarationNode(_declarationNode), table(_table)
{
	nodeData = toOperations();
}

InitDeclaratorNode::InitDeclaratorNode(DeclaratorNode* _declarationNode, InitializerNode* _initializerNode , SymbolTable* _table) : declarationNode(_declarationNode), initializerNode(_initializerNode), table(_table)
{
	nodeData = toOperations();
}

ASTData* InitDeclaratorNode::toOperations()
{
	ASTData* data = new ASTData();

	//Symbol::TACOperandType tacType = ( table->isGlobalScope() ) ? Symbol::GLOB : Symbol::LOCAL;

	//declarationNode->nodeData->result->operandType = tacType;

	if( initializerNode != 0 )
	{

		std::vector< Operation* >* operations = new std::vector< Operation* >();

		//Gets the data for the first parameter
		ASTData* declaratorData = declarationNode->nodeData;

		//gets the data for the second parameter
		ASTData* initializerData = initializerNode->nodeData;

		//create a new temporary name
		std::string tempName = std::string("t") + std::to_string( IdTracker::getInstance()->getId() );

		//get the name of the first parameters temporary
		Symbol* declaratorResult = declaratorData->result;

		//get the name of the second parameters temporary
		Symbol* initializerResult = initializerData->result;

		//create a new temporary for our result
		Symbol* temporary = new Symbol( tempName , *new SymbolLocation() , declaratorResult->symbolType , declarationNode->nodeData->result->operandType );

		GetAddressOp* op1 = new GetAddressOp( temporary , declaratorResult );

		//create a new operation to compute the addition
		StoreOp* op2 = new StoreOp( temporary , initializerResult );

		//Add the multiplicative operations to what we will return
		//operations->insert( operations->end() , multiplicativeData->code->begin() , multiplicativeData->code->end() );

		//add the additive the multiplicative operations to what we will return
		operations->insert( operations->end() , initializerData->code->begin() , initializerData->code->end() );

		//Add our 'add' operation to the end of the list
		operations->push_back( op1 );

		operations->push_back( op2 );

		//add the result of this expression to the data
		//data->result = temporary;

		//add the code used to compute this result
		data->code = operations;

	}

	data->value = declarationNode->nodeData->value;

	return data;
}

std::string InitDeclaratorNode::getNodeTypeAsString()
{

	return std::string( "init declarator node" );

}
