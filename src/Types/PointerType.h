/*
 * PointerType.h
 *
 *  Created on: Mar 29, 2013
 *      Author: njordan
 */

#ifndef POINTERTYPE_H_
#define POINTERTYPE_H_

#include "Type.h"

class PointerType: public Type {
public:

	PointerType() : Type( Pointer )
	{

	}

	virtual ~PointerType();

	//The symbol being pointed to
	Symbol* symbol;

	virtual int sizeInBytes();

};

#endif /* POINTERTYPE_H_ */
