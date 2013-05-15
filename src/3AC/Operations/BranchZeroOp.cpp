#include "BranchZeroOp.h"
void BranchZeroOp::produceMips()
	{
		
		DescriptorTable& dtable = DescriptorTable::getInstance();
		MipsCode& mCode = MipsCode::getInstance();

		mCode.writeToTextSection( "# >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> BranchZero Start", "" );

		// beq $s, $t, offset 
		//

		unsigned int op1Id = op1->getUniqueId();

		// Type
		Type* typeOfOp1 = op1->getType();

		// ID and Type
		MipsVariable opResult( typeOfOp1, op1Id );

		// reserve the memory
		// TODO need to ?
		mCode.writeToDataSection( opResult, "" );

		RegisterInfo r1 = dtable.getRegister( opResult );
		/*
		if ( r1.isNew() ) {
			mCode.writeToTextSection(
					"lw "+ r1.getRegister().toString()+" "+ opResult.toDLabel().toString(),
					""
			);	
		}
		*/


		// Convert Registers Obtained to Strings like "$5"
		std::string r1str = r1.getRegister().toString();
		// std::string r2str = r2.getRegister().toString();

		MipsCode::getInstance().writeToTextSection(
				"beqz " + r1str + ", " + branchTo->getName(),
				""
		);

		// footer
  		mCode.writeToTextSection( "# <<<<<<<<<<<<<<<<<<<<<<<<<<<<<< BranchEqualOp END", "" );
	}
