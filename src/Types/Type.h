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

class DeclarationSpecifiersNode;
class TypeInfo;

enum TypeSpecifier {
	Void,
	Char, // Integral Start
	Short,
	Int,
	Long,
	Float,
	Double, // Double + 1 = Integral End
	Signed, 
	Unsigned,
	Struct,
	Union,
	Enum,
	Typedef,
	TypeSpecifierEnd
};

enum StorageSpecifier
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
		// Builtin,
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
		Void, // Builtin End
		Enum,
		Union,
		Struct,
		Pointer,
		Typedef,
		Array,
		Function 
	};

	int getType();

	virtual std::string getTypeAsString();

	virtual std::string toString();

	virtual int sizeInBytes() = 0;

protected:

	// Type(); // need this?

	Type( TypeEnum );

// ---------------------------------------------------------------------------
// data member
//
private:

	std::string id;

	// Symbol* typeSymbol;

	std::vector< std::string > storageSpecifiers;

	std::vector< std::string > typeQualifiers;

	TypeEnum type;

};

#endif /* TYPE_H_ */
