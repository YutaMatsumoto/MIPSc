#include "AllASTNodes.h"

#include "ArrayType.h"
#include "TypeInfo.h"
#include "BuiltinType.h"

ASTData* DeclarationNode::toOperations()
{
	ASTData* data = new ASTData();

	return data;
}

std::string DeclarationNode::getNodeTypeAsString()
{
	return std::string( "DeclarationNode" );
}

void DeclarationNode::error(std::string msg)
{
	std::cerr << msg << std::endl;
	std::cerr << "Exiting ... " << std::endl;
	exit(1);
}

void DeclarationNode::declare(SymbolTable* stab) 
{
// BIG TODO
	std::vector<Symbol*> symList;

	if (!stab) {
		error("declare() : SymbolTable pointer supplied is null.");
	}

	// bool array = false;

	TypeInfo tInfo = declSpecifier->getTypeInfo();	
	Type* t = BuiltinType::buildType(tInfo);
	for (auto initDecl : initDeclList->declaratorList ) {

		// Symbol* s;
		SymbolLocation sloc;

		auto decl = initDecl->declNode;
		// auto init = initDecl->initNode;
		auto dirDecl = decl->dirDeclNode;
		// auto dirDeclId = dirDecl->id;
		// auto ptr     = decl->ptrNode;

		Symbol* sym = dirDecl->declare(t);

		// TODO
		//
		// At this point array/function/primitive type inside of sym
		// might have some unknown value such as 
		//
		//	array dimension not specified which must be inferred from
		//	number of items in initializer
		//
		//	Function return type
		//
		//	see DirectDeclaratorNode::declare(...)
		//

		stab->insertSymbol(sym);
	}

}


std::string DeclarationNode::toString() const
{
	std::string s="DeclarationNode: \n" ;
	TypeInfo t = declSpecifier->getTypeInfo();
	s+= "\t" + t.toString() + "\n";
	return s;
}

Symbol* DeclarationNode::buildArray(TypeInfo tInfo, DirectDeclaratorNode* dd)
{
	Symbol* sym;
	// std::string id = dd->id;
	return sym;
}
