#include "AssignOp.h"


void AssignOp::produceMips()
	{

		DescriptorTable& dTable = DescriptorTable::getInstance();
		MipsCode& mCode = MipsCode::getInstance();

		// Header
		mCode.writeToTextSection( "# >>>>>>>>>>>>>>> AssignOp/LoadImmediate Text Start", "" );

		// op1->operandType // TACOperandType enum

		// ID
		unsigned int op1Id = op1->getUniqueId();

		// Type
		Type* typeOfOp1 = op1->getType();

		if(!typeOfOp1)

			typeOfOp1 = new BuiltinType( Type::Int );

		// ID and Type
		MipsVariable opResult( typeOfOp1, op1Id );

		// reserve the memory
		mCode.writeToDataSection( opResult, "" );

		// immediate value in string as it is
		std::string immediateValue = op2->getId();

		// Get Registers
		RegisterInfo r1 = dTable.getRegister( opResult );

		// Load 
		if ( r1.isNew() ) {
			mCode.writeToTextSection(
					"li "+ r1.getRegister().toString()+","+ immediateValue,
					"Loading data for register of first argument"
			);	
		}
     	
		// footer
		mCode.writeToTextSection( "# <<<<<<<<<<<<<<< AssignOpc", "" );
	}
