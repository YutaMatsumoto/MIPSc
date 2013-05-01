/*
 * RelationalExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "RelationalExpressionNode.h"

RelationalExpressionNode::RelationalExpressionNode( ShiftExpressionNode* _shiftExpression ) : shiftExpression( _shiftExpression )
{
	nodeData = toOperations();
}

RelationalExpressionNode::RelationalExpressionNode( RelationalExpressionNode* _relationalExpression ,
		ShiftExpressionNode* _shiftExpression ,
		RelationalExpressionType _type
		)
	: shiftExpression( _shiftExpression ), relationalExpression( _relationalExpression ), type( _type )
{
	nodeData = toOperations();
}

ASTData* RelationalExpressionNode::toOperations()
{
	ASTData* data = new ASTData();

	if( relationalExpression == 0 )

		return shiftExpression->nodeData;

	return data;
}

std::string RelationalExpressionNode::getNodeTypeAsString()
{

	return std::string( "relational expression" );

}

