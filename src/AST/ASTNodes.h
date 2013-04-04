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


class IdentifierNode : public Node
{

public:

	inline IdentifierNode( Node* _parent, std::string _id ) : id( _id )
	{

	}

	inline std::string getId()
	{
		return id;
	}

protected:

	std::string id;

};


class StringNode : public Node
{

public:

	inline IdentifierNode( std::string _value ) : value( _value )
	{

	}

	inline std::string getValue()
	{
		return value;
	}

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


protected:

	char value;

};


class ArgExpressionListNode : public Node
{

public:

	inline ArgExpressionListNode( )
	{

	}

	Node* assignmentExpression;
	Node* argumentExpressionList;
	Node* assignmentExpression;

};


class PrimaryExpressionNode : public Node
{

public:

	inline PrimaryExpressionNode( )
	{

	}

	Node* identifier;
	Node* constant;
	Node* string;
	Node* expression;

};




#endif /* ASTNODES_H_ */
