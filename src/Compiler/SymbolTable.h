/*
 * SymbolTable.h
 *
 *  Created on: Mar 25, 2013
 *      Author: njordan
 */

#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include <list>
#include "Scope.h"
#include "SymbolTableInfo.h"

class SymbolTable {

public:

	SymbolTable();
	virtual ~SymbolTable();

	// insert new symbol object
	void insertSymbol( Symbol* symbol );

	//insert new type object
	void insertType( Type* type );

	//push elements onto the symbol and type stack
	void beginScope();

	//pop elements off the symbol and type stack
	void endScope();

	//executed in case of a conflict
	void conflictError( Symbol* newSymbol , Symbol* previousSymbol );

	//Has this symbol been defined yet
	SymbolTableInfo getSymbolInfo( std::string symbolName , bool currentScopeOnly );

	//Has this type been defined yet
	//bool getTypeInfo( std::string typeName );

	//dumps the symbol table to a file
	void dumpTable( std::string filename );

	//returns true if the program is in global scope
	bool isGlobalScope();

	Scope functionScope;

protected:

	std::list< Scope > scopeStack;

};

#endif /* SYMBOLTABLE_H_ */
