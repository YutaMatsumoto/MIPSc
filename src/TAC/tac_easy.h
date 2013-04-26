#ifndef TAC_EASY_H_GUARD
#define TAC_EASY_H_GUARD

#include <string>
#include <sstream>

// ---------------------------------------------------------------------------
// Include auxilary functions and variables
#include "operand.h"

// ---------------------------------------------------------------------------

class OperandEasy {
public:
	typedef std::string FieldValue;

	OperandEasy( OperandType type, FieldValue value)
		: type(type), value(value)
	{}

	std::string toString()
	{
		std::ostringstream s;
		s 
			<< prefix 
			<< operandTypeToString( type )
			<< pad 
			<< value
			<< postfix ;
		return s.str();
	}

private:
	OperandType type;
	FieldValue  value;
};

class TACEasy {
public:

	TACEasy(OperationType type, OperandEasy a, OperandEasy b, OperandEasy c)
		: type(type), a(a), b(b), c(c)
	{}

	std::string toString()
	{
		std::ostringstream s;
		s 
			<< operationTypeToString( type )
			<< pad
			<< a.toString()
			<< pad
			<< b.toString()
			<< pad
			<< c.toString()
			;
		return s.str();
	}

private:
	OperationType type;
	OperandEasy a,b,c;
};

#endif
