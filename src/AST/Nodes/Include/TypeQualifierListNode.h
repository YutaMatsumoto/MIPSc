#ifndef TypeQualifierListNode_H_GUARD
#define TypeQualifierListNode_H_GUARD

#include "AllASTNodes.h"

class TypeQualifierNode;

class TypeQualifierListNode {
public:

	TypeQualifierListNode(TypeQualifierNode* tq);

	TypeQualifierListNode(TypeQualifierListNode* tql, TypeQualifierNode* tq);

	std::vector<TypeQualifierNode*>	tqlist;

};


#endif // END TypeQualifierListNode_H_GUARD

