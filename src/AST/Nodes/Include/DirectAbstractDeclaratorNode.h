#ifndef DirectAbstractDeclaratorNode_H_GUARD
#define DirectAbstractDeclaratorNode_H_GUARD

#include "AllASTNodes.h"

#include "AbstractDeclaratorNode.h"
#include "ParameterTypeListNode.h"
#include "ConstantExpressionNode.h"
#include "DirectAbstractDeclaratorNode.h"
#include "ParameterTypeListNode.h"

class AbstractDeclaratorNode;
class ParameterTypeListNode;
class ConstantExpressionNode;
class DirectAbstractDeclaratorNode;

class DirectAbstractDeclaratorNode {
public:

	enum ParenType {
		Square, Normal, None
	};

	// typedef int ParenType;

	DirectAbstractDeclaratorNode( AbstractDeclaratorNode* ad) // '(' abstract_declarator ')' 
		: ad(ad), dad(0), ce(0), ptl(0), ptype(None)
	{}
	DirectAbstractDeclaratorNode( /*ParenType*/ int ptype ) // '[' ']' and '(' ')' 
		: ad(0), dad(0), ce(0), ptl(0), ptype(ptype)
	{}
	DirectAbstractDeclaratorNode( ConstantExpressionNode* ce )// '[' constant_expression ']' 
		: ad(0), dad(0), ce(ce), ptl(0), ptype(None)
	{}
	DirectAbstractDeclaratorNode( DirectAbstractDeclaratorNode* dad, /*ParenType*/ int  ptype) // direct_abstract_declarator '[' ']'  and '(' ')' 
		: ad(0), dad(dad), ce(0), ptl(0), ptype(None)
	{}
	DirectAbstractDeclaratorNode( DirectAbstractDeclaratorNode* dad, ConstantExpressionNode* ce ) // direct_abstract_declarator '[' constant_expression ']' 
		: ad(0), dad(dad), ce(ce), ptl(0), ptype(None)
	{}
	DirectAbstractDeclaratorNode( ParameterTypeListNode* ptl ) // '(' parameter_type_list ')' 
		: ad(0), dad(0), ce(0), ptl(ptl), ptype(None)
	{}
	DirectAbstractDeclaratorNode( DirectAbstractDeclaratorNode* dad, ParameterTypeListNode* ptl ) // direct_abstract_declarator '(' parameter_type_list ')' 
		: ad(0), dad(dad), ce(0), ptl(ptl), ptype(None)
	{}

	AbstractDeclaratorNode* ad;
	DirectAbstractDeclaratorNode* dad;
	ConstantExpressionNode* ce;
	ParameterTypeListNode* ptl;

	/*ParenType*/ int ptype;
};

#endif // END DirectAbstractDeclaratorNode_H_GUARD

