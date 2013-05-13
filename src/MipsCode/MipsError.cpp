#include "MipsError.h"

MipsError::MipsError(int errorKind, const std::string& error_message)
	: error_message(error_message), errorKind(errorKind)
{}

MipsError::MipsError(const std::string& error_message)
	: error_message(error_message)
{}

const char* MipsError::what() const throw()
{
	return ( std::string("MipsError: ") + error_message ).c_str();
}
