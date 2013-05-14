#include <algorithm>
#include "MipsData.h"
#include "MipsError.h"
#include <iostream>
#include <string>


// ---------------------------------------------------------------------------
// DLabel

void Warn(std::string msg)
{
	std::cout << "Warning: " << msg << std::endl;
}

DLabel::DLabel()
{
	Warn("DLabel : Empty Label Created");	
}

DLabel::DLabel(const std::string& label)
	: label(label)
{}

bool DLabel::operator==(const DLabel& o) const
{
	return ( label == o.label );
}

bool DLabel::operator<(const DLabel& o) const
{
	return ( label < o.label );
}

std::string DLabel::toString()
{
	return label;	
}

// ---------------------------------------------------------------------------
// DKind

DKind::DKind(DKindType kind)
	: kind(kind)
{}

std::string DKind::toString()
{
	switch(kind) {
		case Word:   return  ".word";
		case Ascii:  return  ".ascii";
		case Asciiz: return  ".asciiz";
		case Byte:   return  ".byte";
		case Align:  return  ".align";
		case Half:	 return  ".half";
		case Space:  return  ".space";
		case Double: return  ".double";
		case Float:  return  ".float";
		case Extern: return  ".extern";
		case Kdata:  return  ".kdata";
		case Global: return  ".global";
	}
	throw MipsError("DKind::toString() : kind is invalid");
}

// ---------------------------------------------------------------------------
// DKindInit

DKindInit::DKindInit(DKind kind, std::string init)
	: kind(kind), init(init)
{
	throw MipsError("Implement DKindInit");
	// Check init according to dkind
}

DKind DKindInit::getKind()
{
	return kind;
}

DInit DKindInit::getInit()
{
	return init;
}

