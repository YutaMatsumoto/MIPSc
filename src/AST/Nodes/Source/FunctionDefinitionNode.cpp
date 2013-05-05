/*
 * FunctionDefinitionNode.cpp
 *
 *  Created on: Apr 16, 2013
 *      Author: njordan
 */

#include "FunctionDefinitionNode.h"
#include "IdTracker.h"

FunctionDefinitionNode::FunctionDefinitionNode( CompoundStatementNode* _compoundStatement, DeclaratorNode* _declarator ) : compoundStatement(_compoundStatement), declarator(_declarator) {
	nodeData = toOperations();
}

ASTData* FunctionDefinitionNode::toOperations()
{

	ASTData* data = new ASTData();

	std::vector< Operation* >* operations = new std::vector< Operation* >();

	Label* functionLabel = new Label( declarator->nodeData->result->getId() , IdTracker::getInstance()->getId() );

	operations->push_back( functionLabel );

	operations->insert( operations->end() , compoundStatement->nodeData->code->begin() , compoundStatement->nodeData->code->end() );

	data->code = operations;

	return data;

}

std::string FunctionDefinitionNode::getNodeTypeAsString()
{

	return std::string( "function definition" );

}
