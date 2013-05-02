/*
 * DirectDeclaratorNode2.h
 *
 *  Created on: May 1, 2013
 *      Author: njordan
 */

#ifndef DIRECTDECLARATORNODE2_H_
#define DIRECTDECLARATORNODE2_H_

#include "Node.h"
#include "DeclaratorNode.h"
#include "ASTNodes.h"
#include <string>

class IdentifierListNode;
class ParameterTypeListNode;

class DirectDeclaratorNode : public Node {
public:

	enum DirectDeclaratorKind {
		None,
		Array,
		ArrayWithSize,
		FunctionDefinition,
		FunctionDefinitionWithParam,
		FunctionCall,
		FunctionCallWithParam
	};

	std::string toString();

	void error(std::string msg);

	DirectDeclaratorNode( DirectDeclaratorNode* a);

	DirectDeclaratorNode( IdentifierNode* id );

	DirectDeclaratorNode( DeclaratorNode* declaratorNode );

	void initData();

	void specifyArray();

	void specifyArray( ConstantExpressionNode* a);

	void specifyFunction( ParameterTypeListNode* a );

	void specifyFunctionCall( IdentifierListNode* a );

	int getKind();

	ASTData* toOperations();

	std::string getNodeTypeAsString();

	IdentifierNode* id;
	DeclaratorNode* declNode;
	DirectDeclaratorNode* dirDeclNode;
	IdentifierListNode* idListNode;
	ConstantExpressionNode* arraySize;
	ParameterTypeListNode* funcParams;

private:

	int kind;

	bool array;
	bool functionCall;
	bool functionDefinition; // declaration?
};

#endif /* DIRECTDECLARATORNODE2_H_ */
