/*
 * AndExpressionNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef ANDEXPRESSIONNODE_H_
#define ANDEXPRESSIONNODE_H_

#include "EqualityExpressionNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class EqualityExpressionNode;

class AndExpressionNode : public Node
{

public:

	AndExpressionNode( EqualityExpressionNode* _equalityExpression );

	AndExpressionNode( AndExpressionNode* _andExpression ,
			EqualityExpressionNode* _equalityExpression
			);

	ASTData* toOperations();

	//~PrimaryExpressionNode(){}

	std::string getNodeTypeAsString();

	~AndExpressionNode();

	AndExpressionNode* andExpression = 0;
	EqualityExpressionNode* equalityExpression = 0;

};


#endif /* ANDEXPRESSIONNODE_H_ */
