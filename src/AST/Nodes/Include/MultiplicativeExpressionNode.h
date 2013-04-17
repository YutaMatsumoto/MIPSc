/*
 * MultiplicativeExpressionNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef MULTIPLICATIVEEXPRESSIONNODE_H_
#define MULTIPLICATIVEEXPRESSIONNODE_H_

#include "CastExpressionNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class CastExpressionNode;

class MultiplicativeExpressionNode : public Node
{

public:

	enum MultiplicativeExpressionType
	{
		Multiply,
		Divide,
		Modulo
	};

	MultiplicativeExpressionNode( CastExpressionNode* _castExpression );
	MultiplicativeExpressionNode( MultiplicativeExpressionNode* _multiplicativeExpression ,
			CastExpressionNode* _castExpression ,
			MultiplicativeExpressionType _type
			);
	ASTData* toOperations();
	std::string getNodeTypeAsString();

	CastExpressionNode* castExpression;
	MultiplicativeExpressionNode* multiplicativeExpression;
	MultiplicativeExpressionType type;


};


#endif /* MULTIPLICATIVEEXPRESSIONNODE_H_ */
