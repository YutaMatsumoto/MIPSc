#ifndef GrammarSymbol_H_GUARD
#define GrammarSymbol_H_GUARD

#include "../AST/Nodes.h"

using namespace std;


// ---------------------------------------------------------------------------

// TODO
static const size_t specs_size = 13;
const std::string specs[specs_size] = {
"void",
"char",
"short",
"int",
"long",
"float",
"double",
"signed",
"unsigned",
"struct",
"union",
"enum",
"typedef"
};

// Should be a singleton?
class TypeSpecifierSymbol {

private:
	// typedef int TypeSpecEnum;
	// TypeSpecEnum specifier;
	size_t specifier;
	// std::string specifier;

public:

	enum TypeSpecifierEnum {
		Void     = 0, TypeSpecifierStart = 0,
		Char     = 1, IntegralStart = 1,
		Short    = 2,
		Int      = 3,
		Long     = 4,
		Float    = 5,
		Double   = 6,
		Signed   = 7, IntegralEnd   = 7,
		Unsigned = 8,
		Struct   = 9,
		Union    = 10,
		Enum     = 11,
		Typedef  = 12,
		TypeSpecifierEnd
	};

public:

	TypeSpecifierSymbol()
		: specifier(TypeSpecifierEnd)
	{}

	TypeSpecifierSymbol(const TypeSpecifierSymbol& o)
		: specifier(o.specifier)
	{}

	TypeSpecifierSymbol(std::string type) 
	{

		// std::cerr << "addTypeSpecifier(string): TODO" << std::endl;
		bool success = false;
		for (size_t spec = 0 ; spec<specs_size ; spec++) {
			if ( specs[ spec ] == type ) {
				success = true;
				this->specifier = (TypeSpecifierEnum) spec ;
				break;
			}
		}

		// error
		if ( ! success ) {
			error("TypeSpecifier is invalid. <" + type + "> given.");
		}
	}	
	
	TypeSpecifierSymbol(size_t specifier)
	{
		bool success = false;
		for ( size_t spec = TypeSpecifierStart ; spec < TypeSpecifierEnd; spec++ ) {
			if (specifier == spec) {
				success = true;
				this->specifier = (TypeSpecifierEnum) spec;
				break;
			}
		}
		// Error
		if ( ! success ) {
			std::string s( std::to_string( specifier ) );
			if ( specifier < specs_size ) {
				s = s + " " + specs[specifier];
			}
			error("TypeSpecifier is invalid. <" + s + "> given.");
		}
	}

	bool isIntegral()
	{
		for ( size_t integral = IntegralStart ; integral<IntegralEnd ; integral++ ) {
			if ( specifier == integral ) {
				return true;
			}
		}
		return false;
	}

	std::string toString()
	{	
		for (size_t spec = TypeSpecifierStart; spec < TypeSpecifierEnd; spec++ ) {
			if ( specifier == spec ) {
				return specs[spec];
			}
		}
		return "";
	}

private:
	void error(std::string error) 
	{
		std::cout << "TypeSpecifier Error : " << error << std::endl;
	}

};


// const std::string TypeSpecifierSymbol::specs[TypeSpecifierSymbol::specs_size] = {
// 	"void",
// 	"char",
// 	"short",
// 	"int",
// 	"long",
// 	"float",
// 	"double",
// 	"signed",
// 	"unsigned",
// 	"struct",
// 	"union",
// 	"enum",
// 	"typedef"
// };

// ---------------------------------------------------------------------------

// typedef std::string StorageSpecifierSymbol;
class StorageSpecifierSymbol {
private:
	std::string s;

public:
	StorageSpecifierSymbol() {}
	StorageSpecifierSymbol(const std::string& s) : s(s) {}

};

// ---------------------------------------------------------------------------

class DeclarationSpecifiers {

	std::vector<TypeSpecifierSymbol> tSpecs;
	std::vector<StorageSpecifierSymbol> sSpecs;

	typedef std::string TypeQualifierSymbol;
	std::vector<TypeQualifierSymbol> qSpecs;
	
public:

	DeclarationSpecifiers() {}

	void addTypeSpecifier(TypeSpecifierSymbol t)
	{
		tSpecs.push_back(t);
	}

	void addStorageSpecifier(StorageSpecifierSymbol s)
	{
		sSpecs.push_back(s);
	}

	void addTypeQualifier(std::string s)
	{
		qSpecs.push_back(s);
	}

	bool determineType()
	{
		// TODO
		return true;
	}

	
};


#endif

