#ifndef DeclaratorNode_H_GUARD
#define DeclaratorNode_H_GUARD

#include "DirectDeclaratorNode.h"
#include "PointerNode.h"
#include "Node.h"

#include "AllASTNodes.h"

class DirectDeclaratorNode;

class DeclaratorNode : public Node {
public:

	DeclaratorNode(DirectDeclaratorNode* dirDeclNode);

	DeclaratorNode(PointerNode* ptrNode, DirectDeclaratorNode* dirDeclNode);

	ASTData* toOperations();

	std::string getNodeTypeAsString();

	bool isPointer();

	std::string toString() const;

	DirectDeclaratorNode* dirDeclNode;
	PointerNode* ptrNode;
};

#endif // END DeclaratorNode_H_GUARD
