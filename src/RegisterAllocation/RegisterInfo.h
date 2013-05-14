#ifndef REGISTER_INFO_H_GUARD
#define REGISTER_INFO_H_GUARD
#include "Register.h"

class Register;

class RegisterInfo {

public:

	RegisterInfo(Register reg, bool New);

	// TODO Make these private
	// void setNew() { New = true; }
	// void setRegisterNumber(RegisterNumber num) { regIndex = num; }
	
	// TODO rename to isNew
	bool isNew();

	RegisterNumber getRegisterNumber();

	Register& getRegister();

	std::string toString();

	Register r;
	bool New;
};


#endif
