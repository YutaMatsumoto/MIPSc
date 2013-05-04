/*
 * IdentifierNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "IdentifierNode.h"
#include "SymbolTableInfo.h"
#include "SymbolNotFoundException.h"

#include "LoadOp.h"
#include "GetAddressOp.h"
#include "IdTracker.h"

IdentifierNode::IdentifierNode( SymbolTable* _table , std::string _id , bool _declarationMode ) : id( _id ), table( _table), declarationMode(_declarationMode)
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

	if( !identifier )

		throw new SymbolNotFoundException( "Symbol '" + id + "' has not been declared" );

	//create a new temporary for our result
	Symbol* temporary = new Symbol( tempName , *new SymbolLocation() , identifier->symbolType , identifier->operandType );

	GetAddressOp* op1 = new GetAddressOp( temporary , identifier );

	//create a new operation to compute the addition
	//LoadOp* op2 = new LoadOp( temporary , temporary );

	operations->push_back( op1 );

	//operations->push_back( op2 );

	data->code = operations;

	data->result = temporary;

	return data;

}

std::string IdentifierNode::getNodeTypeAsString()
{

	return std::string( "identifier" );

}

