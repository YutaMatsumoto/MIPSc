// #include "ASTNodes.h"


#ifndef DECLARATIONNODE_H_GUARD
#define DECLARATIONNODE_H_GUARD

#include "AllASTNodes.h"

#include "SymbolTable.h"
#include "Type.h"
#include "Node.h"


#include "DeclarationSpecifiersNode.h"
#include "InitDeclaratorListNode.h"


class DeclarationSpecifiersNode;
class TypeInfo;
class InitDeclaratorListNode;
class DirectDeclaratorNode;

// class DeclarationSpecifiersNode::TypeInfo;
// class Type;

class DeclarationNode : public Node {
public:


	DeclarationNode() {}	

	// -----------------------------------------------------------------------
	
	DeclarationNode(DeclarationSpecifiersNode* declSpecifier)
		: declSpecifier(declSpecifier)
	{}

	DeclarationNode(DeclarationSpecifiersNode* declSpecifier, InitDeclaratorListNode* initDeclList)
		: declSpecifier(declSpecifier), initDeclList(initDeclList)
	{}

	// -----------------------------------------------------------------------
	
	// TODO
	virtual ASTData* toOperations();

	virtual std::string getNodeTypeAsString();

	void error(std::string msg);

	void declare(SymbolTable* stab) ;

	std::string toString() const;

	// bool isPointer();

private:
	// Type* buildType(DeclarationSpecifiersNode::TypeInfo tInfo) const;
	// Type* buildType(DeclarationSpecifiersNode::TypeInfo tInfo) const;

	// Symbol* buildArray(DeclarationSpecifiersNode::TypeInfo tInfo, DirectDeclaratorNode* dd);
	Symbol* buildArray(TypeInfo tInfo, DirectDeclaratorNode* dd);

private: 

	// PointerNode* ptrNode;
	InitDeclaratorListNode* initDeclList;		
	DeclarationSpecifiersNode* declSpecifier;
};



#endif
