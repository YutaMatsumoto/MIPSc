/*
 * StatementListNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef STATEMENTLISTNODE_H_
#define STATEMENTLISTNODE_H_

#include "StatementNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class StatementNode;


class StatementListNode : public Node
{

public:

	StatementListNode( StatementNode* _statement );
	StatementListNode( StatementListNode* _statementList, StatementNode* _statement );
	ASTData* toOperations();
	std::string getNodeTypeAsString();

	StatementNode* statement;

	StatementListNode* statementList;

};


#endif /* STATEMENTLISTNODE_H_ */
