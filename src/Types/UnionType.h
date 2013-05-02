/*
 * UnionType.h
 *
 *  Created on: Mar 29, 2013
 *      Author: njordan
 */

#ifndef UNIONTYPE_H_
#define UNIONTYPE_H_

#include "Type.h"

class UnionType: public Type {
public:

	UnionType() : Type( Union )
	{

	}

	virtual ~UnionType();

	//The possible types that can be stored in this union
	std::vector< Type* > possibleTypes;

	virtual int sizeInBytes();

};

#endif /* UNIONTYPE_H_ */
