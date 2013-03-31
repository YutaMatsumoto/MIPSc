/*
 * Type.cpp
 *
 *  Created on: Mar 13, 2013
 *      Author: njordan
 */

#include "Type.h"

// Type::Type( std::string id , int lineNumber , int columnNumber ) {

	// this->id = id;

	// this->lineNumber = lineNumber;

	// this->columnNumber = columnNumber;

// }

std::string Type::getId()
{

	return id;

}

// Type::Type() {
// }

Type::Type(TypeEnum type)
	: type(type)
{}

Type::~Type() {
	// TODO Auto-generated destructor stub
}

