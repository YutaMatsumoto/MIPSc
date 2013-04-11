/*
 * ASTNodes.h
 *
 *  Created on: Apr 3, 2013
 *      Author: njordan
 */

#ifndef ASTNODES_H_
#define ASTNODES_H_

#include "ParserError.h"
#include "Node.h"
#include <cfloat>
#include "SymbolTable.h"

//Forward Declarations
class ExpressionNode;
class CastExpressionNode;
class TypeNameNode;
class ConditionalExpressionNode;
class AssignmentExpressionNode;
class StatementNode;
class DeclarationListNode;
class ExternalDeclarationNode;
//Definitions

class IdentifierNode : public Node
{

public:

	inline IdentifierNode( std::string _id ) : id( _id )
	{

	}

	inline std::string getId()
	{
		return id;
	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "identifier" );

	}

	//~IdentifierNode(){}

protected:

	std::string id;

};


class StringNode : public Node
{

public:

	inline StringNode( std::string _value ) : value( _value )
	{

	}

	inline std::string getValue()
	{
		return value;
	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "string" );

	}

	//~StringNode(){}

protected:

	std::string value;

};


class IntegerConstantNode : public Node
{

public:

	inline IntegerConstantNode( long long int _value ) : value( _value )
	{

	}

	inline long long int getValue()
	{
		return value;
	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "integer constant" );

	}

	//These handle the issue of overflow when casting
	// or performing operations
	bool canBeShort() { return ( value < 128 ) ? true : false; }
	bool canBeInt() { return ( value < 2147483648 ) ? true : false; }
	bool canBeLong() { return ( value < 2147483648 ) ? true : false; }
	//Long long is still going to be 32 bits on MIPS
	bool canBeLongLong() { return ( value < 2147483648 ) ? true : false; }

	bool canBeUnsignedShort() { return ( value < 256 ) ? true : false; }
	bool canBeUnsignedInt() { return ( value < 4294967296 ) ? true : false; }
	bool canBeUnsignedLong() { return ( value < 4294967296 ) ? true : false; }
	bool canBeUnsignedLongLong() { return ( value < 4294967296 ) ? true : false; }

	//~IntegerConstantNode(){}

protected:

	long long int value;

};


class FloatConstantNode : public Node
{

public:

	inline FloatConstantNode( double _value ) : value( _value )
	{

	}

	inline double getValue()
	{
		return value;
	}

	//These handle the issue of overflow when casting
	// or performing operations

	bool canBeFloat() { return ( value < FLT_MAX ) ? true : false; }

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "float constant" );

	}

	//~FloatConstantNode(){}

protected:

	double value;

};


class CharConstantNode : public Node
{

public:

	inline CharConstantNode( char _value ) : value( _value )
	{

	}

	inline char getValue()
	{
		return value;
	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "char constant" );

	}

	//~CharConstantNode(){}

protected:

	char value;

};

class ConstantNode : public Node
{

public:

	inline ConstantNode( IntegerConstantNode* _intConstant ) : intConstant( _intConstant )
	{

	}

	inline ConstantNode( FloatConstantNode* _floatConstant ) : floatConstant( _floatConstant )
	{

	}

	inline ConstantNode( CharConstantNode* _charConstant ) : charConstant( _charConstant )
	{

	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "constant" );

	}

protected:

	IntegerConstantNode* intConstant;
	FloatConstantNode* floatConstant;
	CharConstantNode* charConstant;

	// TODO Enumeration constant
	// EnumerationConstantNode* enumConstant;

	//~CharConstantNode(){}

};

class ArgExpressionListNode : public Node
{

public:

	inline ArgExpressionListNode( AssignmentExpressionNode* _assignmentExpression )
		: assignmentExpression( _assignmentExpression )
	{



	}

	inline ArgExpressionListNode( ArgExpressionListNode* _argumentExpressionList, AssignmentExpressionNode* _assignmentExpression )
		: assignmentExpression( _assignmentExpression ), argumentExpressionList( _argumentExpressionList )
	{

	}

	AssignmentExpressionNode* assignmentExpression;

	ArgExpressionListNode* argumentExpressionList;


	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "argument expression list" );

	}

	//~ArgExpressionListNode(){}

};


class PrimaryExpressionNode : public Node
{

public:

	inline PrimaryExpressionNode( IdentifierNode* _identifier ) : identifier( _identifier )
	{

	}

	inline PrimaryExpressionNode( ConstantNode* _constant ) : constant( _constant )
	{

	}

	inline PrimaryExpressionNode( StringNode* _string ) : string( _string )
	{

	}

	inline PrimaryExpressionNode( ExpressionNode* _expression ) : expression( _expression )
	{

	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "primary expression" );

	}

	IdentifierNode* identifier;
	ConstantNode* constant;
	StringNode* string;
	ExpressionNode* expression;

};

class PostfixExpressionNode : public Node
{

public:

	enum PostfixExpressionType
	{
		PrimaryExpression,
		ArrayAccess,
		FunctionCall,
		DirectMemberAccess,
		PointerMemberAccess,
		Increment,
		Decrement
	};

	//Primary Expression
	inline PostfixExpressionNode( PrimaryExpressionNode* _primaryExpression )
		: primaryExpression( _primaryExpression )
	{
		type = PrimaryExpression;
	}

