/*
 * EqualityExpressionNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef EQUALITYEXPRESSIONNODE_H_
#define EQUALITYEXPRESSIONNODE_H_

#include "RelationalExpressionNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class RelationalExpressionNode;

class EqualityExpressionNode : public Node
{

public:

	enum EqualityExpressionType
	{
		Equal,
		NotEqual
	};

	EqualityExpressionNode( RelationalExpressionNode* _relationalExpression );
	EqualityExpressionNode( EqualityExpressionNode* _equalityExpression ,
			RelationalExpressionNode* _relationalExpression ,
			EqualityExpressionType _type
			);
	ASTData* toOperations();
	std::string getNodeTypeAsString();
	~EqualityExpressionNode();

	EqualityExpressionNode* equalityExpression;
	RelationalExpressionNode* relationalExpression;
	EqualityExpressionType type;

};


#endif /* EQUALITYEXPRESSIONNODE_H_ */
