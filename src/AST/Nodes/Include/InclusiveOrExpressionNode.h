/*
 * InclusiveOrExpressionNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef INCLUSIVEOREXPRESSIONNODE_H_
#define INCLUSIVEOREXPRESSIONNODE_H_

#include "ExclusiveOrExpressionNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class ExclusiveOrExpressionNode;

class InclusiveOrExpressionNode : public Node
{

public:

	InclusiveOrExpressionNode( ExclusiveOrExpressionNode* _exclusiveOrExpression );
	InclusiveOrExpressionNode( InclusiveOrExpressionNode* _inclusiveOrExpression ,
			ExclusiveOrExpressionNode* _exclusiveOrExpression
			);
	ASTData* toOperations();
	std::string getNodeTypeAsString();

	~InclusiveOrExpressionNode();

	InclusiveOrExpressionNode* inclusiveOrExpression;
	ExclusiveOrExpressionNode* exclusiveOrExpression;

};


#endif /* INCLUSIVEOREXPRESSIONNODE_H_ */
