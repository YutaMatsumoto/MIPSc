/*
 * DeclarationListNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef DECLARATIONLISTNODE_H_
#define DECLARATIONLISTNODE_H_

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

#include "ASTNodes.h"

class DeclarationNode;

class DeclarationListNode : public Node
{

public:

	DeclarationListNode( DeclarationNode* _declaration );

	DeclarationListNode( DeclarationListNode* _declarationList , DeclarationNode* _declaration );

	ASTData* toOperations();

	std::string getNodeTypeAsString();

	DeclarationNode* declaration = 0;

	DeclarationListNode* declarationList = 0;

};


#endif /* DECLARATIONLISTNODE_H_ */
