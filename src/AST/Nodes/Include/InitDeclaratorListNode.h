#ifndef InitDeclaratorListNode_H_GUARD
#define InitDeclaratorListNode_H_GUARD

#include "AllASTNodes.h"
#include "InitDeclaratorNode.h"
#include <list>
#include <string>

class InitDeclaratorNode;

typedef std::list<InitDeclaratorNode*> InitDeclaratorNodeInList;

class InitDeclaratorListNode : public Node {
public:

	InitDeclaratorListNode( InitDeclaratorNode* n);

	InitDeclaratorListNode( InitDeclaratorListNode* a,  InitDeclaratorNode* b);

	ASTData* toOperations();

	std::string getNodeTypeAsString();

	InitDeclaratorNodeInList toList();

	void add(InitDeclaratorNode* initDecl) ;

	InitDeclaratorListNode* initDeclaratorList = 0;
	InitDeclaratorNode* initDeclarator = 0;
	
};

#endif // END InitDeclaratorListNode_H_GUARD
