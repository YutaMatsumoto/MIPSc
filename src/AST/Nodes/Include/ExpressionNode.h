/*
 * ExpressionNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef EXPRESSIONNODE_H_
#define EXPRESSIONNODE_H_

#include "AssignmentExpressionNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class AssignmentExpressionNode;

class ExpressionNode : public Node
{

public:

	ExpressionNode( AssignmentExpressionNode* _assignmentExpression );

	ExpressionNode(
			ExpressionNode* _expression,
			AssignmentExpressionNode* _assignmentExpression
		);
	ASTData* toOperations();
	std::string getNodeTypeAsString();
	~ExpressionNode();

	AssignmentExpressionNode* assignmentExpression = 0;
	ExpressionNode* expression = 0;

};


#endif /* EXPRESSIONNODE_H_ */
