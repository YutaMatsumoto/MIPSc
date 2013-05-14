#include "MipsCode.h"
#include <iostream>
#include "IdTracker.h"
#include "BuiltinType.h"
using namespace std;

int main()
{
	MipsCode& mCode = MipsCode::getInstance();

	// Generage ID's
	vector<unsigned int> ids;
	for (int i = 0; i < 10; i++)
		ids.push_back( IdTracker::getInstance()->getId() );

	//
	// Generage Types
	//
	// Some of these throw exceptions
	//
	// Type uCharType (Type::uChar);
	// Type uShort    (Type::uShort);
	// Type uInt      (Type::uInt);
	// Type uLong     (Type::uLong);
	// Type uLongLong (Type::uLongLong);
	Type* CharType  = new Type( Type::Char) ;
	Type* ShortType = new Type( Type::Short);
	Type* IntType   = new Type( Type::Int)  ;
	Type* LongType  = new Type( Type::Long) ;
	// Type LongLong  (Type::LongLong);
	// Type Float     (Type::Float);
	// Type Double    (Type::Double);

	// -----------------------------------------------------------------------
	MipsVariable m1(CharType, ids[0]);	
	MipsVariable m2(ShortType, ids[2]);	
	MipsVariable m3(IntType, ids[3]);	
	MipsVariable m4(LongType, ids[4]);	
	
	// -----------------------------------------------------------------------
	// Data Section

	mCode.writeToDataSection( m1, "some comment on i1"); 
	mCode.writeToDataSection( m3, "some comment on i1"); 

	// Error since i1 defined twice
	// try {
	// 	mCode.writeToDataSection( DLabel("i1"), DKind(DKind::Word), "some comment on i1"); 
	// } catch (const exception& e) {
	// 	cout << e.what() << endl;
	// }
	
	// mCode.writeToDataSection( DLabel("i2"), DKind(DKind::Word), "some comment on i2"); 
	// mCode.writeToDataSection( DLabel("c1"), DKind(DKind::Byte), "some comment on c1"); 
	// mCode.writeToDataSection( DLabel("c2"), DKind(DKind::Byte), "some comment on c2"); 

	// -----------------------------------------------------------------------
	// Text Sectoin
	
	// mCode.writeToTextSection( "lw $t1,i1", "Load word i1 to $t1" );
	// mCode.writeToTextSection( "lw $t2,i2", "Load word i1 to $t2" );
	// mCode.writeToTextSection( "lb $t3,c1", "Load byte c1 to $t3" );

	// -----------------------------------------------------------------------
	// Write Data Sectoin After Text Section
	// mCode.writeToDataSection( DLabel("i3"), DKind(DKind::Word), "some comment on i3"); 

	// -----------------------------------------------------------------------
	// Dump
	mCode.dump();

		

}
