/*
 * JumpStatementNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef JUMPSTATEMENTNODE_H_
#define JUMPSTATEMENTNODE_H_

#include "ExpressionNode.h"
#include "IdentifierNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class JumpStatementNode : public Node
{

public:

	enum JumpStatementType
	{
		Goto,
		Continue,
		Break,
		Return
	};

	JumpStatementNode( ExpressionNode* _expression, SymbolTable* _stab );
	JumpStatementNode( IdentifierNode* _identifier, SymbolTable* _stab );
	JumpStatementNode( JumpStatementType _type );
	ASTData* toOperations();
	std::string getNodeTypeAsString();

	IdentifierNode* identifier = 0;
	ExpressionNode* expression = 0;
	JumpStatementType type;
	SymbolTable* stab = 0;

};


#endif /* JUMPSTATEMENTNODE_H_ */
