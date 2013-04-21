#include "AllASTNodes.h"

// #include "ParameterListNode.h"
// #include "DeclarationSpecifiersNode.h"

#include "TypeInfo.h"
#include "BuiltinType.h"


ParameterListNode::ParameterListNode( ParameterDeclarationNode* pd)
{
	plist.push_back(pd);
}

void ParameterListNode::add(ParameterDeclarationNode* pd)
{
	plist.push_back(pd);
}

ParameterListNode::TypeList ParameterListNode::getTypeList()
{
	TypeList tList;
	for ( auto p : plist ) {
		TypeInfo tInfo = p->getType();
		Type* type = BuiltinType::buildType(tInfo);
		tList.push_back(type);
	}
	return tList;
}
