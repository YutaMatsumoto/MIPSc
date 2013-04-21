#ifndef TypeSpecifierNode_H_GUARD
#define TypeSpecifierNode_H_GUARD

#include "common.h"
#include "ASTData.h"

class TypeSpecifierNode {

private:
	size_t specs_size; 
	static std::vector<std::string> specs; 
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
		Float    = 4,
		Double   = 5,
		Long     = 6, IntegralEnd = 6, ModifierStart = 6,
		Signed   = 7, 
		Unsigned = 8, 
		Struct   = 9, ModifierEnd = 9,
		Union    = 10,
		Enum     = 11,
		Typedef  = 12,
		TypeSpecifierEnd
	};

public:

	static std::string integralToString(int integral);

	ASTData* toOperations();

	std::string getNodeTypeAsString();

	TypeSpecifierNode()
		: specifier(TypeSpecifierEnd)
	{initData();}

	TypeSpecifierNode(const TypeSpecifierNode& o)
		: specifier(o.specifier)
	{initData();}

	TypeSpecifierNode(std::string type) ;
	
	TypeSpecifierNode(size_t specifier);

	void initData();

	bool isIntegral();

	int getTypeSpecifier();

	std::string toString();

private:

	void error(std::string error) ;

};



#endif // END TypeSpecifierNode_H_GUARD

