/*
 * AssignmentExpressionNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef ASSIGNMENTEXPRESSIONNODE_H_
#define ASSIGNMENTEXPRESSIONNODE_H_

#include "UnaryExpressionNode.h"
#include "AssignmentOperatorNode.h"
#include "ConditionalExpressionNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class UnaryExpressionNode;
class ConditionalExpressionNode;

class AssignmentExpressionNode : public Node
{

public:

	AssignmentExpressionNode( ConditionalExpressionNode* _conditionalExpression );
	AssignmentExpressionNode(
			UnaryExpressionNode* _unaryExpression,
			AssignmentOperatorNode* _assignmentOperator,
			AssignmentExpressionNode* _assignmentExpression
		);

	std::vector< Operation* >* toOperations();


	std::string getNodeTypeAsString();
	~AssignmentExpressionNode();

	UnaryExpressionNode* unaryExpression;
	AssignmentOperatorNode* assignmentOperator;
	AssignmentExpressionNode* assignmentExpression;
	ConditionalExpressionNode* conditionalExpression;

};


#endif /* ASSIGNMENTEXPRESSIONNODE_H_ */
