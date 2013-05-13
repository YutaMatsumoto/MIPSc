/*
 * ExternalDeclarationNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "ExternalDeclarationNode.h"

ExternalDeclarationNode::ExternalDeclarationNode( FunctionDefinitionNode* _functionDefinition ): functionDefinition(_functionDefinition)
{
	nodeData = toOperations();
}

ASTData* ExternalDeclarationNode::toOperations()
{
	ASTData* data = new ASTData();

	if( declaration )

		return declaration->nodeData;

	if( functionDefinition )

		return functionDefinition->nodeData;

	return data;
}

std::string ExternalDeclarationNode::getNodeTypeAsString()
{

	return std::string( "primary expression" );

}


