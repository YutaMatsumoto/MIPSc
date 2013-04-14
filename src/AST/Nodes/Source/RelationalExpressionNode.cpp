/*
 * RelationalExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "RelationalExpressionNode.h"

RelationalExpressionNode::RelationalExpressionNode( ShiftExpressionNode* _shiftExpression ) : shiftExpression( _shiftExpression )
{

}

RelationalExpressionNode::RelationalExpressionNode( RelationalExpressionNode* _relationalExpression ,
		ShiftExpressionNode* _shiftExpression ,
		RelationalExpressionType _type
		)
	: shiftExpression( _shiftExpression ), relationalExpression( _relationalExpression ), type( _type )
{

}

std::vector< Operation* >* RelationalExpressionNode::toOperations()
{
	std::vector< Operation* >* operations;

	return operations;
}

std::string RelationalExpressionNode::getNodeTypeAsString()
{

	return std::string( "relational expression" );

}

