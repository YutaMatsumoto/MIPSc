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

	ArrayType( Type* ) : Type( Array )
	{

	}

	virtual ~ArrayType();

	Type* getElementType()
	{

		return array.at( 0 );

	}

	//whether its 1D, 2D, 3d, 4d...
	unsigned int dimension;

	std::vector< unsigned int > offsets;

	//the array of types(type data)
	std::vector< Type* > array;

};

#endif /* ARRAYTYPE_H_ */
