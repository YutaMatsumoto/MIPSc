/*
 * FloatConstantNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "FloatConstantNode.h"

FloatConstantNode::FloatConstantNode( double _value ) : value( _value )
{
	nodeData = toOperations();
}

double FloatConstantNode::getValue()
{
	return value;
}

//These handle the issue of overflow when casting
// or performing operations

bool FloatConstantNode::canBeFloat()
{

	return ( value < FLT_MAX ) ? true : false;

}

ASTData* FloatConstantNode::toOperations()
{
	ASTData* data = new ASTData();

	return data;
}

std::string FloatConstantNode::getNodeTypeAsString()
{

	return std::string( "float constant" );

}


