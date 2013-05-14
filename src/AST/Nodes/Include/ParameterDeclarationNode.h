#ifndef ParameterDeclarationNode_H_GUARD
#define ParameterDeclarationNode_H_GUARD

#include "AllASTNodes.h"

#include "DeclaratorNode.h"
#include "AbstractDeclaratorNode.h"
#include "DeclarationSpecifiersNode.h"

class DeclaratorNode;
class DeclarationSpecifiersNode;
class TypeInfo;


class ParameterDeclarationNode : public Node {
public:
	ParameterDeclarationNode( DeclarationSpecifiersNode* ds,  DeclaratorNode* d,
			SymbolTable* stab);
	ParameterDeclarationNode( DeclarationSpecifiersNode* ds ,
			SymbolTable* stab);
	ParameterDeclarationNode( DeclarationSpecifiersNode* ds, AbstractDeclaratorNode* ad,
			SymbolTable* stab);

	// -----------------------------------------------------------------------

	// DeclarationSpecifiersNode::TypeInfo getType();
	TypeInfo getType();

	// -----------------------------------------------------------------------

	ASTData* toOperations();

	std::string getNodeTypeAsString();

	void declare(SymbolTable* stab);

	DeclarationSpecifiersNode* ds = 0;
	DeclaratorNode* d = 0;
	AbstractDeclaratorNode* ad = 0;
};

#endif // END ParameterDeclarationNode_H_GUARD

