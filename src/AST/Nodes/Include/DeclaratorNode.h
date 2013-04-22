/*
 * DeclaratorNode.h
 *
 *  Created on: Apr 21, 2013
 *      Author: njordan
 */

#ifndef DECLARATORNODE_H_
#define DECLARATORNODE_H_

#include "Node.h"

#include "ASTNodes.h"

class DirectDeclaratorNode;
class PointerNode;

class DeclaratorNode : public Node {
public:

	DeclaratorNode(DirectDeclaratorNode* dirDeclNode);

	DeclaratorNode(PointerNode* ptrNode, DirectDeclaratorNode* dirDeclNode);

	bool isPointer();

	ASTData* toOperations();

	std::string getNodeTypeAsString();

	DirectDeclaratorNode* dirDeclNode;
	PointerNode* ptrNode;
};

#endif /* DECLARATORNODE_H_ */
