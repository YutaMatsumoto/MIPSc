#include "InitializerListNode.h"

InitializerListNode::InitializerListNode(InitializerNode* initNode)
{

	initializerList.push_back(initNode);

	nodeData = toOperations();

}

InitializerListNode::InitializerListNode(InitializerNode* initNode, InitializerListNode* initListNode)
{

	initializerList.push_back(initNode);
	for (size_t i = 0; i <initListNode->initializerList.size(); i++ )	{
		initializerList.push_back( initListNode->initializerList[i] );
	}

	nodeData = toOperations();

}


size_t InitializerListNode::size()
{ 
	return initializerList.size(); 

}

ASTData* InitializerListNode::toOperations()
{
	ASTData* data = new ASTData();

	return data;
}

std::string InitializerListNode::getNodeTypeAsString()
{
	return std::string("initializer list node");
}
