/*
 * ASTNodes.h
 *
 *  Created on: Apr 3, 2013
 *      Author: njordan
 */

#ifndef ASTNODES_H_
#define ASTNODES_H_

//#include "ParserError.h"
#include "Node.h"
#include <cfloat>
#include "SymbolTable.h"

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

		return std::string( "unary operator" );

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

		return std::string( "unary operator" );

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

	inline LogicalAndExpressionNode( InclusiveOrExpressionNode* _inclusiveOrExpressionNode ,
			LogicalAndExpression* _logicalAndExpression
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

		return std::string( "unary operator" );

	}

	InclusiveOrExpressionNode* inclusiveOrExpressionNode;
	LogicalAndExpression* logicalAndExpression;

};

class LogicalOrExpressionNode : public Node
{

public:

	inline LogicalOrExpressionNode( LogicalAndExpression* _logicalAndExpression ) : logicalAndExpression( _logicalAndExpression )
	{

	}

	inline LogicalOrExpressionNode( LogicalAndExpression* _logicalAndExpression ,
			LogicalOrExpression* _logicalOrExpression
			)
		: logicalAndExpression( _logicalAndExpression ), logicalOrExpression( _logicalOrExpression )
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

	LogicalOrExpression* logicalOrExpression;
	LogicalAndExpression* logicalAndExpression;

};

// TODO: This is temporary
class ExpressionNode : public Node
{

};


// ---------------------------------------------------------------------------
//
// DeclarationNode ... DirectAbstractDeclaratorNode
//

class DeclarationNode;
class DeclarationListNode;
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

class DeclarationNode : public Node {
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

	void declare(SymbolTable* stab) 
	{
		std::cout << "DeclarationNode::declare() TODO" << std::endl;
	}

private:
	InitDeclaratorListNode* initDeclList;		
	DeclarationSpecifiersNode* declSpecifier;
};

class DeclarationSpecifiersNode : public Node {

	typedef std::string TypeQualifierNode;

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


// 	DeclarationSpecifiersNode() {}

// 	void addTypeSpecifier(TypeSpecifierNode t)
// 	{
// 		tSpecs.push_back(t);
// 	}

// 	void addStorageSpecifier(StorageClassSpecifierNode s)
// 	{
// 		sSpecs.push_back(s);
// 	}

// 	void addTypeQualifier(std::string s)
// 	{
// 		qSpecs.push_back(s);
// 	}

// 	bool determineType()
// 	{
// 		// TODO
// 		return true;
// 	}

	
};

class StorageClassSpecifierNode : public Node {
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

static const size_t specs_size = 13;
const std::string specs[specs_size] = {
"void",
"char",
"short",
"int",
"long",
"float",
"double",
"signed",
"unsigned",
"struct",
"union",
"enum",
"typedef"
};
class TypeSpecifierNode : public Node {

private:
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
	{}

	TypeSpecifierNode(const TypeSpecifierNode& o)
		: specifier(o.specifier)
	{}

	TypeSpecifierNode(std::string type) 
	{

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

	bool isIntegral()
	{
		for ( size_t integral = IntegralStart ; integral<IntegralEnd ; integral++ ) {
			if ( specifier == integral ) {
				return true;
			}
		}
		return false;
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

class TypeQualifierNode : public Node {
};

class StructOrUnionSpecifierNode : public Node {
};

class StructOrUnionNode : public Node {
};

class StructDeclarationListNode : public Node {
};

class InitDeclaratorListNode : public Node {
public:

	InitDeclaratorListNode() {}

	void add(InitDeclaratorNode* initDecl) 
	{
		declaratorList.push_back(initDecl);	
		if ( StorageSpecifierKindStart  <= storageSpecKind && storageSpecKind <= StorageSpecifierKindEnd ) {
			specifier = storageSpecKind;
		}
		else {
			//throw ParserError(ParserError::Whatever, "StorageSpecifierNode");
		}
	}

private:
	std::vector<InitDeclaratorNode*> declaratorList;
};

class InitDeclaratorNode : public Node {
public:

	InitDeclaratorNode() {}

	InitDeclaratorNode(DeclaratorNode* declNode) 
		: declNode(declNode)
	{}

	InitDeclaratorNode(DeclaratorNode* declNode, InitializerNode* initNode) 
		: declNode(declNode), initNode(initNode)
	{}

private:
	DeclaratorNode* declNode;
	InitializerNode* initNode;
};

class StructDeclarationNode : public Node {
};

class SpecifierQualifierListNode : public Node {
};

class StructDeclaratorListNode : public Node {
};

class StructDeclaratorNode : public Node {
};

class EnumSpecifierNode : public Node {
};

class EnumeratorListNode : public Node {
};

class EnumeratorNode : public Node {
};

class DeclaratorNode : public Node {
public:

	DeclaratorNode() {}

	DeclaratorNode(DirectDeclaratorNode* dirDeclNode) 
		: dirDeclNode(dirDeclNode)
	{}

	DeclaratorNode(PointerNode* ptrNode, DirectDeclaratorNode* dirDeclNode) 
		: ptrNode(ptrNode), dirDeclNode(dirDeclNode)
	{}

private:	
	DirectDeclaratorNode* dirDeclNode;
	PointerNode* ptrNode;
};

class DirectDeclaratorNode : Node {
public:

	DirectDeclaratorNode() {initData();}

	DirectDeclaratorNode( IdentifierNode* id )
		: id(id)
	{initData();}

	void initData()
	{
		array = false;
		functionCall = false;
		functionDefinition = false;
	}
	
private:
	IdentifierNode* id;
	DirectDeclaratorNode* dirDeclNode;
	DeclaratorNode* declNode;		
	IdentifierListNode* idListNode;

	bool array;
	bool functionCall;
	bool functionDefinition; // declaration?
};

class PointerNode : public Node {
};

class TypeQualifierListNode : public Node {
};

class ParameterTypeListNode : public Node {
};

class ParameterListNode : public Node {
};

class ParameterDeclarationNode : public Node {
};

class IdentifierListNode : public Node {
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

class TypeNameNode : public Node {
};

class AbstractDeclaratorNode : public Node {
};

class DirectAbstractDeclaratorNode : public Node {
};

#endif /* ASTNODES_H_ */
