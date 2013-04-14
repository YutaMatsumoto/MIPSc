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

	LogicalAndExpressionNode( InclusiveOrExpressionNode* _inclusiveOrExpressionNode );
	LogicalAndExpressionNode( LogicalAndExpressionNode* _logicalAndExpression,
			InclusiveOrExpressionNode* _inclusiveOrExpressionNode
			);
	std::vector< Operation* >* toOperations();
	std::string getNodeTypeAsString();
	~LogicalAndExpressionNode();

	InclusiveOrExpressionNode* inclusiveOrExpressionNode;
	LogicalAndExpressionNode* logicalAndExpression;

};


#endif /* LOGICALANDEXPRESSIONNODE_H_ */
