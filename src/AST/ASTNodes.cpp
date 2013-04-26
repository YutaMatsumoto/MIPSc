/*
 * ASTNodes.cpp
 *
 *  Created on: Apr 3, 2013
 *      Author: njordan
 */

#include "ASTNodes.h"

// DirectDeclaratorNode

string DirectDeclaratorNode::toString()
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

void DirectDeclaratorNode::error(string msg)
{
	cerr << "Error : DirectDeclaratorKind : " << msg << endl;
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
	array = false;
	functionCall = false;
	functionDefinition = false;

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
	array = true;
	kind = Array;
}

void DirectDeclaratorNode::specifyArray( ConstantExpressionNode* a)
{
	arraySize = a;
	array = true;
	kind = ArrayWithSize;
}

void DirectDeclaratorNode::specifyFunction( ParameterTypeListNode* a )
{
	funcParams = a;
	functionDefinition = true; // TODO is this right?
	kind = FunctionDefinitionWithParam;
}

void DirectDeclaratorNode::specifyFunctionCall( IdentifierListNode* a )
{
	functionCall = true;
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
