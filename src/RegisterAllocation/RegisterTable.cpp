#include "RegisterTable.h"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

RegisterTable::
RegisterTable(RegisterNumber start, RegisterNumber end, MemoryTable& mTable)
	: start(start), end(end), mTable(mTable), debug(false)
{
	registerUse.resize(end-start+1, false);
	varIds.resize(end-start+1, 0); // TODO 
}

RegisterNumber RegisterTable::registerNumberOf(VarId vid) const
{
	RTable::const_iterator iter = table.find(vid);
	bool inRegister = ( iter != table.end() );
	return ( inRegister )  
		? iter->second
		: end+1
		;
}

bool RegisterTable::isRegisterAvailable() const
{
	for (size_t regIndex = 0; regIndex < registerUse.size(); regIndex++) {
		if ( ! registerUse[regIndex] ) {
			return true;
		}
	}
	return false;
}

RegisterNumber RegisterTable::regIndexToNumber(size_t regIndex) const
{
	return regIndex+start;
}

RegisterNumber RegisterTable::getNextAvailableRegisterNumber()
// Return next available register number.
// If no register is available, the invalid register number is returned (end+1)
{
	for (size_t regIndex = 0; regIndex < registerUse.size(); regIndex++) {
		bool available = ! registerUse[ regIndex ];
		if ( available )
			return regIndexToNumber( regIndex );
	}
	return end+1;
}

RegisterNumber RegisterTable::endRegisterNumber() const
{
	return end+1;
}

RegisterNumber RegisterTable::spill()
{

	// in the context of op3 = op1 + op2, when spilling for op3, 
	// do not spill register for op1 or op2 

	// TODO roundrobin instead of using last two

	static RegisterNumber
		lastSpilled1 = endRegisterNumber(),
		lastSpilled2 = endRegisterNumber()
		;

	// Determine the register to spill
	// TODO : if the number of registers is less than 3, this fails
	RegisterNumber regIndexToSpill = registerUse.size();
	for ( size_t regIndex = 0 ; regIndex < registerUse.size(); regIndex++ ) {
		if ( regIndex != lastSpilled1 && regIndex != lastSpilled2 ) {
			regIndexToSpill = regIndex;
		}
	}

	mTable.store( varIds.at( regIndexToSpill ) );

	// Bookkeep the last two spilled registers
	if      ( lastSpilled1 == endRegisterNumber() && lastSpilled2 == endRegisterNumber() ) {
		lastSpilled1 = regIndexToSpill;	
	}
	else if ( lastSpilled1 != endRegisterNumber() && lastSpilled2 == endRegisterNumber() ) {
		lastSpilled2 = regIndexToSpill;
	}
	else if ( lastSpilled1 != endRegisterNumber() && lastSpilled2 != endRegisterNumber() ) {
		lastSpilled1 = lastSpilled2;
		lastSpilled2 = regIndexToSpill;
	}

	// Erase vid of the spilled register from the table
	table.erase( varIds[regIndexToSpill] );	
		

	return regIndexToNumber( regIndexToSpill );
}

bool RegisterTable::isValidRegisterNumber(RegisterNumber n) const
{
	return ( start <= n && n <= end);
}

size_t RegisterTable::regNumberToIndex(RegisterNumber reg) const
{
	return reg - start;	
}

void RegisterTable::setVarIdOnRegister( RegisterNumber reg, VarId vid )
{
	size_t index = regNumberToIndex(reg);
	varIds[index] = vid;
}

void RegisterTable::debugPrint(std::string msg)
{
	if (debug)
		std::cout << "RegisterTable : " << msg << std::endl;
}

void RegisterTable::setDebug()
{
	debug = true;
}

std::string RegisterTable::toString()
{
	using namespace std;
	std::ostringstream oss;
	typedef RTable::iterator MapIterator;
	for (MapIterator iter = table.begin(); iter != table.end(); iter++) {
		VarId vid = iter->first;
		RegisterNumber rNum = iter->second;
		oss << "Key(" << vid << ")" << " --- " << "Values:(" << rNum << ")" << std::endl;
	}
	return oss.str();
}



void RegisterTable::assignVidToRegister(RegisterNumber rNumber, VarId vid)
{

	RTable::iterator iter = table.find(vid);

	// If the variable is in the table, store it there
	if (iter!=table.end())
		table[vid]	= rNumber;

	// Else insert new element
	else
		table.insert(std::pair<VarId,RegisterNumber>( vid, rNumber ));
	
}

RegisterInfo RegisterTable::getRegister(VarId vid)
{

	// Return the register number for the variable if it is already in a
	// register
	RegisterNumber rNum = registerNumberOf(vid);	
	if ( isValidRegisterNumber(rNum) ) {
		debugPrint(string( "getRegister : using existing register") );
		return RegisterInfo(rNum, NotNew);		
	}

	//
	// Prepare New Register
	//
	rNum = getNextAvailableRegisterNumber();
	bool available = isValidRegisterNumber(rNum);
	// Open register exists. Use that register
	if (available)	{
		debugPrint(string( "getRegister : new register with open(available) register") );

		size_t regIndex = regNumberToIndex( rNum );
		registerUse[regIndex] = true;
		assignVidToRegister(rNum, vid);
	}
	// No open register exists. Spill
	else {
		debugPrint(string( "getRegister : new register with spilled register") );
		rNum = spill();
		assignVidToRegister(rNum, vid);
	}
	setVarIdOnRegister( rNum , vid );

	//
	// Load from memory if the variable is in memory
	//
	bool inMemory = mTable.isInMemory( vid );
	if (inMemory) {
		// load from memory to available register
		// TODO unmark vid in memory ?
		mTable.load(rNum, vid);
		debugPrint(string( "getRegister : loading from memory") );
	}

	return RegisterInfo(rNum , New);
}

