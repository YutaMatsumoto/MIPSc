/*
 * LabeledStatementNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef LABELEDSTATEMENTNODE_H_
#define LABELEDSTATEMENTNODE_H_

#include "IdentifierNode.h"
#include "StatementNode.h"
#include "ConstantExpressionNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class StatementNode;
class ConstantExpressionNode;

class LabeledStatementNode : public Node
{

public:

	enum LabeledStatementType
	{
		Label,
		Case,
		Default
	};

	LabeledStatementNode( IdentifierNode* _identifier, StatementNode* _statement );
	LabeledStatementNode( ConstantExpressionNode* _constantExpression, StatementNode* _statement );
	LabeledStatementNode( StatementNode* _statement );
	std::vector< Operation* >* toOperations();
	std::string getNodeTypeAsString();

	IdentifierNode* identifier;
	ConstantExpressionNode* constantExpression;
	StatementNode* statement;

	LabeledStatementType type;


};


#endif /* LABELEDSTATEMENTNODE_H_ */
