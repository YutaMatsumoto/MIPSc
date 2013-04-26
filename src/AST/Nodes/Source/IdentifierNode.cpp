/*
 * IdentifierNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "IdentifierNode.h"
#include "SymbolTableInfo.h"

#include "LoadOp.h"
#include "IdTracker.h"

IdentifierNode::IdentifierNode( SymbolTable* _table , std::string _id ) : id( _id ), table( _table)
{
	nodeData = toOperations();
}

std::string IdentifierNode::getId()
{
	return id;
}

Symbol* IdentifierNode::resolveSymbol()
{

	//find the symbol 'id' in the symbol table
	SymbolTableInfo info = table->getSymbolInfo( id , false );

	//return a pointer to it
	return info.symbol;

}

ASTData* IdentifierNode::toOperations()
{
	ASTData* data = new ASTData();

	std::vector< Operation* >* operations = new std::vector< Operation* >();

	//create a new temporary name
	std::string tempName = std::string("t") + std::to_string( IdTracker::getInstance()->getId() );

	Symbol* identifier = resolveSymbol();

	//create a new temporary for our result
	Symbol* temporary = new Symbol( tempName , *new SymbolLocation() , identifier->symbolType );

	//create a new operation to compute the addition
	LoadOp* op = new LoadOp( temporary , identifier );

	operations->push_back( op );

	data->code = operations;

	data->result = temporary;

	return data;
}

std::string IdentifierNode::getNodeTypeAsString()
{

	return std::string( "identifier" );

}

