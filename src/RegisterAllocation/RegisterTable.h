#ifndef REGISTER_TABLE_H_GUARD
#define REGISTER_TABLE_H_GUARD

#include <vector>
#include <map>
#include <cstdlib>
#include <string>
#include <sstream>

#include "MemoryTable.h"
#include "RegisterAllocationCommon.h"
#include "RegisterInfo.h"

class MemoryTable;

// ---------------------------------------------------------------------------

// TODO
class Register {
	VarId id;
	bool used;	
	size_t registerIndex;

	// getRegNumber
	// getRegIndex
	// isUsed()
	// getId()
	
};

class RegisterTable {
private:

	enum { Available=0, Used=1 };
	enum { NotNew=0, New=1 };

	typedef std::map<VarId, RegisterNumber> RTable;
	RTable table;

	std::vector<bool>  registerUse; // Available or Used
	std::vector<VarId> varIds; // variable held in the register
	RegisterNumber start; // start register number
	RegisterNumber end;   // end register number

	MemoryTable& mTable;

private:

	void debugPrint(std::string msg);

	void assignVidToRegister(RegisterNumber rNumber, VarId vid);

	RegisterNumber registerNumberOf(VarId vid) const;

	bool isRegisterAvailable() const;
	
	bool isValidRegisterNumber(RegisterNumber n) const;

	RegisterNumber endRegisterNumber() const;

	RegisterNumber getNextAvailableRegisterNumber();

	RegisterNumber regIndexToNumber(size_t regIndex) const; 

	size_t regNumberToIndex(RegisterNumber reg) const;

	void setVarIdOnRegister( RegisterNumber reg, VarId vid );

	RegisterNumber spill();

public:

	RegisterTable(RegisterNumber start, RegisterNumber end, MemoryTable& mTable);

	//
	// Return register number for VarId supplied
	//
	// Spills some register if register not available
	RegisterInfo getRegister(VarId vid);
};

#endif