	//Array Access
	inline PostfixExpressionNode( PostfixExpressionNode* _postfixExpression , ExpressionNode* arrayExpression )
		: postfixExpression( _postfixExpression )
	{
		type = ArrayAccess;
	}

	//Function Call, No arguments =OR= Increment =OR= Dcrement
	inline PostfixExpressionNode( PostfixExpressionNode* _postfixExpression , PostfixExpressionType _type )
		: postfixExpression( _postfixExpression ), type(_type)
	{

	}

	//Function Call, w/ arguments
	inline PostfixExpressionNode( PostfixExpressionNode* _postfixExpression , ArgExpressionListNode* _argExpressionList )
		: postfixExpression( _postfixExpression ), argExpressionList( _argExpressionList )
	{
		type = FunctionCall;
	}

	//Direct Member Access
	inline PostfixExpressionNode( PostfixExpressionNode* _postfixExpression , IdentifierNode* _memberIdentifier , PostfixExpressionType _type )
		: postfixExpression( _postfixExpression ), memberIdentifier( _memberIdentifier ), type( _type )
	{
		type = DirectMemberAccess;
	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "postfix expression" );

	}

	PostfixExpressionType type;

	PrimaryExpressionNode* primaryExpression;
	PostfixExpressionNode* postfixExpression;
	ArgExpressionListNode* argExpressionList;
	IdentifierNode* memberIdentifier;
	ExpressionNode* arrayExpression;


};

class UnaryOperatorNode : public Node
{

public:

	enum UnaryOperatorType
	{
		Address,
		Indirection,
		Positive,
		Negative,
		BitwiseNot,
		LogicalNot

	};

	inline UnaryOperatorNode( UnaryOperatorType _type ) : type( _type )
	{

	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "unary operator" );

	}

	UnaryOperatorType type;

};

class UnaryExpressionNode : public Node
{

public:

	enum UnaryExpressionType
	{
		Postfix,
		Increment,
		Decrement,
		Cast,
		SizeofExpression,
		SizeofType
	};

	inline UnaryExpressionNode( PostfixExpressionNode* _postfixExpression ) : postfixExpression( _postfixExpression )
	{
		type = Postfix;
	}

	inline UnaryExpressionNode( UnaryExpressionNode* _unaryExpression , UnaryExpressionType _type )
		: unaryExpression( _unaryExpression ), type(_type)
	{

	}

	inline UnaryExpressionNode( UnaryOperatorNode* _unaryOperator , CastExpressionNode* _castExpression )
				: unaryOperator( _unaryOperator ), castExpression(_castExpression)
	{
		type = Cast;
	}

	inline UnaryExpressionNode( TypeNameNode* _typeName )
					: typeName( _typeName )
	{
		type = SizeofType;
	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "unary expression" );

	}

	PostfixExpressionNode* postfixExpression;
	UnaryExpressionNode* unaryExpression;
	UnaryOperatorNode* unaryOperator;
	CastExpressionNode* castExpression;
	TypeNameNode* typeName;

	UnaryExpressionType type;

};

class CastExpressionNode : public Node
{

public:

	inline CastExpressionNode( UnaryExpressionNode* _unaryExpression ) : unaryExpression( _unaryExpression )
	{

	}

	inline CastExpressionNode( TypeNameNode* _typeName , CastExpressionNode* _castExpression )
		: typeName( _typeName ), castExpression(_castExpression)
	{

	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "cast expression" );

	}

	UnaryExpressionNode* unaryExpression;

	TypeNameNode* typeName;
	CastExpressionNode* castExpression;

};

class MultiplicativeExpressionNode : public Node
{

public:

	enum MultiplicativeExpressionType
	{
		Multiply,
		Divide,
		Modulo
	};

	inline MultiplicativeExpressionNode( CastExpressionNode* _castExpression ) : castExpression( _castExpression )
	{

	}

	inline MultiplicativeExpressionNode( MultiplicativeExpressionNode* _multiplicativeExpression ,
			CastExpressionNode* _castExpression ,
			MultiplicativeExpressionType _type
			)
		: multiplicativeExpression( _multiplicativeExpression ), castExpression(_castExpression), type( _type )
	{

	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "multiplicative expression" );

	}

	CastExpressionNode* castExpression;
	MultiplicativeExpressionNode* multiplicativeExpression;
	MultiplicativeExpressionType type;


};

class AdditiveExpressionNode : public Node
{

public:

	enum AdditiveExpressionType
	{
		Add,
		Subtract
	};

	inline AdditiveExpressionNode( MultiplicativeExpressionNode* _multiplicativeExpression ) : multiplicativeExpression( _multiplicativeExpression )
	{

	}

	inline AdditiveExpressionNode( AdditiveExpressionNode* _additiveExpression ,
			MultiplicativeExpressionNode* _multiplicativeExpression ,
			AdditiveExpressionType _type
			)
		: multiplicativeExpression( _multiplicativeExpression ), additiveExpression( _additiveExpression ), type( _type )
	{

	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "additive expression" );

	}

	AdditiveExpressionNode* additiveExpression;
	MultiplicativeExpressionNode* multiplicativeExpression;
	AdditiveExpressionType type;


};

class ShiftExpressionNode : public Node
{

public:

