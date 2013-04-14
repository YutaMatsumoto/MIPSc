/*
 * ArgExpressionListNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef ARGEXPRESSIONLISTNODE_H_
#define ARGEXPRESSIONLISTNODE_H_

#include "AssignmentExpressionNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class AssignmentExpressionNode;

class ArgExpressionListNode : public Node
{

public:

	ArgExpressionListNode( AssignmentExpressionNode* _assignmentExpression );
	ArgExpressionListNode( ArgExpressionListNode* _argumentExpressionList, AssignmentExpressionNode* _assignmentExpression );

	AssignmentExpressionNode* assignmentExpression;

	ArgExpressionListNode* argumentExpressionList;


	std::vector< Operation* >* toOperations();

	std::string getNodeTypeAsString();

	~ArgExpressionListNode();

};


#endif /* ARGEXPRESSIONLISTNODE_H_ */
