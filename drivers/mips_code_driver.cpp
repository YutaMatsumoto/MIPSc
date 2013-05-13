#include "MipsCode.h"
#include <iostream>
using namespace std;

int main()
{
	MipsCode& mCode = MipsCode::getInstance();

	// -----------------------------------------------------------------------
	// Data Section

	mCode.writeToDataSection( DLabel("i1"), DKind(DKind::Word), "some comment on i1"); 

	// Error since i1 defined twice
	try {
		mCode.writeToDataSection( DLabel("i1"), DKind(DKind::Word), "some comment on i1"); 
	} catch (const exception& e) {
		cout << e.what() << endl;
	}
	
	mCode.writeToDataSection( DLabel("i2"), DKind(DKind::Word), "some comment on i2"); 
	mCode.writeToDataSection( DLabel("c1"), DKind(DKind::Byte), "some comment on c1"); 
	mCode.writeToDataSection( DLabel("c2"), DKind(DKind::Byte), "some comment on c2"); 

	// -----------------------------------------------------------------------
	// Text Sectoin
	
	mCode.writeToTextSection( "lw $t1,i1", "Load word i1 to $t1" );
	mCode.writeToTextSection( "lw $t2,i2", "Load word i1 to $t2" );
	mCode.writeToTextSection( "lb $t3,c1", "Load byte c1 to $t3" );

	// -----------------------------------------------------------------------
	// Write Data Sectoin After Text Section
	mCode.writeToDataSection( DLabel("i3"), DKind(DKind::Word), "some comment on i3"); 

	// -----------------------------------------------------------------------
	// Dump
	mCode.dump();

		

}
