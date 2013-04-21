#ifndef IdentifierListNode_H_GUARD
#define IdentifierListNode_H_GUARD

#include "AllASTNodes.h"

class IdentifierListNode {
public:

	IdentifierListNode( IdentifierNode* i )
	{
		idList.push_back(i);
	}

	void add(IdentifierNode* i)
	{
		idList.push_back(i);
	}

	// IdentifierListNode( IdentifierListNode* il,  IdentifierNode* i)
	// 	: i(i), il(il)
	// {
	// }

	vector<IdentifierNode*> idList;

	// IdentifierNode* i;
	// IdentifierListNode* il;
};

#endif // END IdentifierListNode_H_GUARD

