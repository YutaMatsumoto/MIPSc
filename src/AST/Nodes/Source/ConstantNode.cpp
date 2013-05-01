/*
 * ConstantNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "ConstantNode.h"

#include "BuiltinType.h"

ConstantNode::ConstantNode( IntegerConstantNode* _intConstant ) : intConstant( _intConstant )
{
	nodeData = toOperations();
}

ConstantNode::ConstantNode( FloatConstantNode* _floatConstant ) : floatConstant( _floatConstant )
{
	nodeData = toOperations();
}

ConstantNode::ConstantNode( CharConstantNode* _charConstant ) : charConstant( _charConstant )
{
	nodeData = toOperations();
}

ASTData* ConstantNode::toOperations()
{
	if( intConstant )
	{

		return intConstant->nodeData;

	}
	if( floatConstant )
	{

		return floatConstant->nodeData;

	}
	if( charConstant )
	{

		return charConstant->nodeData;

	}

}

std::string ConstantNode::getNodeTypeAsString()
{

	return std::string( "constant" );

}

ConstantNode::~ConstantNode()
{

}
