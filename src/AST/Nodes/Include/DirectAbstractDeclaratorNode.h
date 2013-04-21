#ifndef DirectAbstractDeclaratorNode_H_GUARD
#define DirectAbstractDeclaratorNode_H_GUARD

#include "AllASTNodes.h"

#include "AbstractDeclaratorNode.h"
#include "ParameterTypeListNode.h"

class AbstractDeclaratorNode;
class ParameterTypeListNode;

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

#endif // END DirectAbstractDeclaratorNode_H_GUARD

