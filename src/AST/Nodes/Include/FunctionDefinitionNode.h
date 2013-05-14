/*
 * FunctionDefinitionNode.h
 *
 *  Created on: Apr 16, 2013
 *      Author: njordan
 */

#ifndef FUNCTIONDEFINITIONNODE_H_
#define FUNCTIONDEFINITIONNODE_H_

#include "Node.h"

#include "CompoundStatementNode.h"
#include "DeclaratorNode.h"
#include "FunctionType.h"

class CompoundStatementNode;
class Declarator;

class FunctionDefinitionNode: public Node {

public:

	FunctionDefinitionNode( CompoundStatementNode* _compoundStatement , DeclaratorNode* declarator,
			SymbolTable* _table );

	FunctionDefinitionNode( DeclarationSpecifiersNode* _declarationSpecifiers ,
			CompoundStatementNode* _compoundStatement ,
			DeclaratorNode* declarator,
			SymbolTable* _table
		);

	FunctionDefinitionNode(
			DeclarationSpecifiersNode* _declarationSpecifiers ,
			CompoundStatementNode* _compoundStatement,
			DeclaratorNode* _declarator,
			DeclarationListNode* _declarationList,
			SymbolTable* _table
	);

	CompoundStatementNode* compoundStatement = 0;

	DeclaratorNode* declarator = 0;

	DeclarationSpecifiersNode* declarationSpecifiers = 0;

	DeclarationListNode* declarationList = 0;

	Scope functionScope;

	ASTData* toOperations();

	std::string getNodeTypeAsString();

	void declareFunction(SymbolTable* _table);

	void calculateSymbolAddresses(SymbolTable* _table, FunctionType* func);

};

#endif /* FUNCTIONDEFINITIONNODE_H_ */
