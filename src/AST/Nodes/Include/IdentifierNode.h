/*
 * IdentifierNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef IDENTIFIERNODE_H_
#define IDENTIFIERNODE_H_

#include "Node.h"
#include "Operation.h"
#include "SymbolTable.h"
#include <vector>
#include <string>

class IdentifierNode : public Node
{

public:

	IdentifierNode( SymbolTable* _table , std::string _id );

	std::string getId();

	Symbol* resolveSymbol();

	ASTData* toOperations();

	std::string getNodeTypeAsString();

protected:

	std::string id;

	SymbolTable* table;

};


#endif /* IDENTIFIERNODE_H_ */
