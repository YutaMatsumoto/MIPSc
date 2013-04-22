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
		Array,
		ArrayWithSize,
		FunctionDefinition,
		FunctionDefinitionWithParam,
		FunctionCall, // TODO
		FunctionCallWithParam,
		None
	};

	DirectDeclaratorNode();

	DirectDeclaratorNode( DirectDeclaratorNode* a);

	DirectDeclaratorNode( IdentifierNode* id );

	// ASTData* toOperations();

	// std::string getNodeTypeAsString();

	string toString();

	void error(string msg);



	void initData();

	void specifyArray();

	void specifyArray( ConstantExpressionNode* a);

	void specifyFunction( ParameterTypeListNode* a );

	void specifyFunctionCall( IdentifierListNode* a );

	int getKind();

	Symbol* declare(Type*);

	// Type* declare_recurse(Type* t);

	// If this is true, then this instance is the bottom of the
	// direct_declarator symbol
	bool hasIdentifier();
	
	IdentifierNode* id;
	DeclaratorNode* declNode;		
	DirectDeclaratorNode* dirDeclNode;
	IdentifierListNode* idListNode;
	ConstantExpressionNode* arraySize;
	ParameterTypeListNode* funcParams;

private:

	int kind;

};

#endif
