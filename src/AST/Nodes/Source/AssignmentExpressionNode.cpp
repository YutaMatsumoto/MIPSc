/*
 * AssignmentExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "AssignmentExpressionNode.h"

AssignmentExpressionNode::AssignmentExpressionNode( ConditionalExpressionNode* _conditionalExpression ) : conditionalExpression( _conditionalExpression )
{

}

AssignmentExpressionNode::AssignmentExpressionNode(
		UnaryExpressionNode* _unaryExpression,
		AssignmentOperatorNode* _assignmentOperator,
		AssignmentExpressionNode* _assignmentExpression
	) : unaryExpression( _unaryExpression ), assignmentOperator(_assignmentOperator), assignmentExpression(_assignmentExpression)
{

}


std::vector< Operation* >* AssignmentExpressionNode::toOperations()
{
	std::vector< Operation* >* operations;

	return operations;
}

std::string AssignmentExpressionNode::getNodeTypeAsString()
{

	return std::string( "conditional expression" );

}

AssignmentExpressionNode::~AssignmentExpressionNode() {}

