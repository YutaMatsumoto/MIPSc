
#ifndef DIRECTDECLARATORNODE_H_GURAD
#define DIRECTDECLARATORNODE_H_GURAD

#include "common.h"
#include "Symbol.h"
#include "Node.h"

#include "AllASTNodes.h"

#include "ParameterTypeListNode.h"
#include "DeclaratorNode.h"
#include "IdentifierListNode.h"

#include "Node.h"
#include "DeclaratorNode.h"
#include <string>

class IdentifierListNode;
class ParameterTypeListNode;
class IdentifierNode;
class DeclaratorNode;
class ConstantExpressionNode;

class DirectDeclaratorNode : public Node {
public:

	enum DirectDeclaratorKind {
		Array,
		ArrayWithSize,
		FunctionDefinition,
		FunctionDefinitionWithParam,
		FunctionCall, // TODO
		FunctionCallWithParam,
		None,
		Id
	};

	DirectDeclaratorNode();

	std::string toString();

	void error(std::string msg);

	DirectDeclaratorNode( DirectDeclaratorNode* a, DirectDeclaratorKind _kind);

	DirectDeclaratorNode( DirectDeclaratorNode* a, ParameterTypeListNode* _p );

	DirectDeclaratorNode( IdentifierNode* id );

	DirectDeclaratorNode( DeclaratorNode* declaratorNode );

	DirectDeclaratorNode( DirectDeclaratorNode* _directDeclarator , ConstantExpressionNode* _constantExpression );

	void initData();

	void specifyArray( ConstantExpressionNode* a);

	void specifyArray();

	void specifyFunction( ParameterTypeListNode* a );

	void specifyFunctionCall( IdentifierListNode* a );

	int getKind();

	Symbol* declare(Type* , SymbolTable* );

	// Type* declare_recurse(Type* t);

	// If this is true, then this instance is the bottom of the
	// direct_declarator symbol
	bool hasIdentifier();
	
	IdentifierNode* id = 0;
	DeclaratorNode* declNode = 0;

	ASTData* toOperations();

	std::string getNodeTypeAsString();

	DirectDeclaratorNode* dirDeclNode = 0;
	IdentifierListNode* idListNode = 0;
	ConstantExpressionNode* arraySize = 0;
	ParameterTypeListNode* funcParams = 0;

private:

	DirectDeclaratorKind kind;


};

#endif
