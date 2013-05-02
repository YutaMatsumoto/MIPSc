<<<<<<< HEAD
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

public:

=======
/*
 * TypeSpecifierNode.h
 *
 *  Created on: May 1, 2013
 *      Author: njordan
 */

#include "Node.h"
#include <string>
#include <vector>

#ifndef TYPESPECIFIERNODE_H_
#define TYPESPECIFIERNODE_H_

class TypeSpecifierNode : public Node {

private:

	size_t specs_size;
	static std::vector<std::string> specs;
	size_t specifier;


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

>>>>>>> nate
	static std::string integralToString(int integral);

	ASTData* toOperations();

	std::string getNodeTypeAsString();

<<<<<<< HEAD
	TypeSpecifierNode()
		: specifier(TypeSpecifierEnd)
	{initData();}

	TypeSpecifierNode(const TypeSpecifierNode& o)
		: specifier(o.specifier)
	{initData();}

	TypeSpecifierNode(std::string type) ;
	
=======
	TypeSpecifierNode();

	TypeSpecifierNode(const TypeSpecifierNode& o);

	TypeSpecifierNode(std::string type);

>>>>>>> nate
	TypeSpecifierNode(size_t specifier);

	void initData();

	bool isIntegral();

	int getTypeSpecifier();

	std::string toString();

<<<<<<< HEAD
private:

	void error(std::string error) ;

};



#endif // END TypeSpecifierNode_H_GUARD

=======
	void error(std::string error);
};

#endif /* TYPESPECIFIERNODE_H_ */
>>>>>>> nate
