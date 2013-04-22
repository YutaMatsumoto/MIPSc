/*
 * DeclaratorNode.cpp
 *
 *  Created on: Apr 21, 2013
 *      Author: njordan
 */

#include "DeclaratorNode.h"

DeclaratorNode::DeclaratorNode(DirectDeclaratorNode* dirDeclNode) : dirDeclNode(dirDeclNode), ptrNode(NULL)
{

}

DeclaratorNode::DeclaratorNode(PointerNode* ptrNode, DirectDeclaratorNode* dirDeclNode) : dirDeclNode(dirDeclNode), ptrNode(ptrNode)
{

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

