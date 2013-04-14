/*
 * PostfixExpressionNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef POSTFIXEXPRESSIONNODE_H_
#define POSTFIXEXPRESSIONNODE_H_

#include "PrimaryExpressionNode.h"
#include "ArgExpressionListNode.h"
#include "IdentifierNode.h"
#include "ExpressionNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class ArgExpressionListNode;
class ExpressionNode;
class PrimaryExpressionNode;

class PostfixExpressionNode : public Node
{

public:

	enum PostfixExpressionType
	{
		PrimaryExpression,
		ArrayAccess,
		FunctionCall,
		DirectMemberAccess,
		PointerMemberAccess,
		Increment,
		Decrement
	};

	//Primary Expression
	PostfixExpressionNode( PrimaryExpressionNode* _primaryExpression );
	//Array Access
	PostfixExpressionNode( PostfixExpressionNode* _postfixExpression , ExpressionNode* arrayExpression );
	//Function Call, No arguments =OR= Increment =OR= Dcrement
	PostfixExpressionNode( PostfixExpressionNode* _postfixExpression , PostfixExpressionType _type );
	//Function Call, w/ arguments
	PostfixExpressionNode( PostfixExpressionNode* _postfixExpression , ArgExpressionListNode* _argExpressionList );
	//Direct Member Access
	PostfixExpressionNode( PostfixExpressionNode* _postfixExpression , IdentifierNode* _memberIdentifier , PostfixExpressionType _type );
	std::vector< Operation* >* toOperations();
	std::string getNodeTypeAsString();

	PostfixExpressionType type;

	PrimaryExpressionNode* primaryExpression;
	PostfixExpressionNode* postfixExpression;
	ArgExpressionListNode* argExpressionList;
	IdentifierNode* memberIdentifier;
	ExpressionNode* arrayExpression;


};


#endif /* POSTFIXEXPRESSIONNODE_H_ */
