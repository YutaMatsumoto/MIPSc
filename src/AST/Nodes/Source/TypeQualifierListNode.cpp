#include "TypeQualifierListNode.h"

TypeQualifierListNode::TypeQualifierListNode(TypeQualifierNode* tq)
{
	tqlist.push_back(tq);	
}

TypeQualifierListNode::TypeQualifierListNode(TypeQualifierListNode* tql, TypeQualifierNode* tq)
	: tqlist(tql->tqlist)
{	
	tqlist.push_back(tq);
}
