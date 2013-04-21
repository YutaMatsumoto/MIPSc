#ifndef DeclarationSpecifiersNode_H_GUARD
#define DeclarationSpecifiersNode_H_GUARD

#include "TypeSpecifierNode.h"
#include "StorageClassSpecifierNode.h"
#include "TypeQualifierNode.h"

// #include "AllASTNodes.h"

#include <vector>

class DeclarationSpecifiersNode {

	std::vector<TypeSpecifierNode*> tSpecs;
	std::vector<StorageClassSpecifierNode*> sSpecs;
	std::vector<TypeQualifierNode*> qSpecs;
	
public:

	DeclarationSpecifiersNode( StorageClassSpecifierNode* s );

	DeclarationSpecifiersNode( StorageClassSpecifierNode* s, DeclarationSpecifiersNode* ds );

	DeclarationSpecifiersNode( TypeSpecifierNode* ts  );

	DeclarationSpecifiersNode( TypeSpecifierNode* ts, DeclarationSpecifiersNode* ds );

	DeclarationSpecifiersNode( TypeQualifierNode* ts );

	DeclarationSpecifiersNode( TypeQualifierNode*tq, DeclarationSpecifiersNode* ds);


	void error(std::string msg);

	TypeInfo getTypeInfo();


	// TODO
	struct StorageInfo {
	};
	StorageInfo getStorageInfo();

	// TODO
	struct TypeQualInfo {
		bool constness;
		bool volatileness;
	};
	TypeQualInfo getTypeQualInfo();

	
};

#endif // END DeclarationSpecifiersNode_H_GUARD

