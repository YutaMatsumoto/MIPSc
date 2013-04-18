/*
 * ExclusiveOrExpressionNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef EXCLUSIVEOREXPRESSIONNODE_H_
#define EXCLUSIVEOREXPRESSIONNODE_H_

#include "AndExpressionNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class AndExpressionNode;

class ExclusiveOrExpressionNode: public Node {

public:

	ExclusiveOrExpressionNode(AndExpressionNode* _andExpression);

	ExclusiveOrExpressionNode(
			ExclusiveOrExpressionNode* _exclusiveOrExpression,
			AndExpressionNode* _andExpression);

	ASTData* toOperations();

	std::string getNodeTypeAsString();

	AndExpressionNode* andExpression = 0;
	ExclusiveOrExpressionNode* exclusiveOrExpression = 0;

};

#endif /* EXCLUSIVEOREXPRESSIONNODE_H_ */
