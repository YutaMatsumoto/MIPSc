#ifndef PointerNode_H_GUARD
#define PointerNode_H_GUARD

#include "AllASTNodes.h"

#include "TypeQualifierListNode.h"

class TypeQualifierListNode;

class PointerNode {
public:

	PointerNode()
		: p(NULL), tql(NULL)
	{}
		
	PointerNode( TypeQualifierListNode* tql )
		: p(NULL), tql(tql)
	{}

	PointerNode( PointerNode* p )
		: p(p), tql(NULL)
	{}

	PointerNode( TypeQualifierListNode* tql,  PointerNode* p)
		: p(p), tql(tql)
	{}

	PointerNode* p;
	TypeQualifierListNode* tql;
};


#endif // END PointerNode_H_GUARD

