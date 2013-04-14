/*
 * StringNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "StringNode.h"

StringNode::StringNode( std::string _value ) : value( _value )
{

}

std::string StringNode::getValue()
{
	return value;
}

std::vector< Operation* >* StringNode::toOperations()
{
	std::vector< Operation* >* operations;

	return operations;
}

std::string StringNode::getNodeTypeAsString()
{

	return std::string( "string" );

}

