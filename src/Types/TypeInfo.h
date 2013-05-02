#ifndef TYPEINFO_H_GUARD
#define TYPEINFO_H_GUARD
#include "common.h"

class TypeInfo {
public:

	TypeInfo();

	TypeInfo(bool longS, bool llongS, bool uS , int integral);

	std::string toString();
	bool longSpecified;
	bool longLongSpecified ;
	bool unsignedSpecified ;
	int  integral ;
};

#endif
