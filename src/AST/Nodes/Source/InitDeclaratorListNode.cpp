
#include "InitDeclaratorListNode.h"

InitDeclaratorListNode::InitDeclaratorListNode( InitDeclaratorListNode* _initDeclaratorList , InitDeclaratorNode* _initDeclarator) : initDeclaratorList(_initDeclaratorList) , initDeclarator(_initDeclarator)
{
	nodeData = toOperations();
}


InitDeclaratorListNode::InitDeclaratorListNode(InitDeclaratorNode* _initDeclarator) : initDeclarator(_initDeclarator)
{

	nodeData = toOperations();

}

ASTData* InitDeclaratorListNode::toOperations()
{

	if( initDeclaratorList == 0 )

		return initDeclarator->nodeData;

	else
	{

		ASTData* data = new ASTData();

		std::vector< Operation* >* operations = new std::vector< Operation* >();

		//Gets the data for the first parameter
		ASTData* initDeclaratorData = initDeclarator->nodeData;

		//gets the data for the second parameter
		ASTData* initDeclaratorListData = initDeclaratorList->nodeData;

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
		operations->insert( operations->end() , initDeclaratorListData->code->begin() , initDeclaratorListData->code->end() );

		//Add the multiplicative operations to what we will return
		operations->insert( operations->end() , initDeclaratorData->code->begin() , initDeclaratorData->code->end() );

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

std::string InitDeclaratorListNode::getNodeTypeAsString()
{

	return std::string( "init declarator list node" );

}

InitDeclaratorNodeInList InitDeclaratorListNode::toList()
{
	InitDeclaratorNodeInList list;

	InitDeclaratorListNode* iter = this;
	list.push_front(initDeclarator);
	while (iter) {
		iter = iter->initDeclaratorList;			
		list.push_front(initDeclarator);
	}

	return list;
}
