#ifndef ParameterDeclarationNode_H_GUARD
#define ParameterDeclarationNode_H_GUARD

#include "AllASTNodes.h"

#include "DeclaratorNode.h"
#include "AbstractDeclaratorNode.h"
#include "DeclarationSpecifiersNode.h"

class DeclaratorNode;
class DeclarationSpecifiersNode;
class TypeInfo;


class ParameterDeclarationNode {
public:
	ParameterDeclarationNode( DeclarationSpecifiersNode* ds,  DeclaratorNode* d)
		: ds(ds), d(d), ad(NULL)
	{}

	ParameterDeclarationNode( DeclarationSpecifiersNode* ds )
		: ds(ds), d(NULL), ad(NULL)
	{}

	ParameterDeclarationNode( DeclarationSpecifiersNode* ds, AbstractDeclaratorNode* ad)
		: ds(ds), d(NULL), ad(ad)
	{}

	// -----------------------------------------------------------------------

	// DeclarationSpecifiersNode::TypeInfo getType();
	TypeInfo getType();

	// -----------------------------------------------------------------------

	DeclarationSpecifiersNode* ds;  
	DeclaratorNode* d;
	AbstractDeclaratorNode* ad;
};

#endif // END ParameterDeclarationNode_H_GUARD

