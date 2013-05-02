#include "InitializerNode.h"

<<<<<<< HEAD
=======
InitializerNode::InitializerNode(AssignmentExpressionNode* _assignmentExpression) : assignmentExpression(_assignmentExpression)
{
	nodeData = toOperations();
}

InitializerNode::InitializerNode(InitializerListNode* _initializerList) : initializerList(_initializerList)
{
	nodeData = toOperations();
}

>>>>>>> nate
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

