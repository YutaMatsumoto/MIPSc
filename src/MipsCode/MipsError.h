#ifndef MIPS_ERROR_H_GUARD
#define MIPS_ERROR_H_GUARD

#include <exception>
#include <string>

class MipsError : public std::exception {
	std::string error_message;
	int errorKind;
public:

	enum ErrorKind {
		NotImplemented,
		Whatever
	}; 

	MipsError(int errorKind, const std::string& error_message);

	MipsError(const std::string& error_message);

	virtual const char* what() const throw();
};

#endif 
