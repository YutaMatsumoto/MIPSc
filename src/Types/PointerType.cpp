/*
 * PointerType.cpp
 *
 *  Created on: Mar 29, 2013
 *      Author: njordan
 */

#include "PointerType.h"

PointerType::~PointerType() {
	// TODO Auto-generated destructor stub
}

int PointerType::sizeInBytes()
{

	//Pointer size on MIPS should be 32 bits
	return 4;

}
