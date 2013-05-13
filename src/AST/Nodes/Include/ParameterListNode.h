#ifndef ParameterListNode_H_GUARD
#define ParameterListNode_H_GUARD

#include "AllASTNodes.h"

#include "ParameterDeclarationNode.h"

#include "Type.h"

class ParameterDeclarationNode;

class ParameterListNode {
public:

	ParameterListNode( ParameterDeclarationNode* pd);

	void add(ParameterDeclarationNode* pd);

	typedef vector<Type*> TypeList;
	TypeList getTypeList();


	vector<ParameterDeclarationNode*> plist;
};

#endif // END ParameterListNode_H_GUARD

