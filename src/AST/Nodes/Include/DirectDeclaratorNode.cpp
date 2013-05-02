/*
 * DirectDeclaratorNode2.cpp
 *
 *  Created on: May 1, 2013
 *      Author: njordan
 */

#include "DirectDeclaratorNode.h"

std::string DirectDeclaratorNode::toString()
{
	if (id) {
		return id->getId();
	}
	else if (dirDeclNode){
		return dirDeclNode->toString();
	}
	else {
		error("both of id and dirDeclNode is null");
		return "bad DirectDeclaratorNode";
	}
}

void DirectDeclaratorNode::error(std::string msg)
{
	std::cerr << "Error : DirectDeclaratorKind : " << msg << std::endl;
}

DirectDeclaratorNode::DirectDeclaratorNode( DirectDeclaratorNode* a)
{
	initData();
	dirDeclNode = a;
	nodeData = toOperations();
}

DirectDeclaratorNode::DirectDeclaratorNode( DeclaratorNode* _declaratorNode) : declNode(_declaratorNode)
{
	initData();
	nodeData = toOperations();
}

DirectDeclaratorNode::DirectDeclaratorNode( IdentifierNode* id )
{
	initData();
	this->id = id;
	nodeData = toOperations();
}

void DirectDeclaratorNode::initData()
{

	kind = None;

	id = NULL;
	dirDeclNode = NULL;
	declNode = NULL;
	idListNode = NULL;
	arraySize = NULL;
	funcParams = NULL;
}

void DirectDeclaratorNode::specifyArray()
{
	// TODO check existence of initializer in the upstream

	kind = Array;
}

void DirectDeclaratorNode::specifyArray( ConstantExpressionNode* a)
{
	arraySize = a;

	kind = ArrayWithSize;
}

void DirectDeclaratorNode::specifyFunction( ParameterTypeListNode* a )
{
	funcParams = a;

	kind = FunctionDefinitionWithParam;
}

void DirectDeclaratorNode::specifyFunctionCall( IdentifierListNode* a )
{

	idListNode = a;
	kind = FunctionCallWithParam;
}

int DirectDeclaratorNode::getKind()
{
	return kind;
}

ASTData* DirectDeclaratorNode::toOperations()
{

	ASTData* data = new ASTData();

	if( id )
	{

		data->result = id->resolveSymbol();

		return data;

	}

	if( declNode )

		return declNode->nodeData;

	if( dirDeclNode )

		return dirDeclNode->nodeData;

}

std::string DirectDeclaratorNode::getNodeTypeAsString()
{
	return std::string("initializer list node");
}