	enum ShiftExpressionType
	{
		Left,
		Right
	};

	inline ShiftExpressionNode( AdditiveExpressionNode* _additiveExpression ) : additiveExpression( _additiveExpression )
	{

	}

	inline ShiftExpressionNode( ShiftExpressionNode* _shiftExpression ,
			AdditiveExpressionNode* _additiveExpression ,
			ShiftExpressionType _type
			)
		: shiftExpression( _shiftExpression ), additiveExpression( _additiveExpression ), type( _type )
	{

	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "shift expression" );

	}

	AdditiveExpressionNode* additiveExpression;
	ShiftExpressionNode* shiftExpression;
	ShiftExpressionType type;

};

class RelationalExpressionNode : public Node
{

public:

	enum RelationalExpressionType
	{
		Less,
		Greater,
		LessEqual,
		GreaterEqual
	};

	inline RelationalExpressionNode( ShiftExpressionNode* _shiftExpression ) : shiftExpression( _shiftExpression )
	{

	}

	inline RelationalExpressionNode( RelationalExpressionNode* _relationalExpression ,
			ShiftExpressionNode* _shiftExpression ,
			RelationalExpressionType _type
			)
		: shiftExpression( _shiftExpression ), relationalExpression( _relationalExpression ), type( _type )
	{

	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "relational expression" );

	}

	RelationalExpressionNode* relationalExpression;
	ShiftExpressionNode* shiftExpression;
	RelationalExpressionType type;

};

class EqualityExpressionNode : public Node
{

public:

	enum EqualityExpressionType
	{
		Equal,
		NotEqual
	};

	inline EqualityExpressionNode( RelationalExpressionNode* _relationalExpression ) : relationalExpression( _relationalExpression )
	{

	}

	inline EqualityExpressionNode( EqualityExpressionNode* _equalityExpression ,
			RelationalExpressionNode* _relationalExpression ,
			EqualityExpressionType _type
			)
		: equalityExpression( _equalityExpression ), relationalExpression( _relationalExpression ), type( _type )
	{

	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "equality expression" );

	}

	EqualityExpressionNode* equalityExpression;
	RelationalExpressionNode* relationalExpression;
	EqualityExpressionType type;

};

class AndExpressionNode : public Node
{

public:

	inline AndExpressionNode( EqualityExpressionNode* _equalityExpression ) : equalityExpression( _equalityExpression )
	{

	}

	inline AndExpressionNode( AndExpressionNode* _andExpression ,
			EqualityExpressionNode* _equalityExpression
			)
		: equalityExpression( _equalityExpression ), andExpression( _andExpression )
	{

	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "AND expression" );

	}

	AndExpressionNode* andExpression;
	EqualityExpressionNode* equalityExpression;

};

class ExclusiveOrExpressionNode : public Node
{

public:

	inline ExclusiveOrExpressionNode( AndExpressionNode* _andExpression ) : andExpression( _andExpression )
	{

	}

	inline ExclusiveOrExpressionNode( ExclusiveOrExpressionNode* _exclusiveOrExpression ,
			AndExpressionNode* _andExpression
			)
		: exclusiveOrExpression( _exclusiveOrExpression ), andExpression( _andExpression )
	{

	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "exclusive OR expression" );

	}

	AndExpressionNode* andExpression;
	ExclusiveOrExpressionNode* exclusiveOrExpression;

};

class InclusiveOrExpressionNode : public Node
{

public:

	inline InclusiveOrExpressionNode( ExclusiveOrExpressionNode* _exclusiveOrExpression ) : exclusiveOrExpression( _exclusiveOrExpression )
	{

	}

	inline InclusiveOrExpressionNode( InclusiveOrExpressionNode* _inclusiveOrExpressionNode ,
			ExclusiveOrExpressionNode* _exclusiveOrExpression
			)
		: exclusiveOrExpression( _exclusiveOrExpression ), inclusiveOrExpressionNode( _inclusiveOrExpressionNode )
	{

	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "inclusive OR expression" );

	}

	InclusiveOrExpressionNode* inclusiveOrExpressionNode;
	ExclusiveOrExpressionNode* exclusiveOrExpression;

};

class LogicalAndExpressionNode : public Node
{

public:

	inline LogicalAndExpressionNode( InclusiveOrExpressionNode* _inclusiveOrExpressionNode ) : inclusiveOrExpressionNode( _inclusiveOrExpressionNode )
	{

	}

	inline LogicalAndExpressionNode( LogicalAndExpressionNode* _logicalAndExpression,
			InclusiveOrExpressionNode* _inclusiveOrExpressionNode
			)
		: logicalAndExpression( _logicalAndExpression ), inclusiveOrExpressionNode( _inclusiveOrExpressionNode )
	{

	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "logical AND expression" );

	}

	InclusiveOrExpressionNode* inclusiveOrExpressionNode;
	LogicalAndExpressionNode* logicalAndExpression;

};

class LogicalOrExpressionNode : public Node
{

public:


	inline LogicalOrExpressionNode( LogicalAndExpressionNode* _logicalAndExpression ) : logicalAndExpression( _logicalAndExpression )
	{

	}

