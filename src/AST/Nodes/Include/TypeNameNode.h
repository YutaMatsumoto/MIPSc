#ifndef TypeNameNode_H_GUARD
#define TypeNameNode_H_GUARD

#include "AllASTNodes.h"

class SpecifierQualifierListNode;
class AbstractDeclaratorNode;

class TypeNameNode {
public:

	TypeNameNode( SpecifierQualifierListNode* sql )
		: sql(sql), ad(NULL)
	{}

	TypeNameNode( SpecifierQualifierListNode* sql,  AbstractDeclaratorNode* ad )
		: sql(sql), ad(ad)
	{}

	SpecifierQualifierListNode* sql;
	AbstractDeclaratorNode* ad;
};


#endif // END TypeNameNode_H_GUARD

