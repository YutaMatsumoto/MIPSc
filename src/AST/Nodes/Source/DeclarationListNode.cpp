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



std::vector< Operation* >* DeclarationListNode::toOperations()
{
	std::vector< Operation* >* operations;

	return operations;
}

//~PrimaryExpressionNode(){}

std::string DeclarationListNode::getNodeTypeAsString()
{

	return std::string( "unary operator" );

}


