#ifndef InitializerNode_H_GUARD
#define InitializerNode_H_GUARD

#include "AllASTNodes.h"
#include "InitializerListNode.h"

class InitializerListNode;

class InitializerNode {
public:

	InitializerNode() {}

	InitializerNode(AssignmentExpressionNode* assignmentExpression) 
		: assignmentExpression(assignmentExpression)
	{}

	InitializerNode(InitializerListNode* initListNode)
		: initListNode( initListNode )
	{}
			
	ASTData* toOperations();
	std::string getNodeTypeAsString();

private:
	AssignmentExpressionNode* assignmentExpression;
	InitializerListNode* initListNode;
};


#endif // END InitializerNode_H_GUARD
