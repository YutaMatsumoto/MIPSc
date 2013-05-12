#ifndef REGISTER_INFO_H_GUARD
#define REGISTER_INFO_H_GUARD

class RegisterInfo {

public:

	RegisterInfo(RegisterNumber regIndex, bool New)
		: regIndex(regIndex), New(New)
	{}

	void setNew() { New = true; }
	void setRegisterNumber(RegisterNumber num) { regIndex = num; }
	bool getNew() { return New; }
	RegisterNumber getRegisterNumber () { return regIndex; } // TODO index/number

	std::string toString()
	{
		std::ostringstream oss;
		oss << "RegisterInfo : " 
			<< "(New=" << getNew() << ")" 
			<< " "
			<< "(regNum=" << getRegisterNumber() << ")"
			<< std::endl;
		return oss.str();
	}

	RegisterNumber regIndex; // TODO Index BUG ?
	bool New;
};


#endif
