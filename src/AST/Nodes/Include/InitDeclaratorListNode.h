#ifndef InitDeclaratorListNode_H_GUARD
#define InitDeclaratorListNode_H_GUARD

#include "AllASTNodes.h"

#include "InitDeclaratorNode.h"

class InitDeclaratorListNode {
public:

	InitDeclaratorListNode() {}

	InitDeclaratorListNode( InitDeclaratorNode* n);

	InitDeclaratorListNode( InitDeclaratorListNode* a,  InitDeclaratorNode* b);

	void add(InitDeclaratorNode* initDecl) ;


	std::vector<InitDeclaratorNode*> declaratorList;
};

#endif // END InitDeclaratorListNode_H_GUARD

