/*
 * IntegerConstantNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "IntegerConstantNode.h"

#include <vector>
#include <string>
#include "Symbol.h"
#include "Type.h"
#include "BuiltinType.h"
#include "AssignOp.h"
#include "IdTracker.h"
#include "AssignmentOperatorNode.h"

IntegerConstantNode::IntegerConstantNode( long long int _value ) : value( _value )
{
	nodeData = toOperations();
}

long long int IntegerConstantNode::getValue()
{
	return value;
}

ASTData* IntegerConstantNode::toOperations()
{
	ASTData* data = new ASTData();

	std::vector< Operation* >* operations = new std::vector< Operation* >();

	Symbol* constant = new Symbol( std::to_string( value ) , *new SymbolLocation() , new BuiltinType<long long int>( Type::LongLong , value ) );

	std::string tempName = std::string("t") + std::to_string( IdTracker::getInstance()->getId() );

	Symbol* temporary = new Symbol( tempName , *new SymbolLocation() , new BuiltinType<long long int>( Type::LongLong , value ) );

	operations->push_back( new AssignOp( temporary , constant , AssignmentOperatorNode::Assign ) );

	data->result = temporary;

	data->code = operations;

	return data;
}

std::string IntegerConstantNode::getNodeTypeAsString()
{

	return std::string( "integer constant" );

}


