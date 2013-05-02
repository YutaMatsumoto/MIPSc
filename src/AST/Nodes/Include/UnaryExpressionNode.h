/*
 * UnaryExpressionNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef UNARYEXPRESSIONNODE_H_
#define UNARYEXPRESSIONNODE_H_

#include "PostfixExpressionNode.h"
#include "UnaryOperatorNode.h"
#include "CastExpressionNode.h"
#include "AllASTNodes.h"
// #include "TypeNameNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class TypeNameNode;

class CastExpressionNode;
class PostfixExpressionNode;

class UnaryExpressionNode : public Node
{

public:

	enum UnaryExpressionType
	{
		Postfix,
		Increment,
		Decrement,
		Cast,
		SizeofExpression,
		SizeofType
	};

	UnaryExpressionNode( PostfixExpressionNode* _postfixExpression );
	UnaryExpressionNode( UnaryExpressionNode* _unaryExpression , UnaryExpressionType _type );
	UnaryExpressionNode( UnaryOperatorNode* _unaryOperator , CastExpressionNode* _castExpression );

	UnaryExpressionNode( TypeNameNode* _typeName );
	ASTData* toOperations();
	std::string getNodeTypeAsString();

	PostfixExpressionNode* postfixExpression = 0;
	UnaryExpressionNode* unaryExpression = 0;
	UnaryOperatorNode* unaryOperator = 0;
	CastExpressionNode* castExpression = 0;
	TypeNameNode* typeName = 0;

	UnaryExpressionType type;

};


#endif /* UNARYEXPRESSIONNODE_H_ */