	inline LogicalOrExpressionNode( LogicalOrExpressionNode* _logicalOrExpression ,
			LogicalAndExpressionNode* _logicalAndExpression )
		: logicalOrExpression( _logicalOrExpression ), logicalAndExpression( _logicalAndExpression )
	{

	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "logical OR expression" );

	}

	LogicalOrExpressionNode* logicalOrExpression;
	LogicalAndExpressionNode* logicalAndExpression;

};

class ConstantExpressionNode : public Node
{

public:

	inline ConstantExpressionNode( ConditionalExpressionNode* _conditionalExpression ) : conditionalExpression( _conditionalExpression )
	{

	}


	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "constant expression" );

	}

	ConditionalExpressionNode* conditionalExpression;

};

class ConditionalExpressionNode : public Node
{

public:

	inline ConditionalExpressionNode( LogicalOrExpressionNode* _logicalOrExpression ) : logicalOrExpression( _logicalOrExpression )
	{

	}

	inline ConditionalExpressionNode(
			LogicalOrExpressionNode* _logicalOrExpression,
			ExpressionNode* _expression,
			ConditionalExpressionNode* _conditionalExpression
		) : logicalOrExpression( _logicalOrExpression ), expression(_expression), conditionalExpression(_conditionalExpression)
	{

	}


	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "conditional expression" );

	}

	LogicalOrExpressionNode* logicalOrExpression;
	ExpressionNode* expression;
	ConditionalExpressionNode* conditionalExpression;

};

class AssignmentOperatorNode : public Node
{

public:

	enum AssignmentOperatorType
	{
		Assign,
		MulAssign,
		DivAssign,
		ModAssign,
		AddAssign,
		SubAssign,
		LeftAssign,
		RightAssign,
		AndAssign,
		XORAssign,
		OrAssign

	};

	inline AssignmentOperatorNode( AssignmentOperatorType _type ) : type( _type )
	{

	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "assignment operator" );

	}

	AssignmentOperatorType type;

};

class AssignmentExpressionNode : public Node
{

public:

	inline AssignmentExpressionNode( ConditionalExpressionNode* _conditionalExpression ) : conditionalExpression( _conditionalExpression )
	{

	}

	inline AssignmentExpressionNode(
			UnaryExpressionNode* _unaryExpression,
			AssignmentOperatorNode* _assignmentOperator,
			AssignmentExpressionNode* _assignmentExpression
		) : unaryExpression( _unaryExpression ), assignmentOperator(_assignmentOperator), assignmentExpression(_assignmentExpression)
	{

	}


	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "conditional expression" );

	}

	UnaryExpressionNode* unaryExpression;
	AssignmentOperatorNode* assignmentOperator;
	AssignmentExpressionNode* assignmentExpression;
	ConditionalExpressionNode* conditionalExpression;

};

class ExpressionNode : public Node
{

public:

	inline ExpressionNode( AssignmentExpressionNode* _assignmentExpression ) : assignmentExpression( _assignmentExpression )
	{

	}

	inline ExpressionNode(
			ExpressionNode* _expression,
			AssignmentExpressionNode* _assignmentExpression
		) : expression( _expression ), assignmentExpression(_assignmentExpression)
	{

	}


	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "expression" );

	}

	AssignmentExpressionNode* assignmentExpression;
	ExpressionNode* expression;

};

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

	inline JumpStatementNode( ExpressionNode* _expression ) : expression( _expression )
	{
		type = Return;
	}

	inline JumpStatementNode( IdentifierNode* _identifier ) : identifier( _identifier )
	{
		type = Goto;
	}

	inline JumpStatementNode( JumpStatementType _type ) : type( _type )
	{

	}


	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "jump statement" );

	}

	IdentifierNode* identifier;
	ExpressionNode* expression;
	JumpStatementType type;

};



class IterationStatementNode : public Node
{

public:

	enum IterationStatementType
	{
		While,
		DoWhile,
		For
	};

	inline IterationStatementNode( ExpressionNode* _condition , StatementNode* _statement, IterationStatementType _type )
		: condition( _condition ), statement( _statement ), type( _type )
	{

	}

	inline IterationStatementNode( ExpressionNode* _initialization ,ExpressionNode* _condition ,ExpressionNode* _increment ,StatementNode* _statement )
		: initialization( _initialization ), condition(_condition), increment(_increment), statement(_statement)
	{
		type = For;
	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "iteration statement" );

	}

	ExpressionNode* condition;

	ExpressionNode* initialization;

	ExpressionNode* increment;

	StatementNode* statement;

	IterationStatementType type;

};

class SelectionStatementNode : public Node
{

public:

	enum SelectionStatementType
	{
		If,
		IfElse,
		Switch
	};

	inline SelectionStatementNode( ExpressionNode* _condition , StatementNode* _statement, SelectionStatementType _type )
		: condition( _condition ), statement( _statement ), type( _type )
	{

	}

	inline SelectionStatementNode( ExpressionNode* _condition , StatementNode* _statement, StatementNode* _elseStatement )
			: condition( _condition ), statement( _statement )
	{
		type = IfElse;
	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "selection statement" );

	}

	ExpressionNode* condition;

	StatementNode* statement;

	StatementNode* elseStatement;

	SelectionStatementType type;

};

class StatementListNode : public Node
{

public:

	inline StatementListNode( StatementNode* _statement )
		: statement( _statement )
	{

	}

