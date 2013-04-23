#include "DeclarationSpecifiersNode.h"
#include "StorageClassSpecifierNode.h"
#include "TypeInfo.h"

DeclarationSpecifiersNode::DeclarationSpecifiersNode(StorageClassSpecifierNode* s)
{
	sSpecs.push_back(s);
}

DeclarationSpecifiersNode::DeclarationSpecifiersNode( StorageClassSpecifierNode* s, DeclarationSpecifiersNode* ds )
{
	*this = *ds;		
	sSpecs.push_back(s);	
}

DeclarationSpecifiersNode::DeclarationSpecifiersNode( TypeSpecifierNode* ts  )
{
	tSpecs.push_back( ts );
}

DeclarationSpecifiersNode::DeclarationSpecifiersNode( TypeSpecifierNode* ts, DeclarationSpecifiersNode* ds )
{
	*this = *ds;
	tSpecs.push_back(ts);
}

DeclarationSpecifiersNode::DeclarationSpecifiersNode( TypeQualifierNode* ts )
{
	qSpecs.push_back(ts);	
}

DeclarationSpecifiersNode::DeclarationSpecifiersNode( TypeQualifierNode*tq, DeclarationSpecifiersNode* ds)
{
	*this = *ds;
	qSpecs.push_back(tq);
}

void DeclarationSpecifiersNode::error(std::string msg)
{
	std::cerr << "DeclarationSpecifiersNode Error : "<< msg << std::endl;	
}

TypeInfo DeclarationSpecifiersNode::getTypeInfo()
{

	bool longSpecified = false;
	bool longLongSpecified = false;
	bool unsignedSpecified = false;
	int  integral = TypeSpecifierNode::TypeSpecifierEnd;

	//
	// type check
	//
	for (auto type : tSpecs) {
		if( type->isIntegral() ) {
			if (integral == TypeSpecifierEnd) 
				integral = type->getTypeSpecifier();
			else 
				error("type specified more than once.");
			continue;
		}
		else if (type->getTypeSpecifier()==TypeSpecifierNode::Long) {
			if (longLongSpecified)
				error("long specified more than twice");
			if (longSpecified) {
				longLongSpecified = true;
				longSpecified = false;
			}
			else 
				longSpecified = true;
		}
		else if (type->getTypeSpecifier()==TypeSpecifierNode::Unsigned) {
			if (unsignedSpecified)
				error("unsigned specified more than once");
			else
				unsignedSpecified = true;
		}
	}

	if ( (longSpecified || longLongSpecified) && integral == TypeSpecifierEnd )
		integral = TypeSpecifierNode::Int;

	// 
	// Error Check
	//

	// error if integral not specified or cast to int
	// TODO

	// error if ( Float || Double ) && ( Long || Unsigned )
	if ( ( integral==TypeSpecifierNode::Float || integral==TypeSpecifierNode::Double ) 
			&& ( integral==TypeSpecifierNode::Long || integral==TypeSpecifierNode::Unsigned ) )
		error("( Float || Double ) && ( Long || Unsigned ) is illegal");

	// error if Void && ( Long || Unsigned )
	if ( integral==TypeSpecifierNode::Void && ( integral==TypeSpecifierNode::Long || integral==TypeSpecifierNode::Unsigned) )
		error("Void && ( Long || Unsigned ) is illegal");

	// error if Void and not a function return
	// TODO
	// if (TypeSpecifierNode::Void)

	return TypeInfo( longSpecified, longLongSpecified, unsignedSpecified, integral );
}

/*
StorageInfo DeclarationSpecifiersNode::getStorageInfo()
{
	return StorageInfo();
}
*/

TypeQualInfo DeclarationSpecifiersNode::getTypeQualInfo()
{
	TypeQualInfo tQualInfo;

	for ( auto typeQual : qSpecs ) {
		int tq = typeQual->getTypeQualitiferValue();
		if (tq==TypeQualifierNode::Const) {
			bool success = tQualInfo.setConstness();
			if (!success) 
				cerr << "const declared twice or more" << endl;
				; // throw
		}
		else if (tq==TypeQualifierNode::Volatile) {
			bool success = tQualInfo.setVolatileness();
			if (!success) 
				cerr << "const declared twice or more" << endl;
				; // throw
		}
		else { // does not happen 
		}
	}

	return tQualInfo;
}
