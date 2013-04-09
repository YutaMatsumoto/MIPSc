/*
 * ASTNodes.h
 *
 *  Created on: Apr 3, 2013
 *      Author: njordan
 */

#ifndef ASTNODES_H_
#define ASTNODES_H_

#include "Node.h"
#include <cfloat>

//Forward Declarations
class ExpressionNode;
class CastExpressionNode;
class TypeNameNode;

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


class AssignmentExpressionNode : public Node
{

public:

	inline AssignmentExpressionNode( )
	{



	}


	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "assignment expression" );

	}

	//~ArgExpressionListNode(){}

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

		return std::string( "unary operator" );

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

		return std::string( "unary operator" );

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

		return std::string( "unary operator" );

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

		return std::string( "unary operator" );

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

		return std::string( "unary operator" );

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

		return std::string( "unary operator" );

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

		return std::string( "unary operator" );

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

		return std::string( "unary operator" );

	}

	AndExpressionNode* andExpression;
	EqualityExpressionNode* equalityExpression;

};

// TODO: This is temporary
class ExpressionNode : public Node
{

};

// TODO: This is temporary
class TypeNameNode : public Node
{

};

#endif /* ASTNODES_H_ */
