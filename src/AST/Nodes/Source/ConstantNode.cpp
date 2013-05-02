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

}

ConstantNode::ConstantNode( FloatConstantNode* _floatConstant ) : floatConstant( _floatConstant )
{

}

ConstantNode::ConstantNode( CharConstantNode* _charConstant ) : charConstant( _charConstant )
{

}

ASTData* ConstantNode::toOperations()
{
	if( intConstant )
	{

		return intConstant->toOperations();

	}
	if( floatConstant )
	{

		return floatConstant->toOperations();

	}
	if( charConstant )
	{

		return charConstant->toOperations();

	}

}

std::string ConstantNode::getNodeTypeAsString()
{

	return std::string( "constant" );

}

ConstantNode::~ConstantNode()
{

}
