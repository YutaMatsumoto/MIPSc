/*
 * CastExpressionNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef CASTEXPRESSIONNODE_H_
#define CASTEXPRESSIONNODE_H_

#include "UnaryExpressionNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class UnaryExpressionNode;
class TypeNameNode;

class CastExpressionNode : public Node
{

public:

	CastExpressionNode( UnaryExpressionNode* _unaryExpression );

	CastExpressionNode( TypeNameNode* _typeName , CastExpressionNode* _castExpression );

	ASTData* toOperations();

	std::string getNodeTypeAsString();

	UnaryExpressionNode* unaryExpression = 0;

	TypeNameNode* typeName = 0;
	CastExpressionNode* castExpression = 0;

};



#endif /* CASTEXPRESSIONNODE_H_ */
