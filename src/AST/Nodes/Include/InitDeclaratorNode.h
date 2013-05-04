#ifndef InitDeclaratorNode_H_GUARD
#define InitDeclaratorNode_H_GUARD

#include "AllASTNodes.h"

#include "DeclaratorNode.h"
#include "InitializerNode.h"
#include "Node.h"

class InitializerNode;
class DeclaratorNode;

class InitDeclaratorNode : public Node {

public:

	InitDeclaratorNode();

	InitDeclaratorNode(DeclaratorNode* declarationNode , SymbolTable* _table);

	InitDeclaratorNode(DeclaratorNode* declarationNode, InitializerNode* initializerNode, SymbolTable* _table);

	std::string toString();

	std::string getNodeTypeAsString();
	ASTData* toOperations();

	DeclaratorNode* declarationNode;
	InitializerNode* initializerNode;

	SymbolTable* table;
};

#endif // END InitDeclaratorNode_H_GUARD
