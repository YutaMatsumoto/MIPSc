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

	std::vector< Operation* >* toOperations();

	std::string getNodeTypeAsString();

	~ConditionalExpressionNode();

	LogicalOrExpressionNode* logicalOrExpression;
	ExpressionNode* expression;
	ConditionalExpressionNode* conditionalExpression;

};


#endif /* CONDITIONALEXPRESSIONNODE_H_ */
