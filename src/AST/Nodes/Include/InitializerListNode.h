/*
 * InitializerListNode.h
 *
 *  Created on: Apr 21, 2013
 *      Author: njordan
 */

#ifndef INITIALIZERLISTNODE_H_
#define INITIALIZERLISTNODE_H_

#include "Node.h"

class InitializerNode;

class InitializerListNode: public Node {

public:

	InitializerListNode(InitializerNode* _initializerNode);

	InitializerListNode(InitializerListNode* _initializerList , InitializerNode* _initializerNode);

	ASTData* toOperations();
	std::string getNodeTypeAsString();

	InitializerNode* initializerNode;
	InitializerListNode* initializerList;

};

#endif /* INITIALIZERLISTNODE_H_ */
