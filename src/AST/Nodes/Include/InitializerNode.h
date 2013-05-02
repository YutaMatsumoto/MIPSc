#ifndef InitializerNode_H_GUARD
#define InitializerNode_H_GUARD

#include "AllASTNodes.h"
#include "InitializerListNode.h"

class AssignmentExpressionNode;
class InitializerListNode;

class InitializerNode : public Node {
public:

	InitializerNode(AssignmentExpressionNode* assignmentExpression);

	InitializerNode(InitializerListNode* initListNode);
			
	ASTData* toOperations();
	std::string getNodeTypeAsString();

private:
	AssignmentExpressionNode* assignmentExpression;
	InitializerListNode* initializerList;
};


#endif // END InitializerNode_H_GUARD
