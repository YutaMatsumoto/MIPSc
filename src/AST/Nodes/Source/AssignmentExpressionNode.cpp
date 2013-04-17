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


ASTData* AssignmentExpressionNode::toOperations()
{
	ASTData* data = new ASTData();

	if( assignmentOperator == 0 )

		return conditionalExpression->toOperations();

	return data;
}

std::string AssignmentExpressionNode::getNodeTypeAsString()
{

	return std::string( "conditional expression" );

}

AssignmentExpressionNode::~AssignmentExpressionNode() {}

