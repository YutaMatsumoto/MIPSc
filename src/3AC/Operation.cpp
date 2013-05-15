/*
 * Operation.cpp
 *
 *  Created on: Apr 3, 2013
 *      Author: njordan
 */

#include "Operation.h"

void Operation::produceMips()
{
	std::cout << "NOT IMPLEMENTED" << std::endl;
}

Operation::Operation( Operand* _op1 , Operand* _op2 , Operand* _op3 ) : op1(_op1), op2(_op2), op3(_op3) {
	// TODO Auto-generated constructor stub

}

Operation::~Operation() {
	// TODO Auto-generated destructor stub
}

std::vector< std::string > Operation::toMIPS()
{

	std::vector< std::string > v;

	v.push_back( std::string("# NOT IMPLEMENTED") );

	return v;

}
