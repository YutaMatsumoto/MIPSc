/*
 * ExternalDeclarationNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "ExternalDeclarationNode.h"

ExternalDeclarationNode::ExternalDeclarationNode( FunctionDefinitionNode* _functionDefinition ): functionDefinition(_functionDefinition)
{

}

ASTData* ExternalDeclarationNode::toOperations()
{
	ASTData* data = new ASTData();

	if( declaration )

		return declaration->toOperations();

	if( functionDefinition )

		return functionDefinition->toOperations();

	return data;
}

std::string ExternalDeclarationNode::getNodeTypeAsString()
{

	return std::string( "primary expression" );

}


