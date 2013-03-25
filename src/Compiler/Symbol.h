/*
 * Symbol.h
 *
 *  Created on: Mar 13, 2013
 *      Author: njordan
 */

#ifndef SYMBOL_H_
#define SYMBOL_H_

#include <string>
#include "Type.h"

class Symbol
{

public:

	//symbol constructor
	Symbol( std::string , int , int );

	std::string getId();

	virtual ~Symbol();

protected:

	std::string id;

	int lineNumber;

	int columnNumber;
	
	Type* symbolType;

};

#endif /* SYMBOL_H_ */
