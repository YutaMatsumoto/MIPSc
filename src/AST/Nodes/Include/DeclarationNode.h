/*
 * DeclarationNode.h
 *
 *  Created on: May 1, 2013
 *      Author: njordan
 */

#ifndef DECLARATIONNODE_H_
#define DECLARATIONNODE_H_

#include "ASTNodes.h"
#include "InitDeclaratorListNode.h"
#include "Type.h"

class DeclarationSpecifiersNode;
class InitDeclaratorListNode;
struct TypeInfo;

class DeclarationNode : public Node {
public:


	DeclarationNode();

	DeclarationNode(DeclarationSpecifiersNode* declSpecifier);

	DeclarationNode(DeclarationSpecifiersNode* declSpecifier, InitDeclaratorListNode* initDeclList);

	// TODO
	virtual ASTData* toOperations();

	virtual std::string getNodeTypeAsString();

	void error(std::string msg);

	void declare(SymbolTable* stab) ;

	//Type* buildType(DeclarationSpecifiersNode::TypeInfo) const;

	std::string toString() const;

private:
	InitDeclaratorListNode* initDeclList = 0;
	DeclarationSpecifiersNode* declSpecifier = 0;
};

#endif /* DECLARATIONNODE_H_ */
