#include "common.h"
#include "AllASTNodes.h"

std::string InitDeclaratorNode::toString()
{
	string s = "InitDeclaratorNode: " + declNode->toString();
	return s;
}
