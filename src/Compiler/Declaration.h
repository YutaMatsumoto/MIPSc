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

	std::vector<std::string> identifiers;

public:

	typedef std::vector<Symbol*> SymbolList;
	SymbolList createSymbols()
	{
	//
	// TODO
	//	
	//	array
	//	const
	//	identifier
	//	initilizer
	//
	
		std::cout << "TypeSpecifiers: " ;
		for (auto typeS : typeSpecifiers ) 
			std::cout << typeS;
		std::cout << std::endl;

		std::cout << "storageSpecifiers: " ;
		for (auto storageS : storageSpecifiers ) 
			std::cout << storageS;
		std::cout << std::endl;

		std::cout << "identifiers: " ;
		for (auto id : identifiers ) 
			std::cout << id;
		std::cout << std::endl;


		std::cout << "implement createSymbols()" << std::endl;

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
					error("a"); // TODO error message and all the errors below
				continue;
			}
			else if (type==Long) {
				if (longLongSpecified)
					error("b");
				if (longSpecified) {
					longLongSpecified = true;
					longSpecified = false;
				}
				else 
					longSpecified = true;
			}
			else if (type==Unsigned) {
				if (unsignedSpecified)
					error("c");
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
				type = new BuiltinType(Type::uChar);
			else if (integral==Short)
				type = new BuiltinType(Type::uShort);
			else if (integral==Int)
				type = new BuiltinType(Type::uInt);
			else if (longLongSpecified)
				type = new BuiltinType(Type::uLongLong);
			else if (longSpecified)
				type = new BuiltinType(Type::uLong);
		}
		else {
			if (integral==Int) {
				if (longLongSpecified)
					type = new BuiltinType(Type::Long);
				else if (longSpecified)
					type = new BuiltinType(Type::Long);
				else
					type = new BuiltinType(Type::Int);
			}
			else {
				if (integral==Char)
					type = new BuiltinType(Type::Char);
				else if (Short)
					type = new BuiltinType(Type::Short);
				else if (integral==Float)
					type = new BuiltinType(Type::Float);
				else if (integral==Double)
					type = new BuiltinType(Type::Double);
			}
		}


		// TODO
		//	
		//	Initialize SymbolLocation and id
		//
		std::vector<Symbol*> symbolList;
		Symbol* sym;
		for (auto identifier : identifiers) {
			sym = new Symbol( identifier,  SymbolLocation(), type);
			symbolList.push_back(sym);
		}

		return symbolList;
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
		if (type=="void") 
			addTypeSpecifier(Void);
		else if (type=="void")
			addTypeSpecifier(Void);
		else if (type=="char")
			addTypeSpecifier(Char);
		else if (type=="short")
			addTypeSpecifier(Short);
		else if (type=="int")
			addTypeSpecifier(Int);
		else if (type=="long")
			addTypeSpecifier(Long);
		else if (type=="float")
			addTypeSpecifier(Float);
		else if (type=="double")
			addTypeSpecifier(Double);
		else if (type=="signed")
			addTypeSpecifier(Signed);
		else if (type=="unsigned")
			addTypeSpecifier(Unsigned);
		else if (type=="struct")
			addTypeSpecifier(Struct);
		else if (type=="union")
			addTypeSpecifier(Union);
		else if (type=="enum")
			addTypeSpecifier(Enum);
		else if (type=="typedef")
			addTypeSpecifier(Typedef);
		else
			error("");
	}

	void addTypeSpecifier(TypeSpecifier spec)
	{
		typeSpecifiers.push_back(spec);
	}

	void addStorageSpeficier(StorageSpecifier spec)
	{
		storageSpecifiers.push_back(spec);
	}

	void pushIdentifier(std::string identifier)
	{
		identifiers.push_back(identifier);
	}

	void clear()
	{
		// TODO : add clear if any data member added
		typeSpecifiers.clear();
		storageSpecifiers.clear();
		identifiers.clear();
	}

private: // methods

	// bool isTypeSpecifier(TypeSpecifier spec)
	// {
	// 	// const static std::vector<std::string> specifiers = {
	// 	// 	"char", 
	// 	// 	"short",
	// 	// 	"
	// 	// };
	// 	// for (auto s : specifiers) {
	// 	// 	if ( s == spec ) {
	// 	// 		return true;
	// 	// 	}
	// 	// }

	// 	// return false;
	// }



};

#endif

