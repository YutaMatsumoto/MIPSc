/*
 * BranchOp.h
 *
 *  Created on: Apr 26, 2013
 *      Author: njordan
 */

#ifndef BRANCHOP_H_
#define BRANCHOP_H_

#include "Operation.h"

class BranchEqualOp: public Operation {

public:

	inline BranchEqualOp( Label* _branchTo ,Operand* _op1 ) : Operation(_op1,0,0) , branchTo(_branchTo)
	{

	}

	std::string to3AC()
	{

		return std::string("BRANCH TO ") + branchTo->getName() + std::string(" IF ") + op1->getId() + std::string(" == 0");

	}

private:

	Label* branchTo = 0;

};

#endif /* UNCONDITIONALJUMPOP_H_ */
