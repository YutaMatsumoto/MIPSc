/*
 * ArgExpressionListNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "ArgExpressionListNode.h"

ArgExpressionListNode::ArgExpressionListNode( AssignmentExpressionNode* _assignmentExpression )
	: assignmentExpression( _assignmentExpression )
{
	nodeData = toOperations();
}

ArgExpressionListNode::ArgExpressionListNode( ArgExpressionListNode* _argumentExpressionList, AssignmentExpressionNode* _assignmentExpression )
	: assignmentExpression( _assignmentExpression ), argumentExpressionList( _argumentExpressionList )
{
	nodeData = toOperations();
}

ASTData* ArgExpressionListNode::toOperations()
{
	ASTData* data = new ASTData();

	return data;
}

std::string ArgExpressionListNode::getNodeTypeAsString()
{

	return std::string( "argument expression list" );

}

ArgExpressionListNode::~ArgExpressionListNode(){}


