#ifndef SpecifierQualifierListNode_H_GUARD
#define SpecifierQualifierListNode_H_GUARD

class SpecifierQualifierListNode {
public:

	SpecifierQualifierListNode( TypeSpecifierNode* ts )
		: typeSpecifier(ts), typeQualifier(NULL), specifierQualifierList(NULL)
	{}

	SpecifierQualifierListNode( TypeSpecifierNode* ts, SpecifierQualifierListNode* sql )
		: typeSpecifier(ts), specifierQualifierList(sql)
	{}

	SpecifierQualifierListNode( TypeQualifierNode* tq )
		: typeSpecifier(NULL), typeQualifier(tq), specifierQualifierList(NULL)
	{}

	SpecifierQualifierListNode( TypeQualifierNode* tq, SpecifierQualifierListNode* sql )
		: typeQualifier(tq), specifierQualifierList(sql)
	{}

	bool isLast() ;

	TypeSpecifierNode* typeSpecifier;
	TypeQualifierNode* typeQualifier;
	SpecifierQualifierListNode* specifierQualifierList;	
};

#endif // END SpecifierQualifierListNode_H_GUARD

