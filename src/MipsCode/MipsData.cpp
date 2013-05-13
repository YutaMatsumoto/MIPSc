#include <algorithm>
#include "MipsData.h"
#include "MipsError.h"

// ---------------------------------------------------------------------------
// DLabel

std::vector<std::string> DLabel::allLabels;

DLabel::DLabel(const std::string& label)
	: label(label)
{
	// Error if the label already exists 
	typedef std::vector<std::string>::iterator Iter;
	Iter iter = std::find( DLabel::allLabels.begin(), DLabel::allLabels.end(), label) ;
	if ( iter != allLabels.end() ) {
		throw MipsError( "Same Label Generated in MIPS" );
	}

	allLabels.push_back(label);
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

