#ifndef InitializerNode_H_GUARD
#define InitializerNode_H_GUARD

#include "AllASTNodes.h"

#include "InitializerListNode.h"

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


#endif // END InitializerNode_H_GUARD

