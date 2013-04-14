/*
 * PrimaryExpressionNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef PRIMARYEXPRESSIONNODE_H_
#define PRIMARYEXPRESSIONNODE_H_

#include "IdentifierNode.h"
#include "ConstantNode.h"
#include "StringNode.h"
#include "ExpressionNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class ExpressionNode;

class PrimaryExpressionNode : public Node
{

public:

	PrimaryExpressionNode( IdentifierNode* _identifier );
	PrimaryExpressionNode( ConstantNode* _constant );
	PrimaryExpressionNode( StringNode* _string );
	PrimaryExpressionNode( ExpressionNode* _expression );
	std::vector< Operation* >* toOperations();
	std::string getNodeTypeAsString();

	IdentifierNode* identifier;
	ConstantNode* constant;
	StringNode* string;
	ExpressionNode* expression;

};


#endif /* PRIMARYEXPRESSIONNODE_H_ */
