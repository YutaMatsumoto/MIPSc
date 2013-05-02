/*
 * AssignmentOperatorNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "AssignmentOperatorNode.h"

AssignmentOperatorNode::AssignmentOperatorNode( AssignmentOperatorType _type ) : type( _type )
{
	nodeData = toOperations();
}

ASTData* AssignmentOperatorNode::toOperations()
{
	ASTData* data = new ASTData();

	return data;
}

//~PrimaryExpressionNode(){}

std::string AssignmentOperatorNode::getNodeTypeAsString()
{

	return std::string( "assignment operator" );

}

