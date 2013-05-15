/*
 * BranchEqualOp.h
 *
 *  Created on: Apr 26, 2013
 *      Author: njordan
 */

#ifndef BRANCHOP_H_
#define BRANCHOP_H_

#include "Operation.h"

#include <boost/format.hpp>
class BranchEqualOp: public Operation {

public:

	inline BranchEqualOp( Label* _branchTo ,Operand* _op1, Operand* _op2 ) : Operation(_op1,_op2,0) , branchTo(_branchTo)
	{

	}

	std::string to3AC()
	{

		return std::string("BEQUAL ") + op1->getId() + ":" + op1->getTacTypeAsString() + " " + op2->getId() + ":" + op2->getTacTypeAsString() + " " + branchTo->getName();

	}

private:

	Label* branchTo = 0;

};

#endif /* UNCONDITIONALJUMPOP_H_ */
