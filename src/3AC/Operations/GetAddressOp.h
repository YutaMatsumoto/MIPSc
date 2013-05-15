/*
 * GetAddressOp.h
 *
 *  Created on: Apr 15, 2013
 *      Author: njordan
 */

#ifndef GETADDRESSOP_H_
#define GETADDRESSOP_H_

#include "Operation.h"

#include "BuiltinType.h"

#include <boost/format.hpp>
class GetAddressOp: public Operation {

public:

	inline GetAddressOp( Operand* destination , Operand* source ) : Operation(destination , source , 0 )
	{

	}

	virtual void produceMips()
	{

		DescriptorTable& dTable = DescriptorTable::getInstance();
		MipsCode& mCode = MipsCode::getInstance();

		mCode.writeToTextSection( "# >>>>>>>>>>>>>>> GetAddressOp Start ", "" );

		// op1->operandType // TACOperandType enum

		// ID
		unsigned int op1Id = op1->getUniqueId();
		unsigned int op2Id = op2->getUniqueId();

		// Type
		Type* typeOfOp1 = op1->getType();
		Type* typeOfOp2 = op2->getType();

		if( !typeOfOp1 )
			typeOfOp1 = new BuiltinType( Type::Int );

		if( !typeOfOp2 )
			typeOfOp2 = new BuiltinType( Type::Int );

		MipsVariable opArg1( typeOfOp1, op1Id );
		MipsVariable opArg2( typeOfOp2, op2Id );

		// reserve the memory
		mCode.writeToDataSection( opArg1, "" );
		mCode.writeToDataSection( opArg2, "" );

		RegisterInfo r1 = dTable.getRegister( opArg1 );
		RegisterInfo r2 = dTable.getRegister( opArg2   );

		//
		if ( r1.isNew() ) {
			mCode.writeToTextSection(
					"lw "+ r1.getRegister().toString()+" "+ opArg1.toDLabel().toString(),
					"Loading data for register of first argument"
			);	
		}
		if ( r2.isNew() ) {
			// TODO
			// Needs something if the address changes from MKIPS LABEL to
			// something else
		}


		// Convert Registers Obtained to Strings like "$5"
		std::string r1s = r1.getRegister().toString();

		mCode.writeToTextSection( "la "+r1s+","+opArg2.toDLabel().toString(), "" );
		mCode.writeToTextSection( "# <<<<<<<<<<<<<<< GetAddressOp END", "" );
	}

	std::string to3AC()
	{

		return ( boost::format( "%-15s%-15s%-15s" ) % std::string( "LOADADDR") % (op1->getId() + ":" + op1->getTacTypeAsString()) % (op2->getId()+ ":" + op2->getTacTypeAsString())).str();
		//return "LOADA " + op1->getId() + ":" + op1->getTacTypeAsString() + " " + op2->getId() + ":" + op2->getTacTypeAsString();

	}

};

#endif /* GETADDRESSOP_H_ */
