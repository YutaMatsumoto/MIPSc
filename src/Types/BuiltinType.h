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

	struct value
	{

		unsigned char ucharVal;

		unsigned short ushortVal;

		unsigned int uintVal;

		unsigned long ulongVal;

		unsigned long long ulonglongVal;

		char charVal;

		short shortVal;

		int intVal;

		long longVal;

		long long longlongVal;

		float floatVal;

		double doubleVal;

	};

};

#endif /* BUILTINTYPE_H_ */
