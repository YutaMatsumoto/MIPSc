/*
 * AdditiveExpressionNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef ADDITIVEEXPRESSIONNODE_H_
#define ADDITIVEEXPRESSIONNODE_H_

#include "MultiplicativeExpressionNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class MultiplicativeExpressionNode;

class AdditiveExpressionNode : public Node
{

public:

	enum AdditiveExpressionType
	{
		Add,
		Subtract
	};

	AdditiveExpressionNode( MultiplicativeExpressionNode* _multiplicativeExpression );

	AdditiveExpressionNode( AdditiveExpressionNode* _additiveExpression ,
			MultiplicativeExpressionNode* _multiplicativeExpression ,
			AdditiveExpressionType _type
			);

	ASTData* toOperations();

	std::string getNodeTypeAsString();

	~AdditiveExpressionNode();

	AdditiveExpressionNode* additiveExpression = 0;
	MultiplicativeExpressionNode* multiplicativeExpression = 0;
	AdditiveExpressionType type;


};


#endif /* ADDITIVEEXPRESSIONNODE_H_ */
