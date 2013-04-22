#include "DeclaratorNode.h"
#include "DeclaratorNode.h"

bool DeclaratorNode::isPointer()
{
	return (ptrNode!=NULL);
}

std::string DeclaratorNode::toString() const
{
	return dirDeclNode->toString();
}

bool DeclaratorNode::isPointer()
{
	return ( ptrNode != NULL );
}

ASTData* DeclaratorNode::toOperations()
{
	return dirDeclNode->toOperations();
}

std::string DeclaratorNode::getNodeTypeAsString()
{
	return std::string("initializer node");
}