	inline StatementListNode( StatementListNode* _statementList, StatementNode* _statement )
			: statement( _statement ), statementList( _statementList )
	{

	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "statement list" );

	}

	StatementNode* statement;

	StatementListNode* statementList;

};

class CompoundStatementNode : public Node
{

public:

	inline CompoundStatementNode( DeclarationListNode* _declarationList )
		: declarationList( _declarationList )
	{

	}

	inline CompoundStatementNode( StatementListNode* _statementList )
			: statementList( _statementList )
		{

		}

	inline CompoundStatementNode( DeclarationListNode* _declarationList , StatementListNode* _statementList)
			: declarationList( _declarationList ), statementList( _statementList )
	{

	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "compound statement" );

	}

	DeclarationListNode* declarationList;

	StatementListNode* statementList;

};

class ExpressionStatementNode : public Node
{

public:

	inline ExpressionStatementNode( )
	{

	}

	inline ExpressionStatementNode( ExpressionNode* _expression )
			: expression( _expression )
		{

		}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "expression statement" );

	}

	ExpressionNode* expression;

};

class LabeledStatementNode : public Node
{

public:

	enum LabeledStatementType
	{
		Label,
		Case,
		Default
	};

	inline LabeledStatementNode( IdentifierNode* _identifier, StatementNode* _statement )
		: identifier( _identifier ), statement( _statement )
	{
		type = Label;
	}

	inline LabeledStatementNode( ConstantExpressionNode* _constantExpression, StatementNode* _statement )
			: constantExpression( _constantExpression ), statement( _statement )
	{
		type = Case;
	}

	inline LabeledStatementNode( StatementNode* _statement )
			: statement( _statement )
	{
		type = Default;
	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "labeled statement" );

	}

	IdentifierNode* identifier;
	ConstantExpressionNode* constantExpression;
	StatementNode* statement;

	LabeledStatementType type;


};

class StatementNode : public Node
{

public:

	inline StatementNode( LabeledStatementNode* _labeledStatement )
		: labeledStatement( _labeledStatement )
	{

	}

	inline StatementNode( ExpressionStatementNode* _expressionStatement )
		: expressionStatement( _expressionStatement )
	{

	}

	inline StatementNode( CompoundStatementNode* _compoundStatement )
		: compoundStatement( _compoundStatement )
	{

	}

	inline StatementNode( SelectionStatementNode* _selectionStatement )
		: selectionStatement( _selectionStatement )
	{

	}

	inline StatementNode( IterationStatementNode* _iterationStatement )
		: iterationStatement( _iterationStatement )
	{

	}

	inline StatementNode( JumpStatementNode* _jumpStatement )
		: jumpStatement( _jumpStatement )
	{

	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "statement" );

	}

	LabeledStatementNode* labeledStatement;
	CompoundStatementNode* compoundStatement;
	ExpressionStatementNode* expressionStatement;
	SelectionStatementNode* selectionStatement;
	IterationStatementNode* iterationStatement;
	JumpStatementNode* jumpStatement;


};

class TranslationUnitNode : public Node
{

public:

	inline TranslationUnitNode( ExternalDeclarationNode* _externalDeclaration )
		: externalDeclaration( _externalDeclaration )
	{

	}

	inline TranslationUnitNode( ExternalDeclarationNode* _externalDeclaration, TranslationUnitNode* _translationUnit )
			: externalDeclaration( _externalDeclaration ) ,  translationUnit( _translationUnit )
	{

	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "translation unit" );

	}

	TranslationUnitNode* translationUnit;

	ExternalDeclarationNode* externalDeclaration;


};

// ---------------------------------------------------------------------------
//
// DeclarationNode ... DirectAbstractDeclaratorNode
//

class DeclarationNode;
class DeclarationSpecifiersNode;
class StorageClassSpecifierNode;
class TypeSpecifierNode;
class TypeQualifierNode;
class StructOrUnionSpecifierNode;
class StructOrUnionNode;
class StructDeclarationListNode;
class InitDeclaratorListNode;
class InitDeclaratorNode;
class StructDeclarationNode;
class SpecifierQualifierListNode;
class StructDeclaratorListNode;
class StructDeclaratorNode;
class EnumSpecifierNode;
class EnumeratorListNode;
class EnumeratorNode;
class DeclaratorNode;
class DirectDeclaratorNode;
class PointerNode;
class TypeQualifierListNode;
class ParameterTypeListNode;
class ParameterListNode;
class ParameterDeclarationNode;
class IdentifierListNode;
class InitializerNode;
class InitializerListNode;
class TypeNameNode;
class AbstractDeclaratorNode;
class DirectAbstractDeclaratorNode;

// class ConstantExpressionNode;

class  DeclarationNode : public Node {
public:


	DeclarationNode() {}	

	// -----------------------------------------------------------------------
	
	DeclarationNode(DeclarationSpecifiersNode* declSpecifier)
		: declSpecifier(declSpecifier)
	{}

	DeclarationNode(DeclarationSpecifiersNode* declSpecifier, InitDeclaratorListNode* initDeclList)
		: declSpecifier(declSpecifier), initDeclList(initDeclList)
	{}

	// -----------------------------------------------------------------------
	
	// TODO
	virtual std::vector< Operation > toOperations()
	{
		std::vector< Operation > ops;
		return ops;
	}

