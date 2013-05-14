#include "Register.h"
#include "RegisterAllocationCommon.h"

Register::Register(RegisterNumber rNumber)
	: rNumber(rNumber)
{}

RegisterNumber Register::getRegisterNumber() const
{
	return rNumber;
}

std::string Register::toString() const
{
	return std::string( prefix() + std::to_string( rNumber ) );
}

std::string Register::prefix() const
{
	return "$";
}

// ---------------------------------------------------------------------------

std::string FloatRegister::toString() const
{
	return std::string( Register::prefix() + "f"+ std::to_string( getRegisterNumber() ) ) ;
}

