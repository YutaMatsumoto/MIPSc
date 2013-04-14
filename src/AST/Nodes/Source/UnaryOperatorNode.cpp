/*
 * UnaryOperatorNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "UnaryOperatorNode.h"

UnaryOperatorNode::UnaryOperatorNode( UnaryOperatorType _type ) : type( _type )
{

}

std::vector< Operation* >* UnaryOperatorNode::toOperations()
{

	std::vector< Operation* >* operations;

	return operations;
}


std::string UnaryOperatorNode::getNodeTypeAsString()
{

	return std::string( "unary operator" );

}

