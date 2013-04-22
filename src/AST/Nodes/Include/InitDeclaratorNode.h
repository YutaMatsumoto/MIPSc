#ifndef InitDeclaratorNode_H_GUARD
#define InitDeclaratorNode_H_GUARD

#include "AllASTNodes.h"

#include "DeclaratorNode.h"
#include "InitializerNode.h"
#include "Node.h"

#include "ASTNodes.h"


	InitDeclaratorNode() {}

	InitDeclaratorNode(DeclaratorNode* declNode) 
		: declNode(declNode)
	{}

	InitDeclaratorNode(DeclaratorNode* declNode, InitializerNode* initNode) 
		: declNode(declNode), initNode(initNode)
	{}

	string toString();

	std::string getNodeTypeAsString();
	ASTData* toOperations();

	DeclaratorNode* declNode;
	InitializerNode* initNode;
};

#endif // END InitDeclaratorNode_H_GUARD
