#include "operand.h"
#include "tac.h"
#include "tac_easy.h"
#include <iostream>
using namespace std;

int main()
{
	// -----------------------------------------------------------------------
	// 3AC with typecheck
	cout << "=============================" << endl;
	cout << "3AC with typecheck" << endl;
	cout << "-----------------------------" << endl;

	// 3AC String operand
	OperandString ostring("a");
	std::cout << ostring.toString() << std::endl;

	// 3AC Itemp operand
	OperandItemp oitemp1(1);
	OperandItemp oitemp2(2);
	OperandItemp oitemp3(3);
	std::cout << oitemp1.toString() << std::endl;
	std::cout << oitemp2.toString() << std::endl;
	std::cout << oitemp3.toString() << std::endl;

	// Add 3AC
	// Have to specify template arguments : little annoying
	TACAdd<OperandItemp, OperandItemp, OperandItemp> addop(oitemp1, oitemp2, oitemp3);

	// Add 3AC with OperandString( cannot be added to anything )  to TACAdd so this should be a compile time error
	// TACAdd<OperandString, OperandItemp, OperandItemp> addop_should_fail(ostring, oitemp1 , oitemp1);

	std::cout << addop.toString() << std::endl;
	cout << "=============================" << endl;
	cout << endl;

	// -----------------------------------------------------------------------
	// Eacy 3AC without typechecking
	// Almost everything is represented by string
	
	cout << "=============================" << endl;
	cout << "Eacy 3AC without typechecking" << endl;
	cout << "-----------------------------" << endl;
	OperandEasy s(OperandType::STRING, "hello");

	OperandEasy i(OperandType::ITEMP, "1");
	OperandEasy j(OperandType::ITEMP, "2");
	OperandEasy k(OperandType::ITEMP, "3");

	// TACEasy with three temporary integer
	cout << "TACEasy with three temporary integer" << endl;
	TACEasy tac(OperationType::ADD,i,j,k);
	std::cout << tac.toString() << std::endl << endl;

	// this TACEasy does not type check
	cout << "this TACEasy does not type check" << endl;
	TACEasy tac_invalid(OperationType::ADD,s,s,s);
	std::cout << tac_invalid.toString() << std::endl;

	cout << "=============================" << endl;
	cout << endl;
	

}
