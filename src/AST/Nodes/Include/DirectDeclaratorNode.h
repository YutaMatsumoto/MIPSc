<<<<<<< HEAD
#ifndef DIRECTDECLARATORNODE_H_GURAD
#define DIRECTDECLARATORNODE_H_GURAD

#include "common.h"
#include "Symbol.h"
#include "Node.h"

#include "AllASTNodes.h"

#include "ParameterTypeListNode.h"
#include "DeclaratorNode.h"
#include "IdentifierListNode.h"

// class DirectDeclaratorNode : public Node {
class DirectDeclaratorNode {
public:

	enum DirectDeclaratorKind {
		Id,
=======
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
>>>>>>> nate
		Array,
		ArrayWithSize,
		FunctionDefinition,
		FunctionDefinitionWithParam,
<<<<<<< HEAD
		FunctionCall, // TODO
		FunctionCallWithParam,
		None
	};

	DirectDeclaratorNode();
=======
		FunctionCall,
		FunctionCallWithParam
	};

	std::string toString();

	void error(std::string msg);
>>>>>>> nate

	DirectDeclaratorNode( DirectDeclaratorNode* a);

	DirectDeclaratorNode( IdentifierNode* id );

<<<<<<< HEAD
	ASTData* toOperations();

	std::string getNodeTypeAsString();

	string toString();

	void error(string msg);


=======
	DirectDeclaratorNode( DeclaratorNode* declaratorNode );
>>>>>>> nate

	void initData();

	void specifyArray();

	void specifyArray( ConstantExpressionNode* a);

	void specifyFunction( ParameterTypeListNode* a );

	void specifyFunctionCall( IdentifierListNode* a );

	int getKind();

<<<<<<< HEAD
	Symbol* declare(Type*);

	// Type* declare_recurse(Type* t);

	// If this is true, then this instance is the bottom of the
	// direct_declarator symbol
	bool hasIdentifier();
	
	IdentifierNode* id;
	DeclaratorNode* declNode;		
=======
	ASTData* toOperations();

	std::string getNodeTypeAsString();

	IdentifierNode* id;
	DeclaratorNode* declNode;
>>>>>>> nate
	DirectDeclaratorNode* dirDeclNode;
	IdentifierListNode* idListNode;
	ConstantExpressionNode* arraySize;
	ParameterTypeListNode* funcParams;

private:

	int kind;

<<<<<<< HEAD
};

#endif
=======
	bool array;
	bool functionCall;
	bool functionDefinition; // declaration?
};

#endif /* DIRECTDECLARATORNODE2_H_ */
>>>>>>> nate
