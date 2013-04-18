/*
 * ShiftExpressionNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef SHIFTEXPRESSIONNODE_H_
#define SHIFTEXPRESSIONNODE_H_

#include "AdditiveExpressionNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class AdditiveExpressionNode;

class ShiftExpressionNode : public Node
{

public:

	enum ShiftExpressionType
	{
		Left,
		Right
	};

	ShiftExpressionNode( AdditiveExpressionNode* _additiveExpression );

	ShiftExpressionNode( ShiftExpressionNode* _shiftExpression ,
			AdditiveExpressionNode* _additiveExpression ,
			ShiftExpressionType _type
			);

	ASTData* toOperations();

	std::string getNodeTypeAsString();

	AdditiveExpressionNode* additiveExpression = 0;
	ShiftExpressionNode* shiftExpression = 0;
	ShiftExpressionType type;

};


#endif /* SHIFTEXPRESSIONNODE_H_ */
