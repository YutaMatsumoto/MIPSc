/*
 * JumpStatementNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "JumpStatementNode.h"

JumpStatementNode::JumpStatementNode( ExpressionNode* _expression ) : expression( _expression )
{
	type = Return;
}

JumpStatementNode::JumpStatementNode( IdentifierNode* _identifier ) : identifier( _identifier )
{
	type = Goto;
}

JumpStatementNode::JumpStatementNode( JumpStatementType _type ) : type( _type )
{

}


std::vector< Operation* >* JumpStatementNode::toOperations()
{
	std::vector< Operation* >* operations;

	return operations;
}


std::string JumpStatementNode::getNodeTypeAsString()
{

	return std::string( "jump statement" );

}

