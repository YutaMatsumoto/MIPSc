/*
 * ConstantNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "ConstantNode.h"

ConstantNode::ConstantNode( IntegerConstantNode* _intConstant ) : intConstant( _intConstant )
{

}

ConstantNode::ConstantNode( FloatConstantNode* _floatConstant ) : floatConstant( _floatConstant )
{

}

ConstantNode::ConstantNode( CharConstantNode* _charConstant ) : charConstant( _charConstant )
{

}

std::vector< Operation* >* ConstantNode::toOperations()
{
	std::vector< Operation* >* operations;

	return operations;
}

std::string ConstantNode::getNodeTypeAsString()
{

	return std::string( "constant" );

}

ConstantNode::~ConstantNode()
{

}
