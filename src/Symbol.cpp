/*
 * Symbol.cpp
 *
 *  Created on: Mar 13, 2013
 *      Author: njordan
 */

#include "Symbol.h"

Symbol::Symbol( std::string id , int lineNumber , int columnNumber ) {

	this->id = id;

	this->lineNumber = lineNumber;

	this->columnNumber = columnNumber;

}

std::string Symbol::getId()
{
	return id;
}

Symbol::~Symbol() {
	// TODO Auto-generated destructor stub
}

