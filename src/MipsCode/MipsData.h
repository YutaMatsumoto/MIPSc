#ifndef MIPS_DATA_H_GUARD
#define MIPS_DATA_H_GUARD
#include <string>
#include <vector>

// -----------------------------------------------------------------------
// Data Sectoin Entry Components : Three Componenets of Data
//
//	Label, Kind, and Init
//
//	ex.  i00000: .word 0x0
//

// class DLabel;
// class DKind;
typedef std::string DInit;
typedef std::string Comment;
typedef std::string Code;

// ---------------------------------------------------------------------------

class DLabel {
private:
	std::string	label;
public:
	DLabel();
	DLabel(const std::string&);
	bool operator==(const DLabel& o) const; 
	bool operator<(const DLabel& o) const; 
	std::string toString();
};

// ---------------------------------------------------------------------------

class DKind {
public:
	enum DKindType {
		// Data, Text, 
		Word, Ascii, Asciiz, Byte, Align, Half, Space, Double, Float, Extern, Kdata,
		// ktext,
		Global,
		// set, // eqv, // macro, // endmacro, // include,
	};
	DKind(DKindType);
	std::string toString();
private:
	DKindType kind;	
};

// ---------------------------------------------------------------------------

class DKindInit {
private:
	DKind kind;
	DInit init;
public:
	DKindInit(DKind, DInit);
	DKind getKind();
	DInit getInit();
	std::string toString();
	// Maybe // DInit(std::vector<std::string>) // for initialization list
};

#endif
