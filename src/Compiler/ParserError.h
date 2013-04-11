#ifndef PARSER_ERROR_H_GUARD
#define PARSER_ERROR_H_GUARD

#include <exception>

class ParserError : public std::exception {
private:
	// std::string what;
	std::string error_message;

	std::string kindToString(int errorKind)
	{
		// if (errorKind==0) {
		// 	return "NotImplemented"	:
		// }
		// else if (errorKind=Whatever) {
		// 	// return "Whatever":
		// }
		return "";
	}

public:

	enum ErrorKind {
		NotImplemented,
		SemanticError,
		Whatever
	}; 

	ParserError(int errorKind, const std::string& error_message)
		: error_message(error_message)
	{}

	virtual const char* what() const throw()
	{
		return ( std::string("ParserError: ") + error_message ).c_str();
	}
	
	// throw ParserError(ParserError::NotImplemented, "Sturuct/Union is not implemented");
};

#endif 
