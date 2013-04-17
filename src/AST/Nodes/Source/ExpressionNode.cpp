/*
 * ExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "ExpressionNode.h"

ExpressionNode::ExpressionNode( AssignmentExpressionNode* _assignmentExpression ) : assignmentExpression( _assignmentExpression )
{

}

ExpressionNode::ExpressionNode(
		ExpressionNode* _expression,
		AssignmentExpressionNode* _assignmentExpression
	) : expression( _expression ), assignmentExpression(_assignmentExpression)
{

}


ASTData* ExpressionNode::toOperations()
{
	ASTData* data = new ASTData();

	return data;
}

std::string ExpressionNode::getNodeTypeAsString()
{

	return std::string( "expression" );

}

ExpressionNode::~ExpressionNode()
{

}


