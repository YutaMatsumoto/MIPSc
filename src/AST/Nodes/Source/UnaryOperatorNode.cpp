/*
 * UnaryOperatorNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "UnaryOperatorNode.h"

UnaryOperatorNode::UnaryOperatorNode( UnaryOperatorType _type ) : type( _type )
{
	nodeData = toOperations();
}

ASTData* UnaryOperatorNode::toOperations()
{
	ASTData* data = new ASTData();

	return data;
}


std::string UnaryOperatorNode::getNodeTypeAsString()
{

	return std::string( "unary operator" );

}

