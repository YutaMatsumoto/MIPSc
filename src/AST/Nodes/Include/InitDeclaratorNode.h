/*
 * InitDeclaratorNode.h
 *
 *  Created on: Apr 21, 2013
 *      Author: njordan
 */

#ifndef INITDECLARATORNODE_H_
#define INITDECLARATORNODE_H_

#include "Node.h"

#include "ASTNodes.h"

class DeclaratorNode;
class InitializerNode;

class InitDeclaratorNode : public Node {
public:

	InitDeclaratorNode(DeclaratorNode* _declarationNode);

	InitDeclaratorNode(DeclaratorNode* _declarationNode, InitializerNode* _initializerNode);

	std::string getNodeTypeAsString();
	ASTData* toOperations();

	DeclaratorNode* declarationNode = 0;
	InitializerNode* initializerNode = 0;
};

#endif /* INITDECLARATORNODE_H_ */
