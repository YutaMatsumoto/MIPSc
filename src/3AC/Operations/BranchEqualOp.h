/*
 * BranchEqualOp.h
 *
 *  Created on: Apr 26, 2013
 *      Author: njordan
 */

#ifndef BRANCHOP_H_
#define BRANCHOP_H_

#include "Operation.h"

class BranchEqualOp: public Operation {

public:

	inline BranchEqualOp( Label* _branchTo ,Operand* _op1, Operand* _op2 ) : Operation(_op1,_op2,0) , branchTo(_branchTo)
	{

	}

	std::string to3AC()
	{

		return std::string("BEQUAL ") + op1->getId() + " " + op2->getId() + branchTo->getName();

	}

private:

	Label* branchTo = 0;

};

#endif /* UNCONDITIONALJUMPOP_H_ */
