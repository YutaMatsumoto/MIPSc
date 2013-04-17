/*
 * FunctionDefinitionNode.cpp
 *
 *  Created on: Apr 16, 2013
 *      Author: njordan
 */

#include "FunctionDefinitionNode.h"

FunctionDefinitionNode::FunctionDefinitionNode( CompoundStatementNode* _compoundStatement ) : compoundStatement(_compoundStatement) {
	// TODO Auto-generated constructor stub

}

ASTData* FunctionDefinitionNode::toOperations()
{

	return compoundStatement->toOperations();

}

std::string FunctionDefinitionNode::getNodeTypeAsString()
{

	return std::string( "function definition" );

}
