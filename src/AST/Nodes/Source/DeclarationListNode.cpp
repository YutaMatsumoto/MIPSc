/*
 * DeclarationListNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "DeclarationListNode.h"

DeclarationListNode::DeclarationListNode()
{

}



ASTData* DeclarationListNode::toOperations()
{
	ASTData* data = new ASTData();

	return data;
}

//~PrimaryExpressionNode(){}

std::string DeclarationListNode::getNodeTypeAsString()
{

	return std::string( "unary operator" );

}


