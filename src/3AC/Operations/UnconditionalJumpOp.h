/*
 * UnconditionalJumpOp.h
 *
 *  Created on: Apr 26, 2013
 *      Author: njordan
 */

#ifndef UNCONDITIONALJUMPOP_H_
#define UNCONDITIONALJUMPOP_H_

#include "Operation.h"

#include <boost/format.hpp>
class UnconditionalJumpOp: public Operation {

public:

	inline UnconditionalJumpOp( Label* _jumpTo ) : Operation(0,0,0) , jumpTo(_jumpTo)
	{

	}

	virtual void produceMips()
	{

		/*
		unsigned int op1Id = 1;
		// Type* typeOfOp1 = op1->getType();

		std::string labelName = jumpTo->getName();
		MipsVariable opArg2( labelName, 0, op1Id );
		MipsCode::getInstance().writeToDataSection( opArg2, "" );

		MipsCode::getInstance().writeToTextSection( 
			"j " +  labelName , "Unconditional Jump"
		);
		*/

		MipsCode::getInstance().writeToTextSection( 
			"j " + jumpTo->getName(), "Unconditional Jump"
		);

	}

	std::string to3AC()
	{

		//return std::string("JMP ") + jumpTo->getName();

		return ( boost::format( "%-15s%-15s" ) % std::string( "JUMP") % jumpTo->getName() ).str();

	}

private:

	Label* jumpTo = 0;

};

#endif /* UNCONDITIONALJUMPOP_H_ */
