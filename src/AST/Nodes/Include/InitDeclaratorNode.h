#ifndef InitDeclaratorNode_H_GUARD
#define InitDeclaratorNode_H_GUARD

#include "AllASTNodes.h"

#include "DeclaratorNode.h"
#include "InitializerNode.h"


class InitDeclaratorNode {
public:

	InitDeclaratorNode() {}

	InitDeclaratorNode(DeclaratorNode* declNode) 
		: declNode(declNode)
	{}

	InitDeclaratorNode(DeclaratorNode* declNode, InitializerNode* initNode) 
		: declNode(declNode), initNode(initNode)
	{}

	string toString();

	DeclaratorNode* declNode;
	InitializerNode* initNode;
};

#endif // END InitDeclaratorNode_H_GUARD

