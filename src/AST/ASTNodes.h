/*
 * ASTNodes.h
 *
 *  Created on: Apr 3, 2013
 *      Author: njordan
 */

#ifndef ASTNODES_H_
#define ASTNODES_H_

#include "ParserError.h"
#include "Node.h"
#include <cfloat>
#include "SymbolTable.h"
#include "Type.h"
#include "BuiltinType.h"
#include "AllASTNodes.h"

// ---------------------------------------------------------------------------
//
// DeclarationNode ... DirectAbstractDeclaratorNode
//

using namespace std;

class DeclarationNode;
class DeclarationSpecifiersNode;
class StorageClassSpecifierNode;
class TypeSpecifierNode;
class TypeQualifierNode;
class StructOrUnionSpecifierNode;
class StructOrUnionNode;
class StructDeclarationListNode;
class InitDeclaratorListNode;
class InitDeclaratorNode;
class StructDeclarationNode;
class SpecifierQualifierListNode;
class StructDeclaratorListNode;
class StructDeclaratorNode;
class EnumSpecifierNode;
class EnumeratorListNode;
class EnumeratorNode;
class DeclaratorNode;
class DirectDeclaratorNode;
class PointerNode;
class TypeQualifierListNode;
class ParameterTypeListNode;
class ParameterListNode;
class ParameterDeclarationNode;
class IdentifierListNode;
class InitializerNode;
class InitializerListNode;
class TypeNameNode;
class AbstractDeclaratorNode;
class DirectAbstractDeclaratorNode;

