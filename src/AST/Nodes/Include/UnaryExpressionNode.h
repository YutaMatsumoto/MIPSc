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
#include "TypeNameNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

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
	std::vector< Operation* >* toOperations();
	std::string getNodeTypeAsString();

	PostfixExpressionNode* postfixExpression;
	UnaryExpressionNode* unaryExpression;
	UnaryOperatorNode* unaryOperator;
	CastExpressionNode* castExpression;
	TypeNameNode* typeName;

	UnaryExpressionType type;

};


#endif /* UNARYEXPRESSIONNODE_H_ */
