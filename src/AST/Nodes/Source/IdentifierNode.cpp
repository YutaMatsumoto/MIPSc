/*
 * IdentifierNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "IdentifierNode.h"

IdentifierNode::IdentifierNode( std::string _id ) : id( _id )
{

}

std::string IdentifierNode::getId()
{
	return id;
}

std::vector< Operation* >* IdentifierNode::toOperations()
{
	std::vector< Operation* >* operations;

	return operations;
}

std::string IdentifierNode::getNodeTypeAsString()
{

	return std::string( "identifier" );

}

