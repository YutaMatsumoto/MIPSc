/*
 * InitializerNode.h
 *
 *  Created on: Apr 21, 2013
 *      Author: njordan
 */

#ifndef INITIALIZERNODE_H_
#define INITIALIZERNODE_H_

#include "Node.h"

#include "AssignmentExpressionNode.h"

class AssignmentExpressionNode;
class InitializerListNode;

class InitializerNode: public Node {

public:

	InitializerNode(AssignmentExpressionNode* _assignmentExpression);

	InitializerNode(InitializerListNode* _initializerList);

	ASTData* toOperations();
	std::string getNodeTypeAsString();

	AssignmentExpressionNode* assignmentExpression;
	InitializerListNode* initializerList;

};

#endif /* INITIALIZERNODE_H_ */
