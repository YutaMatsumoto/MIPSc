#include "DeclaratorNode.h"

std::string DeclaratorNode::toString() const
{
	return dirDeclNode->toString();
}
DeclaratorNode::DeclaratorNode(DirectDeclaratorNode* dirDeclNode) : dirDeclNode(dirDeclNode), ptrNode(NULL)
{
	nodeData = toOperations();
}

DeclaratorNode::DeclaratorNode(PointerNode* ptrNode, DirectDeclaratorNode* dirDeclNode) : dirDeclNode(dirDeclNode), ptrNode(ptrNode)
{
	nodeData = toOperations();

}

bool DeclaratorNode::isPointer()
{
	return ( ptrNode != NULL );
}

ASTData* DeclaratorNode::toOperations()
{
	return dirDeclNode->nodeData;
}

std::string DeclaratorNode::getNodeTypeAsString()
{
	return std::string("initializer node");
}

