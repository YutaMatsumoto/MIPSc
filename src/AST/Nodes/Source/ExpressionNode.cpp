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


std::vector< Operation* >* ExpressionNode::toOperations()
{
	std::vector< Operation* >* operations;

	return operations;
}

std::string ExpressionNode::getNodeTypeAsString()
{

	return std::string( "expression" );

}

ExpressionNode::~ExpressionNode()
{

}


