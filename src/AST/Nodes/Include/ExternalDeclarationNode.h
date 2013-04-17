/*
 * ExternalDeclarationNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef EXTERNALDECLARATIONNODE_H_
#define EXTERNALDECLARATIONNODE_H_

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>
#include "ASTNodes.h"

class DeclarationNode;

class ExternalDeclarationNode : public Node {

public:

	ExternalDeclarationNode();
	ASTData* toOperations();
	std::string getNodeTypeAsString();

	DeclarationNode* declaration;
	//FunctionDefinitionNode* functionDefinition;

};


#endif /* EXTERNALDECLARATIONNODE_H_ */
