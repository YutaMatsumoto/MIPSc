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

ASTData* ExternalDeclarationNode::toOperations()
{
	ASTData* data = new ASTData();

	return data;
}

std::string ExternalDeclarationNode::getNodeTypeAsString()
{

	return std::string( "primary expression" );

}


