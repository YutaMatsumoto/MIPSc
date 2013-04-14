/*
 * IntegerConstantNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "IntegerConstantNode.h"

IntegerConstantNode::IntegerConstantNode( long long int _value ) : value( _value )
{

}

long long int IntegerConstantNode::getValue()
{
	return value;
}

std::vector< Operation* >* IntegerConstantNode::toOperations()
{
	std::vector< Operation* >* operations;

	return operations;
}

std::string IntegerConstantNode::getNodeTypeAsString()
{

	return std::string( "integer constant" );

}


