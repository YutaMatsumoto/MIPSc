/*
 * ShiftExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "ShiftExpressionNode.h"

ShiftExpressionNode::ShiftExpressionNode( AdditiveExpressionNode* _additiveExpression ) : additiveExpression( _additiveExpression )
{

}

ShiftExpressionNode::ShiftExpressionNode( ShiftExpressionNode* _shiftExpression ,
		AdditiveExpressionNode* _additiveExpression ,
		ShiftExpressionType _type
		)
	: shiftExpression( _shiftExpression ), additiveExpression( _additiveExpression ), type( _type )
{

}

ASTData* ShiftExpressionNode::toOperations()
{
	ASTData* data = new ASTData();

	return data;
}

//~PrimaryExpressionNode(){}

std::string ShiftExpressionNode::getNodeTypeAsString()
{

	return std::string( "shift expression" );

}


