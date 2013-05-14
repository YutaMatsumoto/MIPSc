#ifndef MIPS_CODE_H_GUARD
#define MIPS_CODE_H_GUARD

#include <string>
#include <vector>
#include "MipsData.h"
#include "MipsVariable.h"

// Should be singleton ?

// Usage
//
//	Keep writing data section and text section by writeToDataSection() and
//	writeToTextSection() functions, and use dump() at last.
//
//	Use setIndentLevel()/getIndentLevel() to make the code look nice.
//	

class MipsCode {
public: 

	// void writeToDataSection(DLabel, DKind, DInit, Comment); // write data entry
	void writeToDataSection(MipsVariable, DInit, Comment); // write data entry
	
	// void writeToDataSection(DLabel, DKind, Comment); // write data entry without initialization
	void writeToDataSection(MipsVariable, Comment); // write data entry without initialization

	void writeToTextSection(Code, Comment); // write text entry

	void dump(); // Dump MIPS code

	static MipsCode& getInstance()
	{
		static MipsCode instance;
		return instance;
	}

	// void setIndentLevel(size_t level); // Maybe 
	// void getIndentLevel(); // Maybe
	// writeToTextSection(/*ASTData*/); // Maybe

private: // struct and class

	// -----------------------------------------------------------------------
	// Text Section Entry

	class Text {
	private:
		Code code;
		Comment com;
	public:	
		Text(Code code, Comment com);
		std::string toString();
	};

	// -----------------------------------------------------------------------
	// Data Section Entry

	class Data {
	private:
		DLabel label;	
		DKind  kind;
		DInit  init;
		Comment com;
	public:
		Data(DLabel, DKind, Comment);
		Data(DLabel, DKindInit, Comment);
		std::string toString();
	};

private: // data members

	static std::vector<DLabel> allLabels; // check conflicts

	size_t indentLevel = 0;

	std::vector<Data> dataSection;
	std::vector<Text> textSection;

private: // for singleton
	MipsCode();
	MipsCode(MipsCode const&);
	void operator=(MipsCode const&);
};

#endif
