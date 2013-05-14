#include "RegisterTable.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <boost/optional.hpp>

#include "MipsCode.h"

using namespace std;

RegisterTable::
RegisterTable(RegisterNumber start, RegisterNumber end, MemoryTable& mTable)
	: start(start), end(end), mTable(mTable), debug(false)
{
	registerUse.resize(end-start+1, false);
	varIds.resize(end-start+1, VarId() ); // TODO 
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
	MipsCode::getInstance().writeToTextSection("# Spilling Register ","");

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
	for ( int regIndex = 0 ; regIndex < (int)registerUse.size(); regIndex++ ) {
		if ( regIndex != lastSpilled1 && regIndex != lastSpilled2 ) {
			regIndexToSpill = regIndex;
			break;
		}
	}

	debugPrint("Spilling");

	VarId vid = varIds.at( regIndexToSpill );
	std::cout << "Spilling register to memory of <" + vid.toString() + ">" << std::endl;
	mTable.store( regIndexToNumber( regIndexToSpill), vid );
	// mTable.store( regIndexToNumber( regIndexToSpill), varIds.at( regIndexToSpill ) );

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

void RegisterTable::updateVarId( RegisterNumber rNum, VarId vid )
{
	assignVidToRegister(rNum, vid);
	size_t index = regNumberToIndex(rNum);
	varIds[index] = vid; // HERE 
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
		oss << "Key(" << vid.toString() << ")" << " --- " << "Values:(" << rNum << ")" << std::endl;
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

RegisterInfo RegisterTable::getRegister()
// Get register without automatic loading of vid from memory
{
	//
	// Prepare New Register
	//
	RegisterNumber rNum = getNextAvailableRegisterNumber();
	bool available = isValidRegisterNumber(rNum);
	// Open register exists. Use that register
	if (available)	{
		debugPrint(string( "getRegister : new register with open(available) register") );

		size_t regIndex = regNumberToIndex( rNum );
		registerUse[regIndex] = true;
	}
	// No open register exists. Spill
	else {
		debugPrint(string( "getRegister : new register with spilled register") );
		rNum = spill();
	}

	// -----------------------------------------------------------------------------
	//	TODO : HERE // updateVarId( rNum , vid ); // Possible BUG by hiding this function? 
	// -----------------------------------------------------------------------------

	return RegisterInfo(Register(rNum) , New);
}

RegisterInfo RegisterTable::getRegister(VarId vid)
{

	// Return the register number for the variable if it is already in a
	// register
	RegisterNumber rNum = registerNumberOf(vid);	
	if ( isValidRegisterNumber(rNum) ) {
		debugPrint(string( "getRegister : using existing register") );
		return RegisterInfo(Register(rNum), NotNew);		
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
	}
	// No open register exists. Spill
	else {
		debugPrint(string( "getRegister : new register with spilled register") );
		rNum = spill();
	}
	updateVarId( rNum , vid );

	//
	// Load from memory if the variable is in memory
	//
	// this should be taultology in our scheme
	// bool inMemory = mTable.isInMemory( vid ); 
	// if (inMemory) {
		// std::cout << "inMemory" << std::endl;
		// load from memory to available register
		// TODO unmark vid in memory ?
		// TODO loading should be done outside of RegisterTable ?
		// debugPrint(string( "getRegister : loading from memory") );
		// mTable.load(rNum, vid);
	// }

	return RegisterInfo(Register(rNum) , New);
}

