#include "RegisterInfo.h"
#include "MipsVariable.h"
#include <exception>

//
// Anyting related to labelName is an ugly hack
//

MipsVariable::MipsVariable(Type* type, MipsVariableId id)
	: type(type), id(id)
{}

MipsVariable::MipsVariable(std::string labelName, Type* type, MipsVariableId id)
	: labelName(labelName), type(type), id(id)
{}

bool MipsVariable::typeEqual(const MipsVariable &o)
{
	return ( type->getType() == o.type->getType() );
}

DLabel MipsVariable::toDLabel() // based on id and DKind
{
	if (labelName=="") {
	// TODO Make DLabel ctor private and this class friend of DLabel
		// DKind dkind = type.toDKind();
		std::string typeString = type->getTypeAsString();

		return DLabel( typeString + std::to_string(id) );
	} else {
		return DLabel( labelName );
	}
}

MipsVariable::RegisterType MipsVariable::registerType()
{
	if (labelName=="") {
		int typeEnum = type->getType();
		switch (typeEnum) {
			case Type::uChar:
				return Integer;
				break;
			case Type::uShort:
				return Integer;
				break;
			case Type::uInt:
				return Integer;
				break;
			case Type::uLong:
				// return Integer 2
				throw "MipsVariable::registerType()";
				break;
			case Type::uLongLong:
				throw "MipsVariable::registerType()";
				break;
			case Type::Char:
				return Integer;
				break;
			case Type::Short:
				return Integer;
				break;
			case Type::Int:
				return Integer;
				break;
			case Type::Long:
				return Integer;
				break;
			case Type::LongLong:
				throw "MipsVariable::registerType()";
				break;
			case Type::Float:
				return Float;
				break;
			case Type::Double:
				throw "MipsVariable::registerType()";
				break;
		}
		throw "MipsVariable::registerType()";
	}
	else {		
		return Integer;
	}
}

DKind MipsVariable::toDKind()
{
	if (labelName=="") { 
		int typeEnum = type->getType();
		switch (typeEnum) {
			case Type::uChar:
				return DKind(DKind::Byte);
				break;
			case Type::uShort:
				return DKind(DKind::Half);
				break;
			case Type::uInt:
				return DKind(DKind::Word);
				break;
			case Type::uLong:
				return DKind(DKind::Word);
				break;
			case Type::uLongLong:
				throw "MipsVariable::toDKind()";
				break;
			case Type::Char:
				return DKind(DKind::Byte);
				break;
			case Type::Short:
				return DKind(DKind::Half);
				break;
			case Type::Int:
				return DKind(DKind::Word);
				break;
			case Type::Long:
				return DKind(DKind::Word);
				break;
			case Type::LongLong:
				throw "MipsVariable::toDKind() : LongLong " ;
				break;
			case Type::Float:
				return DKind(DKind::Float);
				break;
			case Type::Double:
				throw "MipsVariable::toDKind() : Double" ;
				break;
		}
		throw "MipsVariable::registerType()";
	} else {
		return DKind(DKind::Word);
	}

}
