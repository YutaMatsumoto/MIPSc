#ifndef MIPS_ERROR_H_GUARD
#define MIPS_ERROR_H_GUARD

#include <exception>
#include <string>

class MipsConversionError : public std::exception {
	std::string error_message;
	int errorKind;
public:

	enum ErrorKind {
		NotImplemented
	}; 

	MipsConversionError(int errorKind, const std::string& error_message);

	MipsConversionError(const std::string& error_message);

	virtual const char* what() const throw();
};

#endif 
