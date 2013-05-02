/*
 * LogicalAndExpressionNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef LOGICALANDEXPRESSIONNODE_H_
#define LOGICALANDEXPRESSIONNODE_H_

#include "InclusiveOrExpressionNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class InclusiveOrExpressionNode;

class LogicalAndExpressionNode : public Node
{

public:

	LogicalAndExpressionNode( InclusiveOrExpressionNode* _inclusiveOrExpression );
	LogicalAndExpressionNode( LogicalAndExpressionNode* _logicalAndExpression,
			InclusiveOrExpressionNode* _inclusiveOrExpression
			);
	ASTData* toOperations();
	std::string getNodeTypeAsString();
	~LogicalAndExpressionNode();

	InclusiveOrExpressionNode* inclusiveOrExpression = 0;
	LogicalAndExpressionNode* logicalAndExpression = 0;

};


#endif /* LOGICALANDEXPRESSIONNODE_H_ */
