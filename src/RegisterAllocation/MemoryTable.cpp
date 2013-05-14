#include "MemoryTable.h"
#include <string>
#include <iostream>
#include <sstream>
#include "MipsCode.h"
using namespace std;

// ---------------------------------------------------------------------------

MemoryTable::MemoryComponent::MemoryComponent()
	: byteSize(0)
{}

MemoryTable::MemoryComponent::MemoryComponent(size_t byteSize)
	: byteSize(byteSize)
{}

std::string MemoryTable::MemoryComponent::toString()
{
	std::ostringstream oss;
	oss
		<< "ByteSize=" << byteSize;
	return oss.str();
}


// ---------------------------------------------------------------------------

MemoryTable::MemoryTable()
	: debug(false)
{}

std::string MemoryTable::toString()
{
	using namespace std;
	std::ostringstream oss;
	typedef MTable::iterator MapIterator;
	for (MapIterator iter = table.begin(); iter != table.end(); iter++) {
		MemoryComponent mem = iter->second;
		VarId vid = iter->first;
		oss << "Key(" << vid.toString() << ")" << " --- " << "Values:(" << mem.toString() << ")" << std::endl;
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
// TODO : multiplex loading operatoin
// TODO : multiplex register expresion on float/int
//        !! RegisterNumber should be Register which can be stringified
{
	MipsCode::getInstance().writeToTextSection(
		"lw $"+ std::to_string(rNumber) +"," + vid.toString()
		, 
		" from MemoryTable::load()"
	);

	// MTable::iterator iter = table.find(vid);
	// if (iter!=table.end()) {
		debugPrint(
				"Loading vid=" + vid.toString() + 
				" register: "  + std::to_string(rNumber)
		);
	// }
}

void MemoryTable::store(RegisterNumber rNumber, VarId vid )
// TODO size is not 4 for everything
{
	MTable::iterator iter = table.find(vid);

	MemoryComponent mem( 4 );

	MipsCode::getInstance().writeToTextSection( 
		string("sw")+" "+"$"+to_string( rNumber )+","+vid.toString()
		, 
		"Super Hacksh Store inside of MemoryTable::store. Not using Type Info"
	);

	// If the variable is in the table, store it there
	if (iter!=table.end()) {
		table[vid]	= mem; 
		debugPrint(
				"Stored vid="+vid.toString() + 
				" to existing memory address : " +
				mem.toString() 
		);
	}
	
	// Else insert new element
	else {
		table.insert(std::pair<VarId,MemoryComponent>( vid, mem ));
		debugPrint(
				"Stored vid="+vid.toString() + 
				" to new memory address : " + 
				mem.toString() 
		);
	}
	
	// currentAddress += 4;
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

