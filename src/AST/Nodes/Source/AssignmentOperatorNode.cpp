/*
 * AssignmentOperatorNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "AssignmentOperatorNode.h"

AssignmentOperatorNode::AssignmentOperatorNode( AssignmentOperatorType _type ) : type( _type )
{

}

std::vector< Operation* >* AssignmentOperatorNode::toOperations()
{
	std::vector< Operation* >* operations;

	return operations;
}

//~PrimaryExpressionNode(){}

std::string AssignmentOperatorNode::getNodeTypeAsString()
{

	return std::string( "assignment operator" );

}

