#include "Common.h"
#include "Symbol.h"

#ifndef EXPRESSHON_H_GUARD
#define EXPRESSHON_H_GUARD

// Should be tree
class Expression { // : public Statement {
	typedef Symbol* Operand;
	// typedef int    Operator;

friend std::ostream& operator<< (std::ostream &out, Expression &exp);

	enum Operator {
		Addition,
		Multiplication,
		Subtraction,
		Division,
		/* Unary operators
		Increment,
		Decrement,
		UnaryPlus,
		UnaryMinus,
		Modulo, 
		AddressResolution, // &
		UnaryStar, 
		Tilda,  // ~
		Negation // !
		*/
		OperatorEnd
	};

public:

	// TODO
	//
	// why does bisonc++ type-definitionthat appear in polymorphic have to have a
	// defualt constructor?
	//
	Expression() 
		: operand(NULL), equalFlag(false)
	{}

	Expression(Operand operand)
		: operand(operand), equalFlag(false)
	{}

	Code toIntermediateCode() 
 	{
		// TODO
		std::cout << "toIntermediateCode() :  TODO" << std::endl;
		return Code();
	}

	Code toMips() 
	{
		// TODO
		std::cout << "toMips() :  TODO" << std::endl;
		return Code();
	}


	std::string toString();

	// TODO Do not forget to check lvalue/rvalue
	//		Type check functions need to be in Symbol, this class should just
	//		delegate to Symbol
	//
	// TODO Do typecheck and coercion properly
	
	// Expression& operator=(const Expression& o);

	Expression& operator+(const Expression& o);
	Expression& operator-(const Expression& o);
	Expression& operator*(const Expression& o);
	Expression& operator/(const Expression& o);

	Expression& operator==(const Expression& o);

	Expression& operator+=(const Expression& o);
	Expression& operator-=(const Expression& o);
	Expression& operator*=(const Expression& o);
	Expression& operator/=(const Expression& o);

private:
	// Expression needs at least one operand
	Operand operand;

	// Additionaly, Expression can have a rigth hand side with an associated
	// operator. Ex. (1+(2)).
	// But if op is unary, rhs holds nothing ((1) unary-minus nth)
	int op;
	// Expression rhs;	

	// Additional pairs of operator and operands
	// std::vector< Expression >  operators;
	// std::vector< Operand    >  oprands;

	// 
	bool equalFlag;	
	
};

inline std::ostream& operator<<(std::ostream &out, Expression &exp)
{
	if ( exp.operand==NULL) {
		out << "Symbol inside of Expression is null" << std::endl;
	}
	else {
		out << "(" << *(exp.operand) ;
		if (exp.op!=Expression::OperatorEnd) {
			std::cout << *(exp.operand) << " : ";
			out << " : equalFlag: " << exp.equalFlag;
		}
		out << ")"; 
	}
	return out;
}



#endif
