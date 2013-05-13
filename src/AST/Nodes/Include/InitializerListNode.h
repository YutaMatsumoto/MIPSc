#ifndef InitializerListNode_H_GUARD
#define InitializerListNode_H_GUARD

#include "Node.h"
#include "AllASTNodes.h"

class InitializerNode;

class InitializerListNode : public Node {
public:

	InitializerListNode(InitializerNode* initNode);

	InitializerListNode(InitializerNode* initNode, InitializerListNode* initListNode);

	ASTData* toOperations();
	std::string getNodeTypeAsString();

	size_t size();

	std::vector<InitializerNode*> initializerList;
};


#endif // END InitializerListNode_H_GUARD
