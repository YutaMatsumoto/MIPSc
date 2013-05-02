#include "InitializerNode.h"

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

