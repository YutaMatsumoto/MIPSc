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
#include "ArrayType.h"
#include "DeclarationListNode.h"
#include "SymbolTableInfo.h"

FunctionDefinitionNode::FunctionDefinitionNode(
		DeclarationSpecifiersNode* _declarationSpecifiers ,
		CompoundStatementNode* _compoundStatement,
		DeclaratorNode* _declarator ,
		SymbolTable* _table)
: declarationSpecifiers(_declarationSpecifiers ), compoundStatement(_compoundStatement), declarator(_declarator), functionScope(_table->functionScope) {

	declareFunction( _table );

	nodeData = toOperations();

}

FunctionDefinitionNode::FunctionDefinitionNode(
		DeclarationSpecifiersNode* _declarationSpecifiers ,
		CompoundStatementNode* _compoundStatement,
		DeclaratorNode* _declarator,
		DeclarationListNode* _declarationList,
		SymbolTable* _table )
: declarationSpecifiers(_declarationSpecifiers ), compoundStatement(_compoundStatement), declarator(_declarator),declarationList(_declarationList), functionScope(_table->functionScope) {

	declareFunction( _table );

	nodeData = toOperations();

}

FunctionDefinitionNode::FunctionDefinitionNode( CompoundStatementNode* _compoundStatement,
		DeclaratorNode* _declarator ,
		SymbolTable* _table)
: compoundStatement(_compoundStatement), declarator(_declarator), functionScope(_table->functionScope) {

	declareFunction( _table );

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

void FunctionDefinitionNode::declareFunction( SymbolTable* _table )
{

	FunctionType* t = new FunctionType();

	std::string tempName("retVal");

	BuiltinType* returnType = new BuiltinType( Type::Int );

	Symbol* returnValue;

	returnValue = _table->getSymbolInfo( tempName , false ).symbol;

	//t->setReturnType( new BuiltinType( Type::Int ) );

	if( !returnValue )

		returnValue = new Symbol( std::string("retVal"),  *new SymbolLocation() , returnType , Symbol::LOCAL );

	t->returnSymbol = returnValue;

	calculateSymbolAddresses( _table , t );

	//Symbol* functionSymbol = declarator->nodeData->result;
	Symbol* functionSymbol = declarator->nodeData->result;

	functionSymbol->symbolType = t;

}

void FunctionDefinitionNode::calculateSymbolAddresses( SymbolTable* _table , FunctionType* func )
{

	unsigned int byteCounter = 0;

	Symbol* j = func->returnSymbol;

	j->addr = byteCounter;

	BuiltinType* b = dynamic_cast<BuiltinType*>( j->symbolType );

	ArrayType* t = dynamic_cast<ArrayType*>( j->symbolType );

	if( b )

		byteCounter += b->sizeInBytes();

	if( t )

		byteCounter += t->sizeInBytes();

	for( auto i : functionScope.symbolMap )
	{

		Symbol* j = i.second;

		j->addr = byteCounter;

		if( j->operandType == Symbol::VALARG || j->operandType == Symbol::REFARG )

			func->parameters.push_back( j );

		BuiltinType* b = dynamic_cast<BuiltinType*>( j->symbolType );

		ArrayType* t = dynamic_cast<ArrayType*>( j->symbolType );

		if( b )

			byteCounter += b->sizeInBytes();

		if( t )

			byteCounter += t->sizeInBytes();

	}

	func->stackFrameSize = byteCounter;

}
