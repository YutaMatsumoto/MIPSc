#include "ASTNodes.h"

ASTData* DeclarationNode::toOperations()
{
	ASTData* data = new ASTData();

	if( initDeclList != 0 )

		return initDeclList->toOperations();

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

	DeclarationSpecifiersNode::TypeInfo tInfo = declSpecifier->getTypeInfo();	
	// std::cout << "InideDeclList.size() : " << initDeclList->declaratorList.size()<< std::endl; // debug

	InitDeclaratorListNode* list = initDeclList;

	while( list != 0 ) {

		Type* t;
		Symbol* s;
		SymbolLocation sloc;

		// seg fault here since some of these are mutually exlusive pointers
		auto decl = list->initDeclarator->declarationNode;
		// auto init = initDecl->initNode;
		auto dirDecl = decl->dirDeclNode;
		auto dirDeclId = dirDecl->id;
		// auto ptr     = decl->ptrNode;

		int dKind = dirDecl->getKind() ;

		std::string id;

		// TODO SymbolLocation
		// std::cout << "dKind" << dKind << std::endl;
		switch(dKind) {
			case DirectDeclaratorNode::None: 
				t = buildType(tInfo);
				id = dirDeclId->getId();
				s = new Symbol(id, sloc, t);
				cout << "declre() : before insertSymbol" << endl;
				stab->insertSymbol(s);
				cout << "declre() : after insertSymbol" << endl;
				break;
			case DirectDeclaratorNode::Array: 
				break;
			case DirectDeclaratorNode::ArrayWithSize: 
				break;
			case DirectDeclaratorNode::FunctionDefinition: 
				break;
			case DirectDeclaratorNode::FunctionDefinitionWithParam: 
				break;
			// TODO: These two should not reduce to declaration node ?
			case DirectDeclaratorNode::FunctionCall: 
				break;
			case DirectDeclaratorNode::FunctionCallWithParam:
				break;
		}

		list = initDeclList->initDeclaratorList;

	}

}

Type* DeclarationNode::buildType(DeclarationSpecifiersNode::TypeInfo tInfo) const
{
	Type* type = NULL;

	bool unsignedSpecified = tInfo.unsignedSpecified;
	int  integral = tInfo.integral;
	bool longSpecified = tInfo.longLongSpecified;
	bool longLongSpecified = tInfo.longLongSpecified;

	if (unsignedSpecified) {
		if (integral==Char) 
			type = new BuiltinType<char>(Type::uChar);
		else if (integral==Short)
			type = new BuiltinType<short>(Type::uShort);
		else if (integral==Int)
			type = new BuiltinType<int>(Type::uInt);
		else if (longLongSpecified)
			type = new BuiltinType<unsigned long long>(Type::uLongLong);
		else if (longSpecified)
			type = new BuiltinType<unsigned long>(Type::uLong);
	}
	else {
		if (integral==Int) {
			if (longLongSpecified)
				type = new BuiltinType<long long>(Type::Long);
			else if (longSpecified)
				type = new BuiltinType<long>(Type::Long);
			else
				type = new BuiltinType<int>(Type::Int);
		}
		else {
			if (integral==Char)
				type = new BuiltinType<char>(Type::Char);
			else if (Short)
				type = new BuiltinType<short>(Type::Short);
			else if (integral==Float)
				type = new BuiltinType<float>(Type::Float);
			else if (integral==Double)
				type = new BuiltinType<double>(Type::Double);
		}
	}

	return type;
}

std::string DeclarationNode::toString() const
{
	std::string s="DeclarationNode: \n" ;
	DeclarationSpecifiersNode::TypeInfo t = declSpecifier->getTypeInfo();
	s+= "\t" + t.toString() + "\n";
	return s;
}
