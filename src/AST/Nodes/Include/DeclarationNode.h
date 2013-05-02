<<<<<<< HEAD
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
=======
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
>>>>>>> nate

class DeclarationNode : public Node {
public:


<<<<<<< HEAD
	DeclarationNode() {}	

	// -----------------------------------------------------------------------
	
	DeclarationNode(DeclarationSpecifiersNode* declSpecifier)
		: declSpecifier(declSpecifier)
	{}

	DeclarationNode(DeclarationSpecifiersNode* declSpecifier, InitDeclaratorListNode* initDeclList)
		: declSpecifier(declSpecifier), initDeclList(initDeclList)
	{}

	// -----------------------------------------------------------------------
	
=======
	DeclarationNode();

	DeclarationNode(DeclarationSpecifiersNode* declSpecifier);

	DeclarationNode(DeclarationSpecifiersNode* declSpecifier, InitDeclaratorListNode* initDeclList);

>>>>>>> nate
	// TODO
	virtual ASTData* toOperations();

	virtual std::string getNodeTypeAsString();

	void error(std::string msg);

	void declare(SymbolTable* stab) ;

<<<<<<< HEAD
	std::string toString() const;

	Type* buildType(TypeInfo tInfo);

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
=======
	//Type* buildType(DeclarationSpecifiersNode::TypeInfo) const;

	std::string toString() const;

private:
	InitDeclaratorListNode* initDeclList = 0;
	DeclarationSpecifiersNode* declSpecifier = 0;
};

#endif /* DECLARATIONNODE_H_ */
>>>>>>> nate
