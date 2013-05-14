/*
 * FunctionDefinitionNode.cpp
 *
 *  Created on: Apr 16, 2013
 *      Author: njordan
 */

#include "FunctionDefinitionNode.h"
#include "IdTracker.h"
#include "FunctionType.h"
#include "BuiltinType.h"
#include "DeclarationListNode.h"

FunctionDefinitionNode::FunctionDefinitionNode( DeclarationSpecifiersNode* _declarationSpecifiers , CompoundStatementNode* _compoundStatement, DeclaratorNode* _declarator ) : declarationSpecifiers(_declarationSpecifiers ), compoundStatement(_compoundStatement), declarator(_declarator) {

	declareFunction();

	nodeData = toOperations();

}

FunctionDefinitionNode::FunctionDefinitionNode(
		DeclarationSpecifiersNode* _declarationSpecifiers ,
		CompoundStatementNode* _compoundStatement,
		DeclaratorNode* _declarator,
		DeclarationListNode* _declarationList
) : declarationSpecifiers(_declarationSpecifiers ), compoundStatement(_compoundStatement), declarator(_declarator),declarationList(_declarationList) {

	declareFunction();

	nodeData = toOperations();

}

FunctionDefinitionNode::FunctionDefinitionNode( CompoundStatementNode* _compoundStatement, DeclaratorNode* _declarator ) : compoundStatement(_compoundStatement), declarator(_declarator) {

	declareFunction();

	nodeData = toOperations();

}

ASTData* FunctionDefinitionNode::toOperations()
{

	ASTData* data = new ASTData();

	std::vector< Operation* >* operations = new std::vector< Operation* >();

	Label* functionLabel = new Label( declarator->nodeData->result->getId() , IdTracker::getInstance()->getId() );

	operations->push_back( functionLabel );

	operations->insert( operations->end() , compoundStatement->nodeData->code->begin() , compoundStatement->nodeData->code->end() );

	declarator->nodeData->result->operandType = Symbol::LABEL;

	data->code = operations;

	return data;

}

std::string FunctionDefinitionNode::getNodeTypeAsString()
{

	return std::string( "function definition" );

}

void FunctionDefinitionNode::declareFunction()
{

	FunctionType* t = new FunctionType();

	t->setReturnType( new BuiltinType( Type::Int ) );

	DeclarationListNode* i = declarationList;

	while( i )
	{


		i = i->declarationList;

	}

}
