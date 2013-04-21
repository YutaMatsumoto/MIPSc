#include "InitializerListNode.h"

InitializerListNode::InitializerListNode(InitializerNode* initNode)
{
	initializerList.push_back(initNode);
}

InitializerListNode::InitializerListNode(InitializerNode* initNode, InitializerListNode* initListNode)
{
	initializerList.push_back(initNode);
	for (size_t i = 0; i <initListNode->initializerList.size(); i++ )	{
		initializerList.push_back( initListNode->initializerList[i] );
	}
}


size_t InitializerListNode::size()
{ 
	return initializerList.size(); 
}
