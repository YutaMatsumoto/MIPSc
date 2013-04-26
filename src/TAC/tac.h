#ifndef TAC_H_GUARD
#define TAC_H_GUARD

#include <string>
#include "operand.h"

// ---------------------------------------------------------------------------
// enum

enum class OperationType {
	ADD,
	SUB,
	MULT,
	DIV,
	NEG,
	EQ,
	GT,
	LT,
	GE,
	LE,
	NE,
	ASSIGN,
	LABEL,
	BR,
	BREQ,
	BRGT,
	BRLT,
	BRGE,
	BRLE,
	BRNE,
	HALT,
	ARGS,
	REFOUT,
	VALOUT,
	CALL,
	PROCENTRY,
};

	
std::string operationTypeToString(OperationType t)
{
	switch(t) {
		case OperationType::ADD:       return std::string( "ADD" );
		case OperationType::SUB:       return std::string( "SUB" );
		case OperationType::MULT:      return std::string( "MULT" );
		case OperationType::DIV:       return std::string( "DIV" );
		case OperationType::NEG:       return std::string( "NEG" );
		case OperationType::EQ:        return std::string( "EQ" );
		case OperationType::GT:        return std::string( "GT" );
		case OperationType::LT:        return std::string( "LT" );
		case OperationType::GE:        return std::string( "GE" );
		case OperationType::LE:        return std::string( "LE" );
		case OperationType::NE:        return std::string( "NE" );
		case OperationType::ASSIGN:    return std::string( "ASSIGN" );
		case OperationType::LABEL:     return std::string( "LABEL" );
		case OperationType::BR:        return std::string( "BR" );
		case OperationType::BREQ:      return std::string( "BREQ" );
		case OperationType::BRGT:      return std::string( "BRGT" );
		case OperationType::BRLT:      return std::string( "BRLT" );
		case OperationType::BRGE:      return std::string( "BRGE" );
		case OperationType::BRLE:      return std::string( "BRLE" );
		case OperationType::BRNE:      return std::string( "BRNE" );
		case OperationType::HALT:      return std::string( "HALT" );
		case OperationType::ARGS:      return std::string( "ARGS" );
		case OperationType::REFOUT:    return std::string( "REFOUT" );
		case OperationType::VALOUT:    return std::string( "VALOUT" );
		case OperationType::CALL:      return std::string( "CALL" );
		case OperationType::PROCENTRY: return std::string( "PROCENTRY" );
	}
	return "ERROR in operationTypeToString";
}

// ---------------------------------------------------------------------------
// 3AC : Base Classes

class TACVoid {
public:
	std::string toString()
	{
		std::ostringstream s;
		s 
			<< operationTypeToString(type) 
			;
		return s.str();
	}
protected:
	TACVoid(OperationType type)
		: type(type)
	{}
	OperationType type;
};

template <class Operand1>
class TACUnary {
public:
	std::string toString()
	{
		std::ostringstream s;
		s 
			<< operationTypeToString(type) 
			<< pad
			<< operand1.toString()
			;
		return s.str();
	}
protected:
	TACUnary(OperationType type, Operand1 a)
		: type(type), operand1(a)
	{}
private:
	OperationType type;
	Operand1 operand1;
};

template <class Operand1, class Operand2>
class TACBinary {
public:
	std::string toString()
	{
		std::ostringstream s;
		s 
			<< operationTypeToString(type) 
			<< pad
			<< operand1.toString()
			<< pad
			<< operand2.toString()
			;
		return s.str();
	}

protected:
	TACBinary(OperationType type, Operand1 a, Operand2 b)
		: type(type), operand1(a), operand2(b)
	{}

private:
	OperationType type;
	Operand1 operand1;
	Operand2 operand2;
};

template <class Operand1, class Operand2, class Operand3> 
class TACTernary {
public:
	std::string toString()
	{
		std::ostringstream s;
		s 
			<< operationTypeToString(type) 
			<< pad
			<< operand1.toString()
			<< pad
			<< operand2.toString()
			<< pad
			<< operand3.toString()
			;
		return s.str();
	}
protected:
	TACTernary(OperationType type, Operand1 a, Operand2 b, Operand3 c)
		: type(type), operand1(a), operand2(b), operand3(c)
	{}
private:
	OperationType type;
	Operand1 operand1;
	Operand2 operand2;
	Operand3 operand3;
};

// ---------------------------------------------------------------------------
// Compiler assertion
//
// From [Restrict C++ Template Parameter to Subclass - Stack Overflow](http://stackoverflow.com/questions/3175219/restrict-c-template-parameter-to-subclass)
//

//
// Check T is derived from B.
//
template<class T, class B> struct Derived_from {
        static void constraints(T* p) { B* pb = p; /*suppress warning*/ pb = pb; }
        Derived_from() { void(*p)(T*) = constraints; /*suppress warning*/ p = p; }
};

// ---------------------------------------------------------------------------
// 3AC : Concret

template <class A, class B, class C>
class TACAdd : public TACTernary<A,B,C> {
public:
	TACAdd(A a, B b, C c)
		: TACTernary<A,B,C>(OperationType::ADD, a,b,c) 
	{
		// Check that arguments A,B,C are numbers
		Derived_from<A, Number>();
		Derived_from<B, Number>();
		Derived_from<C, Number>();
	}
};

/* TODO
class TACSub       : public TACTernary {};
class TACMult      : public TACTernary {};
class TACDiv       : public TACTernary {};
class TACNeg       : public TACBinary {};
class TACEq        : public ? {};
class TACGt        : public ? {};
class TACLt        : public ? {};
class TACGe        : public ? {};
class TACLe        : public ? {};
class TACNe        : public ? {};
class TACAssign    : public ? {};
class TACLabel     : public ? {};
class TACBr        : public ? {};
class TACBreq      : public ? {};
class TACBrgt      : public ? {};
class TACBrlt      : public ? {};
class TACBrge      : public ? {};
class TACBrle      : public ? {};
class TACBrne      : public ? {};
class TACHalt      : public ? {};
class TACArgs      : public ? {};
class TACRefout    : public ? {};
class TACValout    : public ? {};
class TACCall      : public ? {};
class TACProcentry : public ? {};
*/

#endif