	virtual std::string getNodeTypeAsString()
	{
		return std::string( "DeclarationNode" );
	}

	void declare(SymbolTable* stab) 
	{
	// BIG TODO
		std::vector<Symbol*> symList;
	
		// DeclarationSpecifiersNode::TypeInfo tInfo = declSpecifier->getTypeInfo();	
		// for (auto initDecl : initDeclList->declaratorList ) {
		// 	auto decl = initDecl->declNode;
		// 	auto init = initDecl->initNode;
		// 	auto dirDecl = decl->dirDeclNode;
		// 	auto ptr     = decl->ptrNode;

		// 	int dKind = dirDecl->getKind() ;
		// 	switch(dKind) {
		// 		case None: 
		// 			// Type()
		// 			dirDecl->identifier;
		// 			break;
		// 		case DirectDeclaratorKind::Array: 
		// 			break;
		// 		case DirectDeclaratorKind::ArrayWithSize: 
		// 			break;
		// 		case DirectDeclaratorKind::FunctionDefinition: 
		// 			break;
		// 		case DirectDeclaratorKind::FunctionDefinitionWithParam: 
		// 			break;
		// 		case DirectDeclaratorKind::FunctionCall: 
		// 			break;
		// 		case DirectDeclaratorKind::FunctionCallWithParam:
		// 			break;
		// 	}
		// }
	}

	std::string toString() const
	{
		std::cout << "DeclarationNode" << std::endl;
	}


private:
	InitDeclaratorListNode* initDeclList;		
	DeclarationSpecifiersNode* declSpecifier;
};

class TypeSpecifierNode {

private:
	size_t specs_size; 
	std::vector<std::string> specs; 
	// typedef int TypeSpecEnum;
	// TypeSpecEnum specifier;
	size_t specifier;
	// std::string specifier;

public:

	enum TypeSpecifierEnum {
		Void     = 0, TypeSpecifierStart = 0,
		Char     = 1, IntegralStart = 1,
		Short    = 2,
		Int      = 3,
		Long     = 4,
		Float    = 5,
		Double   = 6,
		Signed   = 7, IntegralEnd   = 7,
		Unsigned = 8,
		Struct   = 9,
		Union    = 10,
		Enum     = 11,
		Typedef  = 12,
		TypeSpecifierEnd
	};

public:

	std::vector<Operation> toOperations()
	{
		std::vector<Operation> emptyHack;
		return emptyHack;
	}

	std::string getNodeTypeAsString()
	{
		return "TypeSpecifier";
	}

	TypeSpecifierNode()
		: specifier(TypeSpecifierEnd)
	{initData();}

	TypeSpecifierNode(const TypeSpecifierNode& o)
		: specifier(o.specifier)
	{initData();}

	TypeSpecifierNode(std::string type) 
	{
		initData();

		// std::cerr << "addTypeSpecifier(string): TODO" << std::endl;
		bool success = false;
		for (size_t spec = 0 ; spec<specs_size ; spec++) {
			if ( specs[ spec ] == type ) {
				success = true;
				this->specifier = (TypeSpecifierEnum) spec ;
				break;
			}
		}

		// error
		if ( ! success ) {
			error("TypeSpecifier is invalid. <" + type + "> given.");
		}
	}	
	
	TypeSpecifierNode(size_t specifier)
	{
		initData();
		bool success = false;
		for ( size_t spec = TypeSpecifierStart ; spec < TypeSpecifierEnd; spec++ ) {
			if (specifier == spec) {
				success = true;
				this->specifier = (TypeSpecifierEnum) spec;
				break;
			}
		}
		// Error
		if ( ! success ) {
			std::string s( std::to_string( specifier ) );
			if ( specifier < specs_size ) {
				s = s + " " + specs[specifier];
			}
			error("TypeSpecifier is invalid. <" + s + "> given.");
		}
	}

	void initData()
	{
		specs.push_back( "void" );
		specs.push_back( "char" );
		specs.push_back( "short" );
		specs.push_back( "int" );
		specs.push_back( "long" );
		specs.push_back( "float" );
		specs.push_back( "double" );
		specs.push_back( "signed" );
		specs.push_back( "unsigned" );
		specs.push_back( "struct" );
		specs.push_back( "union" );
		specs.push_back( "enum" );
		specs.push_back( "typedef");
		specs_size = 13;
	}

	bool isIntegral()
	{
		for ( size_t integral = IntegralStart ; integral<IntegralEnd ; integral++ ) {
			if ( specifier == integral ) {
				return true;
			}
		}
		return false;
	}

	int getTypeSpecifier()
	{
		return specifier;
	}

	std::string toString()
	{	
		for (size_t spec = TypeSpecifierStart; spec < TypeSpecifierEnd; spec++ ) {
			if ( specifier == spec ) {
				return specs[spec];
			}
		}
		return "";
	}

private:
	void error(std::string error) 
	{
		std::cout << "TypeSpecifier Error : " << error << std::endl;
	}

};

class DeclarationSpecifiersNode {

	std::vector<TypeSpecifierNode*> tSpecs;
	std::vector<StorageClassSpecifierNode*> sSpecs;
	std::vector<TypeQualifierNode*> qSpecs;
	
public:

