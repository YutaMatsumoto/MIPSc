#include "MemoryTable.h"
#include <string>
#include <iostream>

MemoryTable::MemoryTable()
	: currentAddress(0), debug(false)
{}

bool MemoryTable::isInMemory(VarId vid)
{
	MTable::iterator iter = table.find(vid);
	return ( iter != table.end() );
}

void MemoryTable::load(RegisterNumber rNumber, VarId vid )
{
	MTable::iterator iter = table.find(vid);
}

void MemoryTable::setDebug()
{
	debug = true;
}

void MemoryTable::debugPrint(std::string msg)
{
	if (debug)
	std::cout << "MemoryTable : " << msg << std::endl;
}

void MemoryTable::store(/*RegisterNumber rNumber,*/ VarId vid )
// TODO size is not 4 for everything
{
	MTable::iterator iter = table.find(vid);

	// If the variable is in the table, store it there
	if (iter!=table.end()) {
		table[vid]	= MemoryComponent(currentAddress, 4); 
		debugPrint("Stored vid="+std::to_string(vid) + " to existing memory address");
	}
	
	// Else insert new element
	else {
		table.insert(std::pair<VarId,MemoryComponent>( vid, MemoryComponent(currentAddress, 4 ) ));
		debugPrint("Stored vid="+std::to_string(vid) + " to new memory address");
	}
	
	currentAddress += 4;
}
