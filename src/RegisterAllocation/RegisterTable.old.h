
class RegisterTable {


	// typedef std::map<VarId, MemoryAddress> MTable;

	/*
	enum RegisterAddress {
		RegisterStart = 4,
		IntegerStart = RegisterStart, 
		IntegerEnd = 25,
		FloatStart = 0, 
		FloatEnd = 0,
		RegisterEnd = 0,
	};
	*/
};


RegisterInfo RegisterTable::getRegister(VarId vid)
{

	// ... 

		/*
		if ( vid is integer) {
			availableRegNumber = spill_integer();	
			registers[availableRegNumber] = InUse;
			tablep[vid] = availableRegNumber;
		}
		else if (vid is float) {
			availableRegNumber = spill_float();	
			registers[availableRegNumber] = InUse;
			tablep[vid] = availableRegNumber;
		}
		else {
		}
		*/

}

RegisterTable::RegisterTable(RegisterNumber start, RegisterNumber end)
{
	/*
	for (size_t s = RegisterStart; s<RegisterEnd; s++) {
		if (IntegerStart <= s && s < IntegerEnd ) {
		}
		else if (FloatStart <= s && s < FloatEnd) {
		}
		else {
		}
	}
	*/
}



RegisterInfo RegisterTable::getRegister(VarId vid)
{

	// The variable is already in a register
	if ( ! rInfo.New ) {
		rInfo.regNumber = table[vid];
	}

	// The variable is NOT already in a register
	else {
	}
}

