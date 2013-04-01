/*
 * TypedefType.h
 *
 *  Created on: Mar 29, 2013
 *      Author: njordan
 */

#ifndef TYPEDEFTYPE_H_
#define TYPEDEFTYPE_H_

#include "Type.h"

class TypedefType: public Type {
public:

	TypedefType() : Type( Typedef )
	{

	}

	virtual ~TypedefType();

	//The type referenced by this typedef
	Type* redefinedType;

};

#endif /* TYPEDEFTYPE_H_ */