// class ConstantExpressionNode;
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

	static std::string integralToString(int integral)
	{
		if (integral==Void) 
			return "void";
		else if (integral==Char) 
			return "char";
		else if (integral==Short) 
			return "short";
		else if (integral==Int) 
			return "int";
		else if (integral==Long) 
			return "long";
		else if (integral==Float) 
			return "float";
		else if (integral==Double) 
			return "double";
		else if (integral==Signed) 
			return "signed";
		else if (integral==Unsigned) 
			return "unsigned";
		else if (integral==Struct) 
			return "struct";
		else if (integral==Union) 
			return "union";
		else if (integral==Enum) 
			return "enum";
		else if (integral==Typedef) 
			return "typedef";
		else
			return "invalid type";
	}

	std::vector<Operation> toOperations()
	{
		std::vector<Operation> emptyHack;
		return emptyHack;
	}

	std::string getNodeTypeAsString()
	{
		return "TypeSpecifier";
	}

	TypeSpecifierNode()
		: specifier(TypeSpecifierEnd)
	{initData();}

	TypeSpecifierNode(const TypeSpecifierNode& o)
		: specifier(o.specifier)
	{initData();}

	TypeSpecifierNode(std::string type) 
	{
		initData();

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
	
	TypeSpecifierNode(size_t specifier)
	{
		initData();
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
				s = s + " " + integralToString( specifier );
			}
			error("TypeSpecifier is invalid. <" + s + "> given.");
		}
	}

	void initData()
	{
		// specs.push_back( "void" );
		// specs.push_back( "char" );
		// specs.push_back( "short" );
		// specs.push_back( "int" );
		// specs.push_back( "long" );
		// specs.push_back( "float" );
		// specs.push_back( "double" );
		// specs.push_back( "signed" );
		// specs.push_back( "unsigned" );
		// specs.push_back( "struct" );
		// specs.push_back( "union" );
		// specs.push_back( "enum" );
		// specs.push_back( "typedef");
		specs_size = 13;
	}

	bool isIntegral()
	{
		// std::cout << "isIntegral() : "  << toString() << " : ";
		for ( size_t integral = IntegralStart ; integral<IntegralEnd ; integral++ ) {
			if ( specifier == integral ) {
				// std::cout << " true  " << std::endl;
				return true;
			}
		}
		// std::cout << " false " << std::endl;
		return false;
	}

	int getTypeSpecifier()
	{
		return specifier;
	}

	std::string toString()
	{	
		for (size_t spec = TypeSpecifierStart; spec < TypeSpecifierEnd; spec++ ) {
			if ( specifier == spec ) {
				return integralToString( spec );
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

class DeclarationSpecifiersNode {

	std::vector<TypeSpecifierNode*> tSpecs;
	std::vector<StorageClassSpecifierNode*> sSpecs;
	std::vector<TypeQualifierNode*> qSpecs;
	
public:

	DeclarationSpecifiersNode( StorageClassSpecifierNode* s )
	{
		sSpecs.push_back(s);
	}

	DeclarationSpecifiersNode( StorageClassSpecifierNode* s, DeclarationSpecifiersNode* ds )
	{
		*this = *ds;		
		sSpecs.push_back(s);	
	}

	DeclarationSpecifiersNode( TypeSpecifierNode* ts  )
	{
		tSpecs.push_back( ts );
	}

	DeclarationSpecifiersNode( TypeSpecifierNode* ts, DeclarationSpecifiersNode* ds )
	{
		*this = *ds;
		tSpecs.push_back(ts);
	}

	DeclarationSpecifiersNode( TypeQualifierNode* ts )
	{
		qSpecs.push_back(ts);	
	}

	DeclarationSpecifiersNode( TypeQualifierNode*tq, DeclarationSpecifiersNode* ds)
	{
		*this = *ds;
		qSpecs.push_back(tq);
	}

	void error(std::string msg)
	{
		std::cerr << "DeclarationSpecifiersNode Error : "<< msg << std::endl;	
	}

	struct TypeInfo {

		TypeInfo()
			: longSpecified(false), longLongSpecified(false),
			  unsignedSpecified(false), integral(TypeSpecifierNode::TypeSpecifierEnd) {}

		TypeInfo(bool longS, bool llongS, bool uS , int integral)
			: longSpecified(longS), longLongSpecified(llongS),
			  unsignedSpecified(uS), integral(integral) {}

		std::string toString()
		{
			std::string s="TypeInfo: ";
			if (longSpecified)s += "long ";
			if (longLongSpecified) s+= "long long ";
			if (unsignedSpecified) s+= "unsigned ";
			s += TypeSpecifierNode::integralToString(integral);
			return s;
		}

		bool longSpecified;
		bool longLongSpecified ;
		bool unsignedSpecified ;
		int  integral ;
	};
	TypeInfo getTypeInfo()
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

	// TODO
	struct StorageInfo {
	};
	StorageInfo getStorageInfo()
	{
		return StorageInfo();
	}

	// TODO
	struct TypeQualInfo {
		bool constness;
		bool volatileness;
	};
	TypeQualInfo getTypeQualInfo() 
	{
		return TypeQualInfo();
	};

	
};

class StorageClassSpecifierNode {
private:
	int specifier;

const char specs[5][10] = {
	"auto",
	"register",
	"static",
	"extern",
	"typedef"
};

public:

	enum StorageSpecifierKind {
		Auto = 0,  StorageSpecifierKindStart = 0,
		Register,
		Static,
		Extern,
		Typedef, StorageSpecifierKindEnd = Typedef,
	};

	StorageClassSpecifierNode(int storageSpecKind );

};

class TypeQualifierNode {
};

class StructOrUnionSpecifierNode {
};

class StructOrUnionNode {
};

class StructDeclarationListNode {
};

class InitDeclaratorListNode {
public:

	InitDeclaratorListNode() {}

	InitDeclaratorListNode( InitDeclaratorNode* n)
	{
		declaratorList.push_back(n);
	}

	InitDeclaratorListNode( InitDeclaratorListNode* a,  InitDeclaratorNode* b )
	{
		for (auto initDecl : a->declaratorList) {
			declaratorList.push_back(initDecl);
		}
		declaratorList.push_back(b);
	}


	void add(InitDeclaratorNode* initDecl) 
	{
		declaratorList.push_back(initDecl);	
	}

	std::vector<InitDeclaratorNode*> declaratorList;
};

class DirectDeclaratorNode {
public:

	enum DirectDeclaratorKind {
		None,
		Array,
		ArrayWithSize,
		FunctionDefinition,
		FunctionDefinitionWithParam,
		FunctionCall,
		FunctionCallWithParam
	};

	string toString()
	{
		if (id) {
			return id->getId();
		}
		else if (dirDeclNode){
			return dirDeclNode->toString();
		}
		else {
			error("both of id and dirDeclNode is null");
			return "bad DirectDeclaratorNode";
		}
	}

	void error(string msg)
	{
		cerr << "Error : DirectDeclaratorKind : " << msg << endl;
	}

	DirectDeclaratorNode() {initData();}

	DirectDeclaratorNode( DirectDeclaratorNode* a)
	{
		initData();	
		dirDeclNode = a;
	}

	DirectDeclaratorNode( IdentifierNode* id )
	{
		initData();
		this->id = id;
	}

	void initData()
	{
		array = false;
		functionCall = false;
		functionDefinition = false;

		kind = None;

		id = NULL;
		dirDeclNode = NULL;
		declNode = NULL;
		idListNode = NULL;
		arraySize = NULL;
		funcParams = NULL;
	}

	void specifyArray()
	{
		// TODO check existence of initializer in the upstream
		array = true;
		kind = Array;
	}

	void specifyArray( ConstantExpressionNode* a)
	{
		arraySize = a;
		array = true;
		kind = ArrayWithSize;
	}

	void specifyFunction( ParameterTypeListNode* a )
	{
		funcParams = a;
		functionDefinition = true; // TODO is this right?
		kind = FunctionDefinitionWithParam;
	}

	void specifyFunctionCall( IdentifierListNode* a )
	{
		functionCall = true;
		idListNode = a;	
		kind = FunctionCallWithParam;
	}

	int getKind()
	{
		return kind;
	}
	
	IdentifierNode* id;
	DeclaratorNode* declNode;		
	DirectDeclaratorNode* dirDeclNode;
	IdentifierListNode* idListNode;
	ConstantExpressionNode* arraySize;
	ParameterTypeListNode* funcParams;

private:

	int kind;

	bool array;
	bool functionCall;
	bool functionDefinition; // declaration?
};

class DeclaratorNode {
public:

	DeclaratorNode(DirectDeclaratorNode* dirDeclNode) 
		: dirDeclNode(dirDeclNode), ptrNode(NULL)
	{}

	DeclaratorNode(PointerNode* ptrNode, DirectDeclaratorNode* dirDeclNode) 
		: dirDeclNode(dirDeclNode), ptrNode(ptrNode)
	{}

	bool isPointer()
	{
		return (ptrNode!=NULL);
	}

	string toString()
	{
		return dirDeclNode->toString();
	}

	DirectDeclaratorNode* dirDeclNode;
	PointerNode* ptrNode;
};

class InitDeclaratorNode {
public:

	InitDeclaratorNode() {}

	InitDeclaratorNode(DeclaratorNode* declNode) 
		: declNode(declNode)
	{}

	InitDeclaratorNode(DeclaratorNode* declNode, InitializerNode* initNode) 
		: declNode(declNode), initNode(initNode)
	{}

	string toString()
	{
		string s = "InitDeclaratorNode: " + declNode->toString();
		return s;
	}

	DeclaratorNode* declNode;
	InitializerNode* initNode;
};

class StructDeclarationNode {
};

class SpecifierQualifierListNode {
};

class StructDeclaratorListNode {
};

class StructDeclaratorNode {
};

class EnumSpecifierNode {
};

class EnumeratorListNode {
};

class EnumeratorNode {
};
class PointerNode {

};

class TypeQualifierListNode {
};

class ParameterTypeListNode {
};

class ParameterListNode {
};

class ParameterDeclarationNode {
};

class IdentifierListNode {
};



class InitializerNode {
public:

	InitializerNode() {}

	InitializerNode(AssignmentExpressionNode* assignExprNode) 
		: assignExprNode(assignExprNode)
	{}

	InitializerNode(InitializerListNode* initListNode)
		: initListNode( initListNode )
	{}
			

private:
	AssignmentExpressionNode* assignExprNode;
	InitializerListNode* initListNode;
};

class InitializerListNode {
public:

	InitializerListNode(InitializerNode* initNode)
	{
		initializerList.push_back(initNode);
	}

	InitializerListNode(InitializerNode* initNode, InitializerListNode* initListNode)
	{
		initializerList.push_back(initNode);
		for (size_t i = 0; i <initListNode->initializerList.size(); i++ )	{
			initializerList.push_back( initListNode->initializerList[i] );
		}
	}

	size_t size() { return initializerList.size(); };

	std::vector<InitializerNode*> initializerList;
};

class AbstractDeclaratorNode {
};

class DirectAbstractDeclaratorNode {
};

class DeclarationNode : public Node {
public:


	DeclarationNode() {}	

	// -----------------------------------------------------------------------
	
	DeclarationNode(DeclarationSpecifiersNode* declSpecifier)
		: declSpecifier(declSpecifier)
	{}

	DeclarationNode(DeclarationSpecifiersNode* declSpecifier, InitDeclaratorListNode* initDeclList)
		: declSpecifier(declSpecifier), initDeclList(initDeclList)
	{}

	// -----------------------------------------------------------------------
	
	// TODO
	virtual std::vector< Operation* >* toOperations();

	virtual std::string getNodeTypeAsString();

	void error(std::string msg);

	void declare(SymbolTable* stab) ;

	Type* buildType(DeclarationSpecifiersNode::TypeInfo tInfo) const;

	std::string toString() const;

private:
	InitDeclaratorListNode* initDeclList;		
	DeclarationSpecifiersNode* declSpecifier;
};


//  -----------------------------------------------------------------------------
//
//  Fake Expression to cope with a ton of expressions
//

/*
class Expression {
public:
	Expression(Expression* exp) 
		: exp1(exp) 
	{
		initData();
	}

	Expression(Expression* exp1, Expression* exp2) 
		: exp1(exp1), exp2(exp2)
	{
		initData();
	}

	void initData()
	{
		exp1 = exp2 = NULL;	
	}

private:
	typedef std::string ExpressionKind; // temporary
	ExpressionKind kind;	
	Expression* exp1;
	Expression* exp2;
};
*/

#endif /* ASTNODES_H_ */
