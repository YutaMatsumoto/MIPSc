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

class ExternalDeclarationNode : public Node {

public:

	ExternalDeclarationNode();
	ASTData* toOperations();
	std::string getNodeTypeAsString();

};


#endif /* EXTERNALDECLARATIONNODE_H_ */
