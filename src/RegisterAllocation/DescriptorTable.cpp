#include "DescriptorTable.h"
#include "RegisterInfo.h"
#include <iostream>
#include <string>

DescriptorTable::DescriptorTable()
	: mTable(), fTable(12,15, mTable), iTable(8, 15, mTable)
{}

RegisterInfo DescriptorTable::getFloatRegister(VarId vid)
{
	return fTable.getRegister(vid);	
}

RegisterInfo DescriptorTable::getIntegerRegister(VarId vid)
{
	return iTable.getRegister(vid);	
}

