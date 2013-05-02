#include "InitializerListNode.h"

InitializerListNode::InitializerListNode(InitializerNode* initNode)
{
<<<<<<< HEAD
	initializerList.push_back(initNode);
=======
	nodeData = toOperations();
>>>>>>> nate
}

InitializerListNode::InitializerListNode(InitializerNode* initNode, InitializerListNode* initListNode)
{
<<<<<<< HEAD
	initializerList.push_back(initNode);
	for (size_t i = 0; i <initListNode->initializerList.size(); i++ )	{
		initializerList.push_back( initListNode->initializerList[i] );
	}
}


size_t InitializerListNode::size()
{ 
	return initializerList.size(); 
=======
	nodeData = toOperations();
>>>>>>> nate
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
