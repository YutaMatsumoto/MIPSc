/*
 * BuiltinType.h
 *
 *  Created on: Mar 27, 2013
 *      Author: jordan
 */

#ifndef BUILTINTYPE_H_
#define BUILTINTYPE_H_

#include "Type.h"

class BuiltinType: public Type
{
public:

	BuiltinType();

	virtual ~BuiltinType();

	enum Builtins
	{

		uChar,
		uShort,
		uInt,
		uLong,
		uLongLong,
		Char,
		Short,
		Int,
		Long,
		LongLong,
		Float,
		Double,
		Void

	};



};

#endif /* BUILTINTYPE_H_ */
