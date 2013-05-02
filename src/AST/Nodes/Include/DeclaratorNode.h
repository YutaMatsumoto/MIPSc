#ifndef DeclaratorNode_H_GUARD
#define DeclaratorNode_H_GUARD

#include "AllASTNodes.h"

#include "DirectDeclaratorNode.h"
#include "PointerNode.h"
#include "Node.h"

class DirectDeclaratorNode;

class DeclaratorNode {
public:

	DeclaratorNode(DirectDeclaratorNode* dirDeclNode) 
		: dirDeclNode(dirDeclNode), ptrNode(NULL)
	{}

	DeclaratorNode(PointerNode* ptrNode, DirectDeclaratorNode* dirDeclNode) 
		: dirDeclNode(dirDeclNode), ptrNode(ptrNode)
	{}

	ASTData* toOperations();

	std::string getNodeTypeAsString();

	bool isPointer();

	string toString() const;


	DirectDeclaratorNode* dirDeclNode;
	PointerNode* ptrNode;
};

#endif // END DeclaratorNode_H_GUARD
