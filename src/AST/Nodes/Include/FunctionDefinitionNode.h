/*
 * FunctionDefinitionNode.h
 *
 *  Created on: Apr 16, 2013
 *      Author: njordan
 */

#ifndef FUNCTIONDEFINITIONNODE_H_
#define FUNCTIONDEFINITIONNODE_H_

#include "Node.h"

#include "CompoundStatementNode.h"
#include "DeclaratorNode.h"

class CompoundStatementNode;
class Declarator;

class FunctionDefinitionNode: public Node {

public:

	FunctionDefinitionNode( CompoundStatementNode* _compoundStatement , DeclaratorNode* declarator );

	CompoundStatementNode* compoundStatement = 0;

	DeclaratorNode* declarator = 0;

	ASTData* toOperations();

	std::string getNodeTypeAsString();

};

#endif /* FUNCTIONDEFINITIONNODE_H_ */
