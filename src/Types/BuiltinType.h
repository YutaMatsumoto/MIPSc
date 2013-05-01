/*
 * BuiltinType.h
 *
 *  Created on: Mar 27, 2013
 *      Author: jordan
 */

#ifndef BUILTINTYPE_H_
#define BUILTINTYPE_H_

#include "Type.h"

/*
enum BuiltinTag
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
*/

template <class Data> class BuiltinType : public Type
{
public:

	// BuiltinType(int/*Builtins enum*/ tag)
	BuiltinType(Type::TypeEnum type)
		: Type(type), data(Data())
	{}

	BuiltinType(Type::TypeEnum type, Data data)
		: Type(type), data(data)
	{}

	// virtual ~BuiltinType();



	/* template might save time if we could do it.
	 *
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
	*/

	Data data;

	virtual int sizeInBytes()
	{

		return sizeof(Data);

	}

};

#endif /* BUILTINTYPE_H_ */
