#include "RegisterInfo.h"
#include "Register.h"
#include <sstream>


RegisterInfo::RegisterInfo(Register r, bool New)
	: r(r), New(New)
{}

bool RegisterInfo::isNew()
{ 
	return New; 
}

RegisterNumber RegisterInfo::getRegisterNumber()
{ 
	return r.getRegisterNumber(); 
} // TODO index/number

std::string RegisterInfo::toString()
{
	std::ostringstream oss;
	oss << "RegisterInfo : " 
		<< "(New=" << isNew() << ")" 
		<< " "
		<< "(regNum=" << getRegisterNumber() << ")"
		<< std::endl;
	return oss.str();
}

Register& RegisterInfo::getRegister()
{
	return r;
}
