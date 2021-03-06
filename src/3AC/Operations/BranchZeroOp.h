/*
 * BranchOp.h
 *
 *  Created on: Apr 26, 2013
 *      Author: njordan
 */

#ifndef BRANCHZEROOP_H_
#define BRANCHZEROOP_H_

#include "Operation.h"
#include "Label.h"

#include <boost/format.hpp>

class BranchZeroOp: public Operation {

public:

	inline BranchZeroOp( Label* _branchTo ,Operand* _op1 ) : Operation(_op1,0,0) , branchTo(_branchTo)
	{

	}

	virtual void produceMips();

	std::string to3AC()
	{

		//return std::string("BZERO ") + op1->getId() + ":" + op1->getTacTypeAsString() + " " + branchTo->getName();

		return ( boost::format( "%-15s%-15s%-15s" ) % std::string( "BZERO ") % (op1->getId() + ":" + op1->getTacTypeAsString()) % branchTo->getName() ).str();

	}

private:

	Label* branchTo = 0;

};

#endif /* UNCONDITIONALJUMPOP_H_ */
