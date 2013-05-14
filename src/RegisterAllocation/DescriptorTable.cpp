#include "DescriptorTable.h"
#include "RegisterInfo.h"
#include "RegisterAllocationCommon.h"
#include "Register.h"
#include "MipsVariable.h"
#include <iostream>
#include <string>

DescriptorTable::DescriptorTable()
	: mTable(), fTable(12,15, mTable), iTable(8, 15, mTable)
{}

class Register;

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

