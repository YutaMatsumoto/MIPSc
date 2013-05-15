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

	virtual void produceMips()
	{
		DescriptorTable& dTable = DescriptorTable::getInstance();
		MipsCode& mCode = MipsCode::getInstance();

		mCode.writeToTextSection( "# >>>>>>>>>>>>>>> BranchEqualOp Start", "" );

		// beq $s, $t, offset 
		unsigned int op1Id = op1->getUniqueId();
		unsigned int op2Id = op2->getUniqueId();

		// Type
		Type* typeOfOp1 = op1->getType();
		Type* typeOfOp2 = op2->getType();

		// ID and Type
		MipsVariable opResult( typeOfOp1, op1Id );
		MipsVariable opArg2( typeOfOp2, op2Id );

		// reserve the memory
		// TODO need to ?
		mCode.writeToDataSection( opResult, "" );
		mCode.writeToDataSection( opArg2, "" );

		RegisterInfo r1 = dTable.getRegister( opResult );
		RegisterInfo r2 = dTable.getRegister( opArg2   );

		if ( r1.isNew() ) {
			mCode.writeToTextSection(
					"lw "+ r1.getRegister().toString()+","+ opResult.toDLabel().toString(),
					""                                   
			);	                                         
		}                                                
		if ( r2.isNew() ) {                              
			mCode.writeToTextSection(                    
					"lw "+ r2.getRegister().toString()+","+ opArg2.toDLabel().toString(),
					""
			);	
		}

		// Convert Registers Obtained to Strings like "$5"
		std::string r1str = r1.getRegister().toString();
		std::string r2str = r2.getRegister().toString();

		MipsCode::getInstance().writeToTextSection(
				"beq " + r1str + "," + r2str + ", " + branchTo->getName()
				,
				""
		);

		// footer
		mCode.writeToTextSection( "# <<<<<<<<<<<<<<< BranchEqualOp END", "" );
	}

	std::string to3AC()
	{

		return std::string("BEQUAL ") + op1->getId() + " " + op2->getId() + branchTo->getName();

	}

private:

	Label* branchTo = 0;

};

#endif /* UNCONDITIONALJUMPOP_H_ */
