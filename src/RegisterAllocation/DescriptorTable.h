#ifndef DESCRIPTOR_H_GUARD
#define DESCRIPTOR_H_GUARD

#include "RegisterTable.h"
#include "MemoryTable.h"
#include "MipsVariable.h"

#include <string>

class DescriptorTable
{
private:
	MemoryTable   mTable;	
	RegisterTable fTable;
	RegisterTable iTable;

public:
	
	void setDebug();

	// Does not load vid
	RegisterInfo getRegister(MipsVariable mipsVar, bool Deep=1);

	// TODO : imcomplete
	void load(Register r, MipsVariable mipsVar, MipsComment com=std::string(""));

	void store(Register r, MipsVariable mipsVar, MipsComment com=std::string(""));

	static DescriptorTable& getInstance();

private:
	DescriptorTable();
	DescriptorTable(DescriptorTable const&);
	void operator=(DescriptorTable const&);
 };

#endif
