#include <vector>
#include <string>
#include "Symbol.h"
#include "Expression.h"
#include "Common.h"

#ifndef NODES_H_GUARD
#define NODES_H_GUARD




// Things that must be able expand to code, but do not have to be a node of the
// tree such as init expression of a For node
class Statement {
	virtual Code toIntermediateCode() = 0;
	virtual Code toMips() = 0;
};


// ---------------------------------------------------------------------------
// Node of Abstract Syntax Tree

class Node { // : public Statement {

public:

	Node() : parent(NULL) {}

	Node(Node* parentNode) 
		: parent(parentNode) 
	{}

	virtual std::string toString() { return "Base Node"; } ;

	// virtual ~Node();

	bool isLeaf() 
	{
		return ( children.size() == 0 );
	}	

private:
	Node* parent;
	std::vector<Node> children;

};

// ---------------------------------------------------------------------------
// Node Subtypes


//class Assignment : public Statement { 
//public:
//	Assignment(Symbol lvalue, Expression expression, Node* parent) 
//		: Node(parent), lvalue(lvalue), expression(expression)
//	{}
//
//	void addLvalue(Symbol lvalue);
//
//private:
//
//	// Assignment needs at leat one lvalue and expression to assign to the lvalue
//	Symbol lvalue;
//	Expression expression;
//
//	// Exra lvalues
//	std::vector<Symbol> lvalues;
//
//};

// --------------------------------------------------------------------------
// Loop

/*
class While : public Node {
public:
	// While(Statement* body, Expression condition, Node* parent)
	While(Node* body, Expression condition, Node* parent)
		: Node(parent), body(body), condition(condition)
	{}

	Code toMips();

	Code toIntermediateCode();


protected:
	Node* body;
	Expression condition;
};
*/

/*
class For : public While {
public:
	// For(Statement* init, Expression cond,  Node* update, Statement* body, Node* parent) 
	For(Node* init, Expression cond,  Node* update, Node* body, Node* parent) 
		: While(body, cond, parent), init(init), update(update)
	{}

	Code toMips();

	Code toIntermediateCode();

private:
	Statement* init;
	Statement* update;
};


class DoWhile : public While {
public:
	// DoWhile(Statement* body, Expression condition, Node* parent)
	DoWhile(Node* body, Expression condition, Node* parent)
		: While(body, condition, parent)
	{}
};
*/

// --------------------------------------------------------------------------
// Selection


/*
class If : public Node {
public:
	// if without else
	If(Expression, Statement*);

	// if with else
	If(Expression, Statement*, Statement&);

	// no 'else if (expression)' construct in parser.y
	// void addElseIf(Expression, statement)	
	// void addElse(statement);

private:
	Node* stmt;
	Node* stmt2;
	Expression* cond;

};
*/

#endif