	DeclarationSpecifiersNode( StorageClassSpecifierNode* s )
	{
		sSpecs.push_back(s);
	}

	DeclarationSpecifiersNode( StorageClassSpecifierNode* s, DeclarationSpecifiersNode* ds )
	{
		*this = *ds;		
		sSpecs.push_back(s);	
	}

	DeclarationSpecifiersNode( TypeSpecifierNode* ts  )
	{
		tSpecs.push_back( ts );
	}

	DeclarationSpecifiersNode( TypeSpecifierNode* ts, DeclarationSpecifiersNode* ds )
	{
		*this = *ds;
		tSpecs.push_back(ts);
	}

	DeclarationSpecifiersNode( TypeQualifierNode* ts )
	{
		qSpecs.push_back(ts);	
	}

	DeclarationSpecifiersNode( TypeQualifierNode*tq, DeclarationSpecifiersNode* ds)
	{
		*this = *ds;
		qSpecs.push_back(tq);
	}

	void error(std::string msg)
	{
		std::cerr << "DeclarationSpecifiersNode Error : "<< msg << std::endl;	
	}

	struct TypeInfo {

		TypeInfo()
			: longSpecified(false), longLongSpecified(false),
			  unsignedSpecified(false), integral(TypeSpecifierNode::TypeSpecifierEnd) {}

		TypeInfo(bool longS, bool llongS, bool uS , int integral)
			: longSpecified(longS), longLongSpecified(llongS),
			  unsignedSpecified(uS), integral(integral) {}

		bool longSpecified;
		bool longLongSpecified ;
		bool unsignedSpecified ;
		int  integral ;
	};
	TypeInfo getTypeInfo()
	{

		bool longSpecified = false;
		bool longLongSpecified = false;
		bool unsignedSpecified = false;
		int  integral = TypeSpecifierNode::TypeSpecifierEnd;

		//
		// type check
		//
		for (auto type : tSpecs) {
			if( type->isIntegral() ) {
				if (integral == TypeSpecifierEnd) 
					integral = type->getTypeSpecifier();
				else 
					error("type specified more than once.");
				continue;
			}
			else if (type->getTypeSpecifier()==TypeSpecifierNode::Long) {
				if (longLongSpecified)
					error("long specified more than twice");
				if (longSpecified) {
					longLongSpecified = true;
					longSpecified = false;
				}
				else 
					longSpecified = true;
			}
			else if (type->getTypeSpecifier()==TypeSpecifierNode::Unsigned) {
				if (unsignedSpecified)
					error("unsigned specified more than once");
				else
					unsignedSpecified = true;
			}
		}

		if ( (longSpecified || longLongSpecified) && integral == TypeSpecifierEnd )
			integral = TypeSpecifierNode::Int;

		// 
		// Error Check
		//

		// error if integral not specified or cast to int
		// TODO

		// error if ( Float || Double ) && ( Long || Unsigned )
		if ( ( TypeSpecifierNode::Float || TypeSpecifierNode::Double ) && (TypeSpecifierNode::Long || TypeSpecifierNode::Unsigned) )
			error("( Float || Double ) && ( Long || Unsigned ) is illegal");

		// error if Void && ( Long || Unsigned )
		if ( TypeSpecifierNode::Void && ( TypeSpecifierNode::Long || TypeSpecifierNode::Unsigned) )
			error("Void && ( Long || Unsigned ) is illegal");

		// error if Void and not a function return
		// TODO
		// if (TypeSpecifierNode::Void)

		return TypeInfo( longSpecified, longLongSpecified, unsignedSpecified, integral );
	}

	// TODO
	struct StorageInfo {
	};
	StorageInfo getStorageInfo()
	{
		return StorageInfo();
	}

	// TODO
	struct TypeQualInfo {
		bool constness;
		bool volatileness;
	};
	TypeQualInfo getTypeQualInfo() 
	{
		return TypeQualInfo();
	};

	
};

class StorageClassSpecifierNode {
private:
	int specifier;

const char specs[5][10] = {
	"auto",
	"register",
	"static",
	"extern",
	"typedef"
};

public:

	virtual std::vector< Operation > toOperations() { } 

	virtual std::string getNodeTypeAsString() {}

	enum StorageSpecifierKind {
		Auto = 0,  StorageSpecifierKindStart = 0,
		Register,
		Static,
		Extern,
		Typedef, StorageSpecifierKindEnd = Typedef,
	};

	StorageClassSpecifierNode() {}
	// StorageClassSpecifierNode(const std::string& s) : s(s) {}
	StorageClassSpecifierNode(int storageSpecKind ) 
	{
		if ( StorageSpecifierKindStart  <= storageSpecKind && storageSpecKind <= StorageSpecifierKindEnd ) {
			specifier = storageSpecKind;
		}
		else {
			throw ParserError(ParserError::Whatever, "StorageClassSpecifierNode");
		}
	}

};

class TypeQualifierNode {
};

class StructOrUnionSpecifierNode {
};

class StructOrUnionNode {
};

class StructDeclarationListNode {
};

class InitDeclaratorListNode {
public:

	InitDeclaratorListNode() {}

	InitDeclaratorListNode( InitDeclaratorNode* n)
	{
		declaratorList.push_back(n);
	}

