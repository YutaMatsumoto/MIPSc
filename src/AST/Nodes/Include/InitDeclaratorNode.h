#ifndef InitDeclaratorNode_H_GUARD
#define InitDeclaratorNode_H_GUARD

#include "AllASTNodes.h"

#include "DeclaratorNode.h"
#include "InitializerNode.h"
#include "Node.h"

#include "ASTNodes.h"

class InitializerNode;


class InitDeclaratorNode {
public:

	InitDeclaratorNode() {}

	InitDeclaratorNode(DeclaratorNode* declarationNode) 
		: declarationNode(declarationNode)
	{}

	InitDeclaratorNode(DeclaratorNode* declarationNode, InitializerNode* initializerNode) 
		: declarationNode(declarationNode), initializerNode(initializerNode)
	{}

	string toString();

	std::string getNodeTypeAsString();
	ASTData* toOperations();

	DeclaratorNode* declarationNode;
	InitializerNode* initializerNode;
};

#endif // END InitDeclaratorNode_H_GUARD
