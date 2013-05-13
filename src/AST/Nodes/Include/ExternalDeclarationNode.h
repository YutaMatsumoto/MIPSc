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
#include "FunctionDefinitionNode.h"

class DeclarationNode;
class FunctionDefinitionNode;

class ExternalDeclarationNode : public Node {

public:

	ExternalDeclarationNode(FunctionDefinitionNode*);
	ASTData* toOperations();
	std::string getNodeTypeAsString();

	DeclarationNode* declaration = 0;
	FunctionDefinitionNode* functionDefinition = 0;

};


#endif /* EXTERNALDECLARATIONNODE_H_ */
