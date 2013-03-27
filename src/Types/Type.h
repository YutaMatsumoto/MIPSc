/*
 * Type.h
 *
 *  Created on: Mar 13, 2013
 *      Author: njordan
 */

#include <string>

#ifndef TYPE_H_
#define TYPE_H_



class Type
{
public:

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

	virtual Type();

	virtual ~Type();

	virtual bool isBuiltinType();

	virtual bool isEnumType();

	virtual bool isUnionType();

	virtual bool isStructType();

	virtual bool isPointerType();

	virtual bool isTypedefType();

	virtual bool isArrayType();

	virtual bool isFunctionType();

	int sizeInBytes();

	std::string id;

	Symbol* typeSymbol;

	std::vector<Type::StorageSpecifier> storageSpecifiers;

	std::vector<Type::TypeQualifier> typeQualifiers;

};

#endif /* TYPE_H_ */
