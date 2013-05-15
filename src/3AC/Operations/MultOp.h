/*
 * MultOp.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef MULTOP_H_
#define MULTOP_H_

#include "Operation.h"
#include "MultiplicativeExpressionNode.h"

#include <boost/format.hpp>
class MultOp: public Operation {

public:

	inline MultOp( Operand* result , Operand* first , Operand* second, MultiplicativeExpressionNode::MultiplicativeExpressionType _type )
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

		mCode.writeToTextSection( "# <<<<<<<<<<<<<<< MultOp Text Start", "" );

		// op1->operandType // TACOperandType enum

		// ID
		unsigned int op1Id = op1->getUniqueId();
		unsigned int op2Id = op2->getUniqueId();
		unsigned int op3Id = op3->getUniqueId();

		// Type
		Type* typeOfOp1 = op1->getType();
		Type* typeOfOp2 = op2->getType();
		Type* typeOfOp3 = op3->getType();

		if( !typeOfOp1 )
			typeOfOp1 = new BuiltinType( Type::Int );

		if( !typeOfOp2 )
			typeOfOp2 = new BuiltinType( Type::Int );

		if( !typeOfOp3 )
			typeOfOp3 = new BuiltinType( Type::Int );

		// ID and Type
		MipsVariable opResult( typeOfOp1, op1Id );
		MipsVariable opArg2( typeOfOp2, op2Id );
		MipsVariable opArg3( typeOfOp3, op3Id );

		// reserve the memory
		mCode.writeToDataSection( opResult, "AddResult" );
		mCode.writeToDataSection( opArg2, "AddArgument1" );
		mCode.writeToDataSection( opArg3, "AddArgument2" );

		// 
		// Get the registers for these guys	
		//
		// ???????????????????????????????????????????????????????????????????? 
		// should getRegister() automatically load the register the opResult/opArg2/opArg3 lable 
		// ???????????????????????????????????????????????????????????????????? 
		// RegisterInfo r1 = dTable.getRegister( opResult, false );  // r1=Result so no need to load opResult before the operation(addition)
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

		int typeEnumOfOp1 = typeOfOp1->getType();

		// Do not allow casting
		// if (typeEnumOfOp1 != typeEnumOfOp2 ) {
		// 	throw "MultOp : Type Mismatch";	
		// }

		//
		// mips operation
		//
		std::string mipsOperation;

		// Addition
		if ( type == MultiplicativeExpressionNode::Multiply) {
			switch (typeEnumOfOp1) {
				case Type::uChar:
					throw "Multiop : this type not implemented ";
					break;
				case Type::uShort:
					throw "Multiop : this type not implemented ";
					break;
				case Type::uInt:
					throw "Multiop : this type not implemented ";
					break;
				case Type::uLong:
					throw "Multiop : this type not implemented ";
					break;
				case Type::uLongLong:
					throw "Multiop : this type not implemented ";
					break;
				case Type::Char:
					throw "Multiop : this type not implemented ";
					break;
				case Type::Short:
					throw "Multiop : this type not implemented ";
					break;
				case Type::Int:
					mipsOperation="mul";
					break;
				case Type::Long:
					throw "Multiop : this type not implemented ";
					break;
				case Type::LongLong:
					throw "Multiop : this type not implemented ";
					break;
				case Type::Float:
					mipsOperation="mul.s";
					break;
				case Type::Double:
					mipsOperation="mul.d";
					break;
			}

		// Subtraction
		} else if ( type == MultiplicativeExpressionNode::Divide ) {
			switch (typeEnumOfOp1) {
				case Type::uChar:
					throw "Multiop : this type not implemented ";
					break;
				case Type::uShort:
					throw "Multiop : this type not implemented ";
					break;
				case Type::uInt:
					throw "Multiop : this type not implemented ";
					break;
				case Type::uLong:
					throw "Multiop : this type not implemented ";
					break;
				case Type::uLongLong:
					throw "Multiop : this type not implemented ";
					break;
				case Type::Char:
					throw "Multiop : this type not implemented ";
					break;
				case Type::Short:
					throw "Multiop : this type not implemented ";
					break;
				case Type::Int:
					mipsOperation="div";
					break;
				case Type::Long:
					throw "Multiop : this type not implemented ";
					break;
				case Type::LongLong:
					throw "Multiop : this type not implemented ";
					break;
				case Type::Float:
					mipsOperation="div.s";
					break;
				case Type::Double:
					mipsOperation="div.d";
					break;
			}
		}
		else {
			throw "MultiOp";
		}

		// Convert Registers Obtained to Strings like "$5"
		std::string r1str = r1.getRegister().toString();
		std::string r2str = r2.getRegister().toString();
		std::string r3str = r3.getRegister().toString();

		mCode.writeToTextSection( 
				mipsOperation + " " + r1str + "," + r2str + "," + r3str, 
				"MultOp " 
		);
		dTable.store(r1.getRegister(), opResult, " MultOp: loading result to memory");

		mCode.writeToTextSection( "# >>>>>>>>>>>>>>> MultOp ", "" );
	}

	std::string to3AC()
	{

		if( type == MultiplicativeExpressionNode::Multiply )

			return ( boost::format( "%-15s%-15s%-15s%-15s" ) % std::string( "MUL ") % (op1->getId() + ":" + op1->getTacTypeAsString()) % (op2->getId()+ ":" + op2->getTacTypeAsString()) % (op3->getId()+ ":" + op3->getTacTypeAsString())).str();
			//return std::string("MULT ") + op1->getId()+ ":" + op1->getTacTypeAsString() + " " + op2->getId()+ ":" + op2->getTacTypeAsString() + " " + op3->getId()+ ":" + op3->getTacTypeAsString();

		if( type == MultiplicativeExpressionNode::Divide )

			return ( boost::format( "%-15s%-15s%-15s%-15s" ) % std::string( "DIV ") % (op1->getId() + ":" + op1->getTacTypeAsString()) % (op2->getId()+ ":" + op2->getTacTypeAsString()) % (op3->getId()+ ":" + op3->getTacTypeAsString())).str();
			//return std::string("MULT ") + op1->getId()+ ":" + op1->getTacTypeAsString() + " " + op2->getId()+ ":" + op2->getTacTypeAsString() + " " + op3->getId()+ ":" + op3->getTacTypeAsString();

		//else

			//return std::string("MULT ") + op1->getId()+ ":" + op1->getTacTypeAsString() + " " + op2->getId()+ ":" + op2->getTacTypeAsString() + " " + op3->getId()+ ":" + op3->getTacTypeAsString();

	}

	MultiplicativeExpressionNode::MultiplicativeExpressionType type;

};

#endif /* MULTOP_H_ */
