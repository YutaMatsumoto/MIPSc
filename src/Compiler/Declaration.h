#ifndef DECLARATION_H_GUARD
#define DECLARATION_H_GUARD

#include <string>
#include <vector>
#include "Parserbase.h"
#include "Type.h" // for enum's
#include "Symbol.h"

#include "BuiltinType.h"

class Declaration {
private: // data members

	// typedef std::string typeSpecifier;
	// typedef std::string declarationSpecifier;

	typedef int TypeSpecifier;
	std::vector<TypeSpecifier> typeSpecifiers;
	typedef int StorageSpecifier;
	std::vector<StorageSpecifier> storageSpecifiers;

public:

	Symbol* createSymbol()
	{
	//
	// TODO
	//	
	//	array
	//	const
	//	identifier
	//	initilizer
	//

		std::cout << "implement createSymbol()" << std::endl;

		TypeSpecifier integral = TypeSpecifierEnd;

		bool longSpecified = false;
		bool longLongSpecified = false;
		bool unsignedSpecified = false;

		//
		// type check
		//
		for (auto type : typeSpecifiers) {
			if( isIntegral(type) ) {
				if (integral == TypeSpecifierEnd) 
					integral = type;
				else 
					error(""); // TODO error message and all the errors below
				continue;
			}
			else if (type==Long) {
				if (longLongSpecified)
					error("");
				if (longSpecified) {
					longLongSpecified = true;
					longSpecified = false;
				}
				else 
					longSpecified = true;
			}
			else if (type==Unsigned) {
				if (unsignedSpecified)
					error("");
				else
					unsignedSpecified = true;
			}
		}

		if ( (longSpecified || longLongSpecified) && integral == TypeSpecifierEnd )
			integral = Int;

		// 
		// Error Check
		//

		// error if integral not specified
		// TODO

		// error if ( Float || Double ) && ( Long || Unsigned )
		// TODO

		// error if Void && ( Long || Unsigned )
		// TODO

		// error if Void and not a function return
		// TODO
		//

		//
		//  create symbol
		//
		Type* type;

		if (unsignedSpecified) {
			if (integral==Char) 
				type = new BuiltinType<char>(Type::uChar);
			else if (integral==Short)
				type = new BuiltinType<short>(Type::uShort);
			else if (integral==Int)
				type = new BuiltinType<int>(Type::uInt);
			else if (longLongSpecified)
				type = new BuiltinType<unsigned long long>(Type::uLongLong);
			else if (longSpecified)
				type = new BuiltinType<unsigned long>(Type::uLong);
		}
		else {
			if (integral==Int) {
				if (longLongSpecified)
					type = new BuiltinType<long long>(Type::Long);
				else if (longSpecified)
					type = new BuiltinType<long>(Type::Long);
				else
					type = new BuiltinType<int>(Type::Int);
			}
			else {
				if (integral==Char)
					type = new BuiltinType<char>(Type::Char);
				else if (Short)
					type = new BuiltinType<short>(Type::Short);
				else if (integral==Float)
					type = new BuiltinType<float>(Type::Float);
				else if (integral==Double)
					type = new BuiltinType<double>(Type::Double);
			}
		}


		// TODO
		//	
		//	Initialize SymbolLocation and id
		//
		Symbol* sym = new Symbol( "TODO",  SymbolLocation(), type);

		return sym;
	}

	void error(std::string msg)
	{
		std::cerr << "Error: " << msg << std::endl;
	}

	inline bool isIntegral(TypeSpecifier type)
	{
		int integralEnd = Double + 1;
		for( int i = Char; i<integralEnd ; i++) {
			if (i==type) {
				return true;
			}
		}
		return false;
	}

	// TODO
	void addTypeSpecifier(std::string type)
	{
		std::cerr << "addTypeSpecifier(string): TODO" << std::endl;
	}

	void addTypeSpecifier(TypeSpecifier spec)
	{
		typeSpecifiers.push_back(spec);
	}

	void addStorageSpeficier(StorageSpecifier spec)
	{
		storageSpecifiers.push_back(spec);
	}

	void clear()
	{
		
	}

private: // methods

	bool isTypeSpecifier(TypeSpecifier spec)
	{
		// const static std::vector<std::string> specifiers = {
		// 	"char", 
		// 	"short",
		// 	"
		// };
		// for (auto s : specifiers) {
		// 	if ( s == spec ) {
		// 		return true;
		// 	}
		// }

		// return false;
	}



};

#endif

