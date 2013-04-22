/*
 * InitializerNode.cpp
 *
 *  Created on: Apr 21, 2013
 *      Author: njordan
 */

#include "InitializerNode.h"

InitializerNode::InitializerNode(AssignmentExpressionNode* _assignmentExpression) : assignmentExpression(_assignmentExpression)
{

}

InitializerNode::InitializerNode(InitializerListNode* _initializerList) : initializerList(_initializerList)
{

}

ASTData* InitializerNode::toOperations()
{
	ASTData* data = new ASTData();

	if( assignmentExpression != 0 )

		return assignmentExpression->toOperations();

	return data;
}

std::string InitializerNode::getNodeTypeAsString()
{
	return std::string("initializer node");
}

