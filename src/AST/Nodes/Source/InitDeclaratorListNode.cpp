#include "InitDeclaratorListNode.h"

InitDeclaratorListNode::InitDeclaratorListNode( InitDeclaratorNode* n)
{
	declaratorList.push_back(n);
}

InitDeclaratorListNode::InitDeclaratorListNode( InitDeclaratorListNode* a,  InitDeclaratorNode* b)
{
	for (auto initDecl : a->declaratorList) {
		declaratorList.push_back(initDecl);
	}
	declaratorList.push_back(b);
}

void InitDeclaratorListNode::add(InitDeclaratorNode* initDecl) 
{
	declaratorList.push_back(initDecl);	
}
