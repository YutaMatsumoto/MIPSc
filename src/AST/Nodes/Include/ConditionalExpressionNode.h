/*
 * ConditionalExpressionNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef CONDITIONALEXPRESSIONNODE_H_
#define CONDITIONALEXPRESSIONNODE_H_

#include "LogicalOrExpressionNode.h"
#include "ExpressionNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class ExpressionNode;
class LogicalOrExpressionNode;

class ConditionalExpressionNode : public Node
{

public:

	ConditionalExpressionNode( LogicalOrExpressionNode* _logicalOrExpression );

	ConditionalExpressionNode(
			LogicalOrExpressionNode* _logicalOrExpression,
			ExpressionNode* _expression,
			ConditionalExpressionNode* _conditionalExpression
		);

	ASTData* toOperations();

	std::string getNodeTypeAsString();

	~ConditionalExpressionNode();

	LogicalOrExpressionNode* logicalOrExpression = 0;
	ExpressionNode* expression = 0;
	ConditionalExpressionNode* conditionalExpression = 0;

};


#endif /* CONDITIONALEXPRESSIONNODE_H_ */
