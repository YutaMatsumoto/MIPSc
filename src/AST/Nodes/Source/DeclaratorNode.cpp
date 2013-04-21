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
