/*
 * StringNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "StringNode.h"

StringNode::StringNode( std::string _value ) : value( _value )
{
	nodeData = toOperations();
}

std::string StringNode::getValue()
{
	return value;
}

ASTData* StringNode::toOperations()
{
	ASTData* data = new ASTData();

	return data;
}

std::string StringNode::getNodeTypeAsString()
{

	return std::string( "string" );

}

