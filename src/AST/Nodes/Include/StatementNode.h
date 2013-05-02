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
class ExpressionStatementNode;
class JumpStatementNode;

class StatementNode : public Node
{

public:

	StatementNode( LabeledStatementNode* _labeledStatement , std::string _lineInfo);

	StatementNode( ExpressionStatementNode* _expressionStatement , std::string _lineInfo);

	StatementNode( CompoundStatementNode* _compoundStatement , std::string _lineInfo);

	StatementNode( SelectionStatementNode* _selectionStatement , std::string _lineInfo);

	StatementNode( IterationStatementNode* _iterationStatement , std::string _lineInfo );

	StatementNode( JumpStatementNode* _jumpStatement , std::string _lineInfo);

	ASTData* toOperations();

	std::string getNodeTypeAsString();

	LabeledStatementNode* labeledStatement = 0;
	CompoundStatementNode* compoundStatement = 0;
	ExpressionStatementNode* expressionStatement = 0;
	SelectionStatementNode* selectionStatement = 0;
	IterationStatementNode* iterationStatement = 0;
	JumpStatementNode* jumpStatement = 0;

	std::string lineInfo;

	inline ~StatementNode() {};

};


#endif /* STATEMENTNODE_H_ */
