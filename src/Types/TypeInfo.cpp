#include "TypeInfo.h"
#include "TypeSpecifierNode.h"

TypeInfo::TypeInfo()
	: longSpecified(false), longLongSpecified(false),
		unsignedSpecified(false), integral(TypeSpecifierNode::TypeSpecifierEnd) {}

TypeInfo::TypeInfo(bool longS, bool llongS, bool uS , int integral)
	: longSpecified(longS), longLongSpecified(llongS),
		unsignedSpecified(uS), integral(integral) {}

// ---------------------------------------------------------------------------

std::string TypeInfo::toString()
{
	std::string s="TypeInfo: ";
	if (longSpecified)s += "long ";
	if (longLongSpecified) s+= "long long ";
	if (unsignedSpecified) s+= "unsigned ";
	s += TypeSpecifierNode::integralToString(integral);
	return s;
}

