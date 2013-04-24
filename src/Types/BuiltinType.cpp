#include "BuiltinType.h"
#include "TypeInfo.h"

BuiltinType::~BuiltinType() 
{
	// TODO Auto-generated destructor stub
}

BuiltinType::BuiltinType(Type::TypeEnum type)
	: Type(type)
{}

// BuiltinType::BuiltinType(int type)
// 	: Type((int)type)
// {}

int BuiltinType::sizeInBytes()
// TODO this should be size of data in mipsc not size of c++ primitive
// type
{
	// return sizeof(Data);
	return -1;
}


Type* BuiltinType::buildType(TypeInfo tInfo)
// {
// }
// Type* Type::buildType(TypeInfo tInfo)
{
	Type* type = NULL;

	bool unsignedSpecified = tInfo.unsignedSpecified;
	int  integral = tInfo.integral;
	bool longSpecified = tInfo.longLongSpecified;
	bool longLongSpecified = tInfo.longLongSpecified;

	if (unsignedSpecified) {
		if (integral==Char) 
			type = new BuiltinType(Type::uChar);
		else if (integral==Short)
			type = new BuiltinType(Type::uShort);
		else if (integral==Int)
			type = new BuiltinType(Type::uInt);
		else if (longLongSpecified)
			type = new BuiltinType(Type::uLongLong);
		else if (longSpecified)
			type = new BuiltinType(Type::uLong);
	}
	else {
		if (integral==Int) {
			if (longLongSpecified)
				type = new BuiltinType(Type::Long);
			else if (longSpecified)
				type = new BuiltinType(Type::Long);
			else
				type = new BuiltinType(Type::Int);
		}
		else {
			if (integral==Char)
				type = new BuiltinType(Type::Char);
			else if (Short)
				type = new BuiltinType(Type::Short);
			else if (integral==Float)
				type = new BuiltinType(Type::Float);
			else if (integral==Double)
				type = new BuiltinType(Type::Double);
		}
	}

	return type;
}


std::string BuiltinType::getTypeAsString()
{
	return "Builtin todo";
}

std::string BuiltinType::toString()
{
	return getTypeAsString();
}
