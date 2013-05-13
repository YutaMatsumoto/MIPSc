#include "MemoryTable.h"
#include <string>
#include <iostream>
#include <sstream>

// ---------------------------------------------------------------------------

MemoryTable::MemoryComponent::MemoryComponent()
	: id(0), byteSize(0)
{}

MemoryTable::MemoryComponent::MemoryComponent(MemoryId id, size_t byteSize)
	: id(id), byteSize(byteSize)
{}

std::string MemoryTable::MemoryComponent::toString()
{
	std::ostringstream oss;
	oss
		<< "MemoryAddress=" << id
		<< " "
		<< "ByteSize=" << byteSize;
	return oss.str();
}


// ---------------------------------------------------------------------------

MemoryTable::MemoryTable()
	: currentAddress(0), debug(false)
{}

std::string MemoryTable::toString()
{
	using namespace std;
	std::ostringstream oss;
	typedef MTable::iterator MapIterator;
	for (MapIterator iter = table.begin(); iter != table.end(); iter++) {
		MemoryComponent mem = iter->second;
		VarId vid = iter->first;
		oss << "Key(" << vid << ")" << " --- " << "Values:(" << mem.toString() << ")" << std::endl;
	}
	return oss.str();
}

bool MemoryTable::isInMemory(VarId vid)
{
	MTable::iterator iter = table.find(vid);
	// std::cout << " isInMemory function " << std::endl;
	// std::cout << toString() << std::endl;
	return ( iter != table.end() );
}

void MemoryTable::load(RegisterNumber rNumber, VarId vid )
{
	// MTable::iterator iter = table.find(vid);
	// if (iter!=table.end()) {
		debugPrint(
				"Loading vid=" + std::to_string(vid) + 
				" register: "  + std::to_string(rNumber)
		);
	// }
}

void MemoryTable::store(/*RegisterNumber rNumber,*/ VarId vid )
// TODO size is not 4 for everything
{
	MTable::iterator iter = table.find(vid);

	MemoryComponent mem(currentAddress, 4 );

	// If the variable is in the table, store it there
	if (iter!=table.end()) {
		table[vid]	= mem; 
		debugPrint(
				"Stored vid="+std::to_string(vid) + 
				" to existing memory address : " +
				mem.toString() 
		);
	}
	
	// Else insert new element
	else {
		table.insert(std::pair<VarId,MemoryComponent>( vid, mem ));
		debugPrint(
				"Stored vid="+std::to_string(vid) + 
				" to new memory address : " + 
				mem.toString() 
		);
	}
	
	currentAddress += 4;
}


// ---------------------------------------------------------------------------
// Debugging

void MemoryTable::setDebug()
{
	debug = true;
}

void MemoryTable::debugPrint(std::string msg)
{
	if (debug)
	std::cout << "MemoryTable : " << msg << std::endl;
}

