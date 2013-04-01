/*
 * EnumType.h
 *
 *  Created on: Mar 29, 2013
 *      Author: njordan
 */

#ifndef ENUMTYPE_H_
#define ENUMTYPE_H_

#include "Type.h"

class EnumType: public Type {
public:

	EnumType() : Type( Enum )
	{

	}

	virtual ~EnumType();

	std::vector< std::string > enumValues;

};

#endif /* ENUMTYPE_H_ */
