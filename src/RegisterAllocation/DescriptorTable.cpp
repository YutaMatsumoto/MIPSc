#include "DescriptorTable.h"
#include "RegisterInfo.h"
#include "RegisterAllocationCommon.h"
#include "Register.h"
#include "MipsVariable.h"
#include "MipsCode.h"
#include <iostream>
#include <string>

DescriptorTable::DescriptorTable()
	: mTable(), fTable(12,15, mTable), iTable(8, 15, mTable)
{}

class Register;

DescriptorTable& DescriptorTable::getInstance()
{
	static DescriptorTable instance;
	return instance;
}

void DescriptorTable::load(Register r, MipsVariable mipsVar, MipsComment com)
// TODO : multiplex load operation
{
	MipsCode& mCode = MipsCode::getInstance(); 
	mCode.writeToTextSection( "lw " + r.toString() + "," + mipsVar.toDLabel().toString() );
	throw "Descripter::load() : incomplete";
}

void DescriptorTable::store(Register r, MipsVariable mipsVar, MipsComment com)
// TODO : multiplex store operation on type (making map from type to store opration)
{
	MipsCode& mCode = MipsCode::getInstance(); 
	mCode.writeToTextSection( 
		"sw " + r.toString() + "," + mipsVar.toDLabel().toString(),
		com
	);
}

RegisterInfo DescriptorTable::getRegister(MipsVariable mipsVar, bool Deep)
{

	MipsVariable::RegisterType rType = mipsVar.registerType();

	DLabel label = mipsVar.toDLabel();

	// Load vid 
	if ( Deep ) {
		if (rType == MipsVariable::Float ) 
			return fTable.getRegister(label);
		else if (rType == MipsVariable::Integer ) 
			return iTable.getRegister(label);
		else {
			throw "DescriptorTable::getRegister()";
		}
	}

	// Do not load vid
	else {
		if (rType == MipsVariable::Float ) 
			return fTable.getRegister();
		else if (rType == MipsVariable::Integer ) 
			return iTable.getRegister();
		else {
			throw "DescriptorTable::getRegister()";
		}
	}

}	

void DescriptorTable::setDebug()
{
	fTable.setDebug();
	iTable.setDebug();
}

/*
RegisterInfo DescriptorTable::getFloatRegister(VarId vid)
{
	return fTable.getRegister("f"+vid.toString());
}

RegisterInfo DescriptorTable::getIntegerRegister(VarId vid)
{
	return iTable.getRegister("i"+vid.toString());
}
*/

