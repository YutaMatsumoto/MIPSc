/*
 * LoadOp.h
 *
 *  Created on: Apr 15, 2013
 *      Author: njordan
 */

#ifndef LOADOP_H_
#define LOADOP_H_

#include <string>
#include "Operation.h"

#include "BuiltinType.h"

#include <boost/format.hpp>
class LoadOp: public Operation {

public:

	inline LoadOp( Operand* destination , Operand* source ) : Operation(destination , source , 0 )
	{

	}

	virtual void produceMips()
	{

		MipsCode& mCode = MipsCode::getInstance();
		DescriptorTable& dTable = DescriptorTable::getInstance();

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

		std::string labelName = op2->getId();

		// std::cout << "type->getType()==" << labelName << std::endl;
		// if (labelName=="") {
		// 	std::cout << "ERROR in produceMips() in LoadOp.h" << std::endl;
		// 	exit(1);
		// }

		// ID and Type
		MipsVariable opArg1( typeOfOp1, op1Id );
		MipsVariable opArg2( labelName, typeOfOp1, op1Id );

		// reserve the memory
		mCode.writeToDataSection( opArg1, "" );
		mCode.writeToDataSection( opArg2, "" );

		// Register
		RegisterInfo r1 = dTable.getRegister( opArg1 );
		RegisterInfo r2 = dTable.getRegister( opArg2 );

		/*
		if ( r1.isNew() ) {
			mCode.writeToTextSection(
					"lw "+ r1.getRegister().toString()+","+ opArg1.toDLabel().toString(),
					"Loading data for register of first argument"
			);	
		}
		if ( r2.isNew() ) {
			mCode.writeToTextSection(
					"lw "+ r2.getRegister().toString()+","+ opArg2.toDLabel().toString(),
					"Loading data for register of first argument"
			);	
		}
		*/


		std::string addressOfSeond = opArg1.toDLabel().toString();

		std::string r1s = r1.getRegister().toString();
		std::string r2s = r2.getRegister().toString();

		// Load address of whatever the second argument is
		mCode.writeToTextSection(
			"la "+ r2s +","+labelName, 
			""
		);	

		// Load contents of the address r2 holds to r1
		mCode.writeToTextSection(
				"lw "+ r1s +",("+r2s+")",
				""
		);	

	}

	std::string to3AC()
	{

		return ( boost::format( "%-15s%-15s%-15s" ) % std::string( "LOAD") % (op1->getId() + ":" + op1->getTacTypeAsString()) % (op2->getId()+ ":" + op2->getTacTypeAsString())).str();
		//turn "LOAD " + op1->getId() + ":" + op1->getTacTypeAsString() + " @" + op2->getId() + ":" + op2->getTacTypeAsString();

	}


};

#endif /* LOADOP_H_ */
