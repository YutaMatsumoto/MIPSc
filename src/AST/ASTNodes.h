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
#include "TypeSpecifierNode.h"

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
class TypeNameNode;
class AbstractDeclaratorNode;
class DirectAbstractDeclaratorNode;

class ConstantExpressionNode;



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
public:

	enum TypeQual { Const, Volatile };
	
	TypeQualifierNode(int tqual )
		: tqual(tqual)
	{}

	int /*TypeQual*/ tqual;
};

// Maybe
class StructOrUnionSpecifierNode {
};

// Maybe
class StructOrUnionNode {
};

// Maybe
class StructDeclarationListNode {
};



class SpecifierQualifierListNode {
public:

	SpecifierQualifierListNode( TypeSpecifierNode* ts )
		: typeSpecifier(ts), typeQualifier(NULL), specifierQualifierList(NULL)
	{}

	SpecifierQualifierListNode( TypeSpecifierNode* ts, SpecifierQualifierListNode* sql )
		: typeSpecifier(ts), specifierQualifierList(sql)
	{}

	SpecifierQualifierListNode( TypeQualifierNode* tq )
		: typeSpecifier(NULL), typeQualifier(tq), specifierQualifierList(NULL)
	{}

	SpecifierQualifierListNode( TypeQualifierNode* tq, SpecifierQualifierListNode* sql )
		: typeQualifier(tq), specifierQualifierList(sql)
	{}

	bool isLast() { return specifierQualifierList == NULL; }

	TypeSpecifierNode* typeSpecifier;
	TypeQualifierNode* typeQualifier;
	SpecifierQualifierListNode* specifierQualifierList;	
};

// Maybe
class StructDeclaratorListNode {
};

// Maybe
class StructDeclaratorNode {
};

// Maybe
class EnumSpecifierNode {
};

// Maybe
class EnumeratorListNode {
};

// Maybe
class EnumeratorNode {
};

class PointerNode {
public:

	PointerNode()
		: p(NULL), tql(NULL)
	{}
		
	PointerNode( TypeQualifierListNode* tql )
		: p(NULL), tql(tql)
	{}

	PointerNode( PointerNode* p )
		: p(p), tql(NULL)
	{}

	PointerNode( TypeQualifierListNode* tql,  PointerNode* p)
		: p(p), tql(tql)
	{}

	PointerNode* p;
	TypeQualifierListNode* tql;
};

class TypeQualifierListNode {
public:

	TypeQualifierListNode(TypeQualifierNode* tq)
	{
		tqlist.push_back(tq);	
	}

	TypeQualifierListNode(TypeQualifierListNode* tql, TypeQualifierNode* tq)
		: tqlist(tql->tqlist)
	{	
		tqlist.push_back(tq);
	}

	std::vector<TypeQualifierNode*>	tqlist;

};

class ParameterTypeListNode {
public:

	ParameterTypeListNode(ParameterListNode* pl)
		: pl(pl), ellipsis(false)
	{}

	void setVariableArgumentList()	
	{
		ellipsis = true;
	}

	ParameterListNode* pl;
	bool ellipsis;
};

class ParameterListNode {
public:

	ParameterListNode( ParameterDeclarationNode* pd)
		: pd(pd), pl(NULL)
	{}

	ParameterListNode( ParameterListNode* pl, ParameterDeclarationNode* pd)
		: pd(pd), pl(pl)
	{}

	ParameterDeclarationNode* pd;
	ParameterListNode* pl;

};

class ParameterDeclarationNode {
public:
	ParameterDeclarationNode( DeclarationSpecifiersNode* ds,  DeclaratorNode* d)
		: ds(ds), d(d), ad(NULL)
	{}

	ParameterDeclarationNode( DeclarationSpecifiersNode* ds )
		: ds(ds), d(NULL), ad(NULL)
	{}

	ParameterDeclarationNode( DeclarationSpecifiersNode* ds, AbstractDeclaratorNode* ad)
		: ds(ds), d(NULL), ad(ad)
	{}

	DeclarationSpecifiersNode* ds;  
	DeclaratorNode* d;
	AbstractDeclaratorNode* ad;
};

class IdentifierListNode {
public:

	IdentifierListNode( IdentifierNode* i )
		: i(i), il(NULL)
	{}

	IdentifierListNode( IdentifierListNode* il,  IdentifierNode* i)
		: i(i), il(il)
	{}

	IdentifierNode* i;
	IdentifierListNode* il;
};

class TypeNameNode {
public:
	TypeNameNode( SpecifierQualifierListNode* sql )
		: sql(sql), ad(NULL)
	{}

	TypeNameNode( SpecifierQualifierListNode* sql,  AbstractDeclaratorNode* ad )
		: sql(sql), ad(ad)
	{}

	SpecifierQualifierListNode* sql;
	AbstractDeclaratorNode* ad;
};

class AbstractDeclaratorNode {
public:

	AbstractDeclaratorNode( PointerNode* p )
		: p(p), dad(NULL)
	{}

	AbstractDeclaratorNode( DirectAbstractDeclaratorNode * dad )
		: p(NULL), dad(dad)
	{}

	AbstractDeclaratorNode( PointerNode* p,  DirectAbstractDeclaratorNode* dad)
		: p(p), dad(dad)
	{}

	PointerNode* p;
	DirectAbstractDeclaratorNode* dad;
};

class DirectAbstractDeclaratorNode {
public:

	enum ParenType {
		Square, Normal, None
	};

	// typedef int ParenType;

	DirectAbstractDeclaratorNode( AbstractDeclaratorNode* ad) // '(' abstract_declarator ')' 
		: ad(ad), dad(NULL), ce(NULL), ptl(NULL), ptype(None)
	{}
	DirectAbstractDeclaratorNode( /*ParenType*/ int ptype ) // '[' ']' and '(' ')' 
		: ad(NULL), dad(NULL), ce(NULL), ptl(NULL), ptype(ptype)
	{}
	DirectAbstractDeclaratorNode( ConstantExpressionNode* ce )// '[' constant_expression ']' 
		: ad(NULL), dad(NULL), ce(ce), ptl(NULL), ptype(None)
	{}
	DirectAbstractDeclaratorNode( DirectAbstractDeclaratorNode* dad, /*ParenType*/ int  ptype) // direct_abstract_declarator '[' ']'  and '(' ')' 
		: ad(NULL), dad(dad), ce(NULL), ptl(NULL), ptype(None)
	{}
	DirectAbstractDeclaratorNode( DirectAbstractDeclaratorNode* dad, ConstantExpressionNode* ce ) // direct_abstract_declarator '[' constant_expression ']' 
		: ad(NULL), dad(dad), ce(ce), ptl(NULL), ptype(None)
	{}
	DirectAbstractDeclaratorNode( ParameterTypeListNode* ptl ) // '(' parameter_type_list ')' 
		: ad(NULL), dad(NULL), ce(NULL), ptl(ptl), ptype(None)
	{}
	DirectAbstractDeclaratorNode( DirectAbstractDeclaratorNode* dad, ParameterTypeListNode* ptl ) // direct_abstract_declarator '(' parameter_type_list ')' 
		: ad(NULL), dad(dad), ce(NULL), ptl(ptl), ptype(None)
	{}

	AbstractDeclaratorNode* ad;
	DirectAbstractDeclaratorNode* dad;
	ConstantExpressionNode* ce;
	ParameterTypeListNode* ptl;

	/*ParenType*/ int ptype;
};

#endif /* ASTNODES_H_ */
