#include "ParameterDeclarationNode.h"
#include "TypeInfo.h"

TypeInfo ParameterDeclarationNode::getType()
{
	return ds->getTypeInfo();
}

