#ifndef InitializerListNode_H_GUARD
#define InitializerListNode_H_GUARD

#include "AllASTNodes.h"

class InitializerNode;

class InitializerListNode {
public:

	InitializerListNode(InitializerNode* initNode);

	InitializerListNode(InitializerNode* initNode, InitializerListNode* initListNode);

	size_t size();

	std::vector<InitializerNode*> initializerList;
};


#endif // END InitializerListNode_H_GUARD

