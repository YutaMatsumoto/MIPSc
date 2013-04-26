/*
 * InitializerNode.cpp
 *
 *  Created on: Apr 21, 2013
 *      Author: njordan
 */

#include "InitializerNode.h"

InitializerNode::InitializerNode(AssignmentExpressionNode* _assignmentExpression) : assignmentExpression(_assignmentExpression)
{
	nodeData = toOperations();
}

InitializerNode::InitializerNode(InitializerListNode* _initializerList) : initializerList(_initializerList)
{
	nodeData = toOperations();
}

ASTData* InitializerNode::toOperations()
{
	ASTData* data = new ASTData();

	if( assignmentExpression != 0 )

		return assignmentExpression->nodeData;

	return data;
}

std::string InitializerNode::getNodeTypeAsString()
{
	return std::string("initializer node");
}

