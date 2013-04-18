/*
 * StatementNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef STATEMENTNODE_H_
#define STATEMENTNODE_H_

#include "LabeledStatementNode.h"
#include "ExpressionStatementNode.h"
#include "CompoundStatementNode.h"
#include "SelectionStatementNode.h"
#include "IterationStatementNode.h"
#include "JumpStatementNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class CompoundStatementNode;
class IterationStatementNode;
class LabeledStatementNode;
class SelectionStatementNode;

class StatementNode : public Node
{

public:

	StatementNode( LabeledStatementNode* _labeledStatement );

	StatementNode( ExpressionStatementNode* _expressionStatement );

	StatementNode( CompoundStatementNode* _compoundStatement );

	StatementNode( SelectionStatementNode* _selectionStatement );

	StatementNode( IterationStatementNode* _iterationStatement );

	StatementNode( JumpStatementNode* _jumpStatement );

	ASTData* toOperations();

	std::string getNodeTypeAsString();

	LabeledStatementNode* labeledStatement = 0;
	CompoundStatementNode* compoundStatement = 0;
	ExpressionStatementNode* expressionStatement = 0;
	SelectionStatementNode* selectionStatement = 0;
	IterationStatementNode* iterationStatement = 0;
	JumpStatementNode* jumpStatement = 0;


	inline ~StatementNode() {};

};


#endif /* STATEMENTNODE_H_ */
