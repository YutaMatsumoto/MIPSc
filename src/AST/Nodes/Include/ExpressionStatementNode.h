/*
 * ExpressionStatementNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef EXPRESSIONSTATEMENTNODE_H_
#define EXPRESSIONSTATEMENTNODE_H_

#include "ExpressionNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class ExpressionStatementNode : public Node
{

public:

	ExpressionStatementNode( );
	ExpressionStatementNode( ExpressionNode* _expression );
	ASTData* toOperations();
	std::string getNodeTypeAsString();

	ExpressionNode* expression;

};


#endif /* EXPRESSIONSTATEMENTNODE_H_ */
