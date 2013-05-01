/*
 * InitDeclaratorListNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef INITDECLARATORLISTNODE_H_
#define INITDECLARATORLISTNODE_H_

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

#include "ASTNodes.h"

class InitDeclaratorNode;

class InitDeclaratorListNode : public Node
{

public:

	InitDeclaratorListNode( InitDeclaratorListNode* _initDeclaratorList , InitDeclaratorNode* _initDeclarator);

	InitDeclaratorListNode( InitDeclaratorNode* _initDeclarator);

	ASTData* toOperations();

	std::string getNodeTypeAsString();

	InitDeclaratorListNode* initDeclaratorList = 0;
	InitDeclaratorNode* initDeclarator = 0;

};


#endif /* INITDECLARATORLISTNODE_H_ */
