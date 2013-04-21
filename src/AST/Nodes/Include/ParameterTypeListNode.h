#ifndef ParameterTypeListNode_H_GUARD
#define ParameterTypeListNode_H_GUARD

#include "AllASTNodes.h"

// #include "ParameterTypeListNode.h"
#include "ParameterListNode.h"

typedef vector<Type*> TypeList;

class ParameterTypeListNode {
public:

	ParameterTypeListNode(ParameterListNode* pl)
		: pl(pl), ellipsis(false)
	{}

	TypeList typeList();

	void setVariableArgumentList();

	ParameterListNode* pl;
	bool ellipsis;
};

#endif // END ParameterTypeListNode_H_GUARD

