/*
 * AssignOp.h
 *
 *  Created on: Apr 15, 2013
 *      Author: njordan
 */

#ifndef ASSIGNOP_H_
#define ASSIGNOP_H_

#include "Operation.h"

#include <boost/format.hpp>
#include "AssignmentOperatorNode.h"

class AssignOp: public Operation {

public:

	inline AssignOp( Operand* destination , Operand* source , AssignmentOperatorNode::AssignmentOperatorType _type ) : Operation(destination , source , 0 ), type( _type )
	{

	}

	virtual void produceMips()
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
					"li "+ r1.getRegister().toString()+" "+ immediateValue,
					"Loading data for register of first argument"
			);	
		}
     	
		// footer
		mCode.writeToTextSection( "<<<<<<<<<<<<<<< assignop/loadimmediate text end", "" );
	}

	std::string to3AC()
	{

		return ( boost::format( "%-15s%-15s%-15s" ) % std::string( "LOADI ") % (op1->getId() + ":" + op1->getTacTypeAsString()) % (op2->getId()+ ":" + op2->getTacTypeAsString())).str();
		//return "LOADI " + op1->getId() + ":" + op1->getTacTypeAsString() + " " + op2->getId() + ":" + op2->getTacTypeAsString();

	}

	AssignmentOperatorNode::AssignmentOperatorType type;

};

#endif /* ASSIGNOP_H_ */
