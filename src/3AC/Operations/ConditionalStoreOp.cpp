#include "ConditionalStoreOp.h"


	void ConditionalStoreOp::produceMips()
	{

		// SLT -- Set on less than (signed)
		// if $s < $t $d = 1; advance_pc (4); else $d = 0; advance_pc (4); 	
		// slt $d, $s, $t 

		// TODO 
		// Move code commont to all the operations or some of the operations of
		// the same type to the parent class or some other method
		//

		DescriptorTable& dTable = DescriptorTable::getInstance();
		MipsCode& mCode = MipsCode::getInstance();

		mCode.writeToTextSection( "# >>>>>>>>>>>>>>> ConditionalStore Start ", "" );

		// op1->operandType // TACOperandType enum

		// ID
		unsigned int op1Id = op1->getUniqueId();
		unsigned int op2Id = op2->getUniqueId();
		unsigned int op3Id = op3->getUniqueId();

		// Type
		Type* typeOfOp1 = op1->getType();
		Type* typeOfOp2 = op2->getType();
		Type* typeOfOp3 = op3->getType();

		// ID and Type
		MipsVariable opResult( typeOfOp1, op1Id );
		MipsVariable opArg2( typeOfOp2, op2Id );
		MipsVariable opArg3( typeOfOp3, op3Id );

		// reserve the memory
		mCode.writeToDataSection( opResult, "" );
		mCode.writeToDataSection( opArg2, "" );
		mCode.writeToDataSection( opArg3, "" );

		// 
		// Get the registers for these guys	
		//
		// ???????????????????????????????????????????????????????????????????? 
		// should getRegister() automatically load the register the opResult/opArg2/opArg3 lable 
		// ???????????????????????????????????????????????????????????????????? 
		// registerInfo r1 = dTable.getRegister( opResult, false );  // r1=Result so no need to load opResult before the operation(addition)
		RegisterInfo r1 = dTable.getRegister( opResult );
		RegisterInfo r2 = dTable.getRegister( opArg2   );
		RegisterInfo r3 = dTable.getRegister( opArg3   );

		// ???????????????????????????????????????????????????????????????????
		//
		// If new registers, need to load from the static global memory
		//
		// Should be done here or inside of getRegister ?
		//
		if ( r1.isNew() ) {
		}
		if ( r2.isNew() ) {
			mCode.writeToTextSection(
					"lw "+ r2.getRegister().toString()+","+ opArg2.toDLabel().toString(),
					"Loading data for register of first argument"
			);	
		}
		if ( r3.isNew() ) {
			mCode.writeToTextSection(
					"lw "+ r3.getRegister().toString()+","+ opArg3.toDLabel().toString(), 
					"Loading data for register of second argument"
			);	
		}

		//
		// mips operation
		//

		// Convert Registers Obtained to Strings like "$5"
		std::string r1str = r1.getRegister().toString();
		std::string r2str = r2.getRegister().toString();
		std::string r3str = r3.getRegister().toString();

		std::string r1s = r1.getRegister().toString();
		std::string r2s = r2.getRegister().toString();
		std::string r3s = r3.getRegister().toString();

		// let a = r2, b = r3

		std::string mipsStatement;
		switch(type)
		{
		case RelationalExpressionNode::Greater:
			mipsStatement = "sgt " + r1s + "," + r2s + "," + r3s;
			break;
		case RelationalExpressionNode::Less:
			mipsStatement = "slt " + r1s + "," + r2s + "," + r3s;
			break;
		case RelationalExpressionNode::GreaterEqual:
			mipsStatement = "sge " + r1s + "," + r2s + "," + r3s;
			break;
		case RelationalExpressionNode::LessEqual:
			mipsStatement = "sle " + r1s + "," + r2s + "," + r3s;
			break;
		}
		
		mCode.writeToTextSection( mipsStatement, "" );
		mCode.writeToTextSection( "# <<<<<<<<<<<<<<< ConditionalStore END", "" );
	}
