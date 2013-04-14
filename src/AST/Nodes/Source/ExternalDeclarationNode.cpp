/*
 * ExternalDeclarationNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "ExternalDeclarationNode.h"

ExternalDeclarationNode::ExternalDeclarationNode( )
{

}

std::vector< Operation* >* ExternalDeclarationNode::toOperations()
{
	std::vector< Operation* >* operations;

	return operations;
}

std::string ExternalDeclarationNode::getNodeTypeAsString()
{

	return std::string( "primary expression" );

}


