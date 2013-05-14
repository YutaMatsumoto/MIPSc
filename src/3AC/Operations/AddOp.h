/*
 * Add.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef ADDOP_H_
#define ADDOP_H_

#include "Operation.h"

#include "AdditiveExpressionNode.h"

#include "MipsVariable.h"
#include "MipsCode.h"
#include "DescriptorTable.h"

class AddOp: public Operation {

public:

	inline AddOp( Operand* result , Operand* first , Operand* second , AdditiveExpressionNode::AdditiveExpressionType _type )
		: Operation( result, first, second ), type(_type)
	{

	}

	virtual void produceMips()
	{
	// TODO 
	// Move code commont to all the operations or some of the operations of
	// the same type to the parent class or some other method
	//

		DescriptorTable& dTable = DescriptorTable::getInstance();
		MipsCode& mCode = MipsCode::getInstance();

		// op1->operandType // TACOperandType enum

		// ID
		unsigned int op1Id = op1->getId();
		unsigned int op2Id = op2->getId();
		unsigned int op3Id = op3->getId();

		// Type
		Type* typeOfOp1 = op1->getType();
		Type* typeOfOp2 = op2->getType();
		Type* typeOfOp3 = op3->getType();

		// ID and Type
		MipsVariable m1( typeOfOp1, op1Id );
		MipsVariable m2( typeOfOp2, op2Id );
		MipsVariable m3( typeOfOp3, op3Id );

		// reserve the memory
		mCode.writeToDataSection( m1, "comment" );
		mCode.writeToDataSection( m2, "comment" );
		mCode.writeToDataSection( m3, "comment" );

		// 
		// Get the registers for these guys	
		//
		// ???????????????????????????????????????????????????????????????????? 
		// should getRegister() automatically load the register the m1/m2/m3 lable 
		// ???????????????????????????????????????????????????????????????????? 
		RegisterInfo r1 = dTable.getRegister( m1 );
		RegisterInfo r2 = dTable.getRegister( m2 );
		RegisterInfo r3 = dTable.getRegister( m3 );

		// ???????????????????????????????????????????????????????????????????
		//
		// If new registers, need to load from the static global memory
		//
		// Should be done here or inside of getRegister ?
		//
		if ( r1.isNew() ) {
		}
		if ( r2.isNew() ) {
		}
		if ( r3.isNew() ) {
		}

		int typeEnumOfOp1 = typeOfOp1->getType();
	
		// Do not allow casting
		// if (typeEnumOfOp1 != typeEnumOfOp2 ) {
		// 	throw "AddOp : Type Mismatch";	
		// }

		//
		// mips operation
		//
		std::string mipsOperation;
		switch (typeEnumOfOp1) {
			case Type::uChar:
				break;
			case Type::uShort:
				break;
			case Type::uInt:
				break;
			case Type::uLong:
				break;
			case Type::uLongLong:
				break;
			case Type::Char:
				break;
			case Type::Short:
				break;
			case Type::Int:
				mipsOperation="add";
				break;
			case Type::Long:
				break;
			case Type::LongLong:
				break;
			case Type::Float:
				mipsOperation="add.s";
				break;
			case Type::Double:
				mipsOperation="add.d";
				break;
		}

		// Convert Registers Obtained to String like "$5"
		std::string r1str = r1.getRegister().toString();
		std::string r2str = r2.getRegister().toString();
		std::string r3str = r3.getRegister().toString();

		mCode.writeToTextSection( mipsOperation + " " + r1str + "," + r2str + "," + r3str, "comment" );
	}

	std::string to3AC()
	{

		if( type == AdditiveExpressionNode::Add )

			return "ADD " + op1->getId() + " " + op2->getId() + " " + op3->getId();

		else

			return "SUB " + op1->getId() + " " + op2->getId() + " " + op3->getId();

	}

	AdditiveExpressionNode::AdditiveExpressionType type;

};

#endif /* ADDOP_H_ */
