/*
 * ArrayType.cpp
 *
 *  Created on: Mar 29, 2013
 *      Author: njordan
 */

#include "ArrayType.h"


ArrayType::~ArrayType() {
	// TODO Auto-generated destructor stub
}

int ArrayType::sizeInBytes()
{

	return array.size() * getElementType()->sizeInBytes();

}
