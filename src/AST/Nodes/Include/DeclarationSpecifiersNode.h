#ifndef DeclarationSpecifiersNode_H_GUARD
#define DeclarationSpecifiersNode_H_GUARD

#include "TypeSpecifierNode.h"
#include "StorageClassSpecifierNode.h"
#include "TypeQualifierNode.h"

// #include "AllASTNodes.h"

#include <vector>

// TODO
struct StorageInfo {
};

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

	// -----------------------------------------------------------------------
	
	void debugPrint()
	{
		std::cout << "DeclarationSPecifierNode DebugPrint()" << std::endl;
		std::cout << tSpecs.size() << std::endl;
		std::cout << sSpecs.size() << std::endl;
		std::cout << qSpecs.size() << std::endl;
	}

	void error(std::string msg);

	TypeInfo getTypeInfo();

	StorageInfo getStorageInfo();

	TypeQualInfo getTypeQualInfo();

	
};

#endif // END DeclarationSpecifiersNode_H_GUARD

