/*
 * ConstantExpressionNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef CONSTANTEXPRESSIONNODE_H_
#define CONSTANTEXPRESSIONNODE_H_

#include "ConditionalExpressionNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class ConstantExpressionNode : public Node
{

public:

	ConstantExpressionNode( ConditionalExpressionNode* _conditionalExpression );

	std::vector< Operation* >* toOperations();

	std::string getNodeTypeAsString();

	ConditionalExpressionNode* conditionalExpression;

	~ConstantExpressionNode();

};


#endif /* CONSTANTEXPRESSIONNODE_H_ */
