/*
 * Type.h
 *
 *  Created on: Mar 13, 2013
 *      Author: njordan
 */

#ifndef TYPE_H_
#define TYPE_H_

#include <string>
#include <vector>
#include "Symbol.h"

enum StorageSpeficier
{
	Extern,
	Static,
	Register,
	Auto
};

enum TypeQualifier
{
	Const,
	Volatile
};

class Type
{
public:

	std::string getId();

	virtual ~Type();

	enum TypeEnum {
		Builtin,
		Enum,
		Union,
		Struct,
		Pointer,
		Typedef,
		Array,
		Function
	};

	TypeEnum getType() 
	{
		return type;
	}

	int sizeInBytes();

	std::string id;

	Symbol* typeSymbol;

	std::vector< std::string > storageSpecifiers;

	std::vector< std::string > typeQualifiers;

	TypeEnum type;

protected:

	Type();

};

#endif /* TYPE_H_ */
