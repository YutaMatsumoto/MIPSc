#ifndef AbstractDeclaratorNode_H_GUARD
#define AbstractDeclaratorNode_H_GUARD

#include "AllASTNodes.h"

#include "PointerNode.h"
#include "DirectAbstractDeclaratorNode.h"

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



#endif // END AbstractDeclaratorNode_H_GUARD