	InitDeclaratorListNode( InitDeclaratorListNode* a,  InitDeclaratorNode* b )
	{
		*this = *a;
		declaratorList.push_back(b);
	}


	void add(InitDeclaratorNode* initDecl) 
	{
		declaratorList.push_back(initDecl);	
	}

	std::vector<InitDeclaratorNode*> declaratorList;
};

class InitDeclaratorNode {
public:

	InitDeclaratorNode() {}

	InitDeclaratorNode(DeclaratorNode* declNode) 
		: declNode(declNode)
	{}

	InitDeclaratorNode(DeclaratorNode* declNode, InitializerNode* initNode) 
		: declNode(declNode), initNode(initNode)
	{}

	DeclaratorNode* declNode;
	InitializerNode* initNode;
};

class StructDeclarationNode {
};

class SpecifierQualifierListNode {
};

class StructDeclaratorListNode {
};

class StructDeclaratorNode {
};

class EnumSpecifierNode {
};

class EnumeratorListNode {
};

class EnumeratorNode {
};

class DeclaratorNode {
public:

	DeclaratorNode() {}

	DeclaratorNode(DirectDeclaratorNode* dirDeclNode) 
		: dirDeclNode(dirDeclNode), ptrNode(NULL)
	{}

	DeclaratorNode(PointerNode* ptrNode, DirectDeclaratorNode* dirDeclNode) 
		: dirDeclNode(dirDeclNode), ptrNode(ptrNode)
	{}

	bool isPointer()
	{
		return (ptrNode!=NULL);
	}

	DirectDeclaratorNode* dirDeclNode;
	PointerNode* ptrNode;
};

class DirectDeclaratorNode {
public:

	enum DirectDeclaratorKind {
		None,
		Array,
		ArrayWithSize,
		FunctionDefinition,
		FunctionDefinitionWithParam,
		FunctionCall,
		FunctionCallWithParam
	};

	DirectDeclaratorNode() {initData();}

	DirectDeclaratorNode( DirectDeclaratorNode* a)
	{
		initData();	
		dirDeclNode = a;
	}

	DirectDeclaratorNode( IdentifierNode* id )
		: id(id)
	{initData();}

	void initData()
	{
		array = false;
		functionCall = false;
		functionDefinition = false;

		kind = None;

		id = NULL;
		dirDeclNode = NULL;
		declNode = NULL;
		idListNode = NULL;
		arraySize = NULL;
		funcParams = NULL;
	}

	void specifyArray()
	{
		// TODO check existence of initializer in the upstream
		array = true;
		kind = Array;
	}

	void specifyArray( ConstantExpressionNode* a)
	{
		arraySize = a;
		array = true;
		kind = ArrayWithSize;
	}

	void specifyFunction( ParameterTypeListNode* a )
	{
		funcParams = a;
		functionDefinition = true; // TODO is this right?
		kind = FunctionDefinitionWithParam;
	}

	void specifyFunctionCall( IdentifierListNode* a )
	{
		functionCall = true;
		idListNode = a;	
		kind = FunctionCallWithParam;
	}

	int getKind()
	{
		return kind;
	}
	
private:
	IdentifierNode* id;
	DeclaratorNode* declNode;		
	DirectDeclaratorNode* dirDeclNode;
	IdentifierListNode* idListNode;
	ConstantExpressionNode* arraySize;
	ParameterTypeListNode* funcParams;

	int kind;

	bool array;
	bool functionCall;
	bool functionDefinition; // declaration?
};

class PointerNode {

};

class TypeQualifierListNode {
};

class ParameterTypeListNode {
};

class ParameterListNode {
};

class ParameterDeclarationNode {
};

class IdentifierListNode {
};

class InitializerNode {
public:

	InitializerNode() {}

	InitializerNode(AssignmentExpressionNode* assignExprNode) 
		: assignExprNode(assignExprNode)
	{}

	InitializerNode(InitializerListNode* initListNode)
		: initListNode( initListNode )
	{}
			

private:
	AssignmentExpressionNode* assignExprNode;
	InitializerListNode* initListNode;
};

class InitializerListNode {
public:

	InitializerListNode(InitializerNode* initNode)
	{
		initializerList.push_back(initNode);
	}

	InitializerListNode(InitializerNode* initNode, InitializerListNode* initListNode)
	{
		initializerList.push_back(initNode);
		for (size_t i = 0; i <initListNode->initializerList.size(); i++ )	{
			initializerList.push_back( initListNode->initializerList[i] );
		}
	}

	size_t size() { return initializerList.size(); };

	std::vector<InitializerNode*> initializerList;
};

class TypeNameNode {
};

class AbstractDeclaratorNode {
};

class DirectAbstractDeclaratorNode {
};

//  -----------------------------------------------------------------------------
//
//  Fake Expression to cope with a ton of expressions
//

/*
class Expression {
public:
	Expression(Expression* exp) 
		: exp1(exp) 
	{
		initData();
	}

	Expression(Expression* exp1, Expression* exp2) 
		: exp1(exp1), exp2(exp2)
	{
		initData();
	}

	void initData()
	{
		exp1 = exp2 = NULL;	
	}

private:
	typedef std::string ExpressionKind; // temporary
	ExpressionKind kind;	
	Expression* exp1;
	Expression* exp2;
};
*/

#endif /* ASTNODES_H_ */
