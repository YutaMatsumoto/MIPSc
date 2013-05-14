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

RegisterInfo DescriptorTable::getRegister(MipsVariable mipsVar)
{

	MipsVariable::RegisterType rType = mipsVar.registerType();

	DLabel label = mipsVar.toDLabel();

	if (rType == MipsVariable::Float ) 
		return fTable.getRegister(label);
	else if (rType == MipsVariable::Integer ) 
		return iTable.getRegister(label);
	else {
		throw "DescriptorTable::getRegister()";
	}
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

