

#ifndef DECLARATIONNODE_H_
#define DECLARATIONNODE_H_

#include "AllASTNodes.h"

#include "SymbolTable.h"
#include "Type.h"
#include "Node.h"

#include "InitDeclaratorListNode.h"
#include "Type.h"
#include "DeclarationSpecifiersNode.h"
#include "InitDeclaratorListNode.h"
#include "TypeInfo.h"

class DeclarationSpecifiersNode;
class TypeInfo;
class InitDeclaratorListNode;
class DirectDeclaratorNode;

class DeclarationNode : public Node
{
public:

	DeclarationNode();

	DeclarationNode(DeclarationSpecifiersNode* declSpecifier);

	DeclarationNode(DeclarationSpecifiersNode* declSpecifier, InitDeclaratorListNode* initDeclList);

	virtual ASTData* toOperations();

	virtual std::string getNodeTypeAsString();

	void error(std::string msg);

	void declare(SymbolTable* stab) ;

	std::string toString() const;

	Type* buildType(TypeInfo tInfo) const;


private:

	Symbol* buildArray(TypeInfo tInfo, DirectDeclaratorNode* dd);

	//Type* buildType(DeclarationSpecifiersNode::TypeInfo) const;

	InitDeclaratorListNode* initDeclList = 0;
	DeclarationSpecifiersNode* declSpecifier = 0;
};

#endif /* DECLARATIONNODE_H_ */

