#ifndef OPERAND_H_GUARD
#define OPERAND_H_GUARD

#include <string>
#include <sstream>

// ---------------------------------------------------------------------------
// Auxilaries

// TODO
// CharTemp and other mips types?
enum OperandType {
		LOCAL,
		GLOB,
		ITEMP,
		FTEMP,
		CONS,
		FCONS,
		INDR,
		LABEL,
		REFAR,
		VALARG,
		STRING,
		NONE
};

std::string operandTypeToString(OperandType t)
{
	switch(t) {
		case OperandType::LOCAL:  return std::string( "local" );
		case OperandType::GLOB:   return std::string( "glob" );
		case OperandType::ITEMP:  return std::string( "itemp" );
		case OperandType::FTEMP:  return std::string( "ftemp" );
		case OperandType::CONS:   return std::string( "cons" );
		case OperandType::FCONS:  return std::string( "fcons" );
		case OperandType::INDR:   return std::string( "indr" );
		case OperandType::LABEL:  return std::string( "label" );
		case OperandType::REFAR:  return std::string( "refar" );
		case OperandType::VALARG: return std::string( "valarg" );
		case OperandType::STRING: return std::string( "string" );
		case OperandType::NONE:   return std::string( "none" );
	}
	return "ERROR in operandTypeToString";
}

// ---------------------------------------------------------------------------
// Abstract Base Operand

template <class Data>
class Operand {

protected:

	Operand(OperandType type, Data data)
		: type(type), data(data)
	{}

public:

	std::string toString();

	OperandType type;
	Data data;
};

// ---------------------------------------------------------------------------
// Source
// ---------------------------------------------------------------------------
// #include "operand.h"

std::string prefix  = "(";
std::string  pad = " ";
std::string postfix = ")";

// ---------------------------------------------------------------------------
// Operand

//
// priting of all the operands should be done through this function so that
// parsing 3AC will be easier with consistent format
//
template <class Data>
std::string Operand<Data>::toString()
{
	std::ostringstream s;
	s 
		<< prefix 
		<< operandTypeToString(type) 
		<< pad 
		<< data 
		<< postfix ;
	return s.str();
}

// ---------------------------------------------------------------------------
// Operand Tag
// class Stringifiable { virtual std::string toString() { return ""; } };
// class Additive {};
class Number {};

// ---------------------------------------------------------------------------
// Concrete Operands

class OperandLocal  : public Operand<size_t>{};

class OperandGlob  : public Operand<std::string> {
	OperandGlob(std::string data)
		: Operand<std::string>(OperandType::GLOB, data)
	{}
};

typedef int TYPE;
class OperandItemp  : public Operand<TYPE>, public Number {
public:
	OperandItemp(TYPE i) 
		: Operand<TYPE >(OperandType::ITEMP, i)
	{}
};

/*
class OperandFtemp  : public Operand<float>{};
class OperandCons   : public Operand<int>{};
class OperandFCons  : public Operand<float>{};
class OperandIndr   : public Operand<size_t>{};
class OperandLabel  : public Operand<size_t>{}; // use IdTracker in constructor
class OperandRefar  : public Operand<size_t>{};
class OperandValarg : public Operand<size_t>{};
*/

class OperandString : public Operand<std::string> {
public:
	OperandString(std::string data)
		: Operand<std::string>(OperandType::STRING, data)
	{}
};

// class OperandNone   : public Operand<int>/*TODO:what should it be*/{};

#endif
