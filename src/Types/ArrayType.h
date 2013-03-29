/*
 * ArrayType.h
 *
 *  Created on: Mar 29, 2013
 *      Author: njordan
 */

#ifndef ARRAYTYPE_H_
#define ARRAYTYPE_H_

#include "Type.h"

class ArrayType: public Type {

public:

	ArrayType();

	virtual ~ArrayType();

	//the array of types(type data)
	std::vector< Type* > array;

};

#endif /* ARRAYTYPE_H_ */
