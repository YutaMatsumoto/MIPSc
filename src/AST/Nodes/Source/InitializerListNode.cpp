/*
 * InitializerListNode.cpp
 *
 *  Created on: Apr 21, 2013
 *      Author: njordan
 */

#include "InitializerListNode.h"

InitializerListNode::InitializerListNode(InitializerNode* _initializerNode) : initializerNode(_initializerNode)
{
	nodeData = toOperations();
}

InitializerListNode::InitializerListNode(InitializerListNode* _initializerList , InitializerNode* _initializerNode) : initializerList(_initializerList), initializerNode(_initializerNode)
{
	nodeData = toOperations();
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


