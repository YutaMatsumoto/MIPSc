/*
 * UnconditionalJumpOp.h
 *
 *  Created on: Apr 26, 2013
 *      Author: njordan
 */

#ifndef UNCONDITIONALJUMPOP_H_
#define UNCONDITIONALJUMPOP_H_

#include "Operation.h"

class UnconditionalJumpOp: public Operation {

public:

	inline UnconditionalJumpOp( Label* _jumpTo ) : Operation(0,0,0) , jumpTo(_jumpTo)
	{

	}

	std::string to3AC()
	{

		return std::string("JMP ") + jumpTo->getName();

	}

private:

	Label* jumpTo = 0;

};

#endif /* UNCONDITIONALJUMPOP_H_ */
