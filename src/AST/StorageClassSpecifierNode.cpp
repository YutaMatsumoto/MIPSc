#include "ASTNodes.h"

StorageClassSpecifierNode::StorageClassSpecifierNode(int storageSpecKind ) 
{
	if ( StorageSpecifierKindStart  <= storageSpecKind && storageSpecKind <= StorageSpecifierKindEnd ) {
		specifier = storageSpecKind;
	}
	else {
		throw ParserError(ParserError::Whatever, "StorageClassSpecifierNode");
	}
}
