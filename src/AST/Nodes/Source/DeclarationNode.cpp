#include "DeclarationNode.h"

#include "TypeInfo.h"
#include "Symbol.h"
#include "ArrayType.h"
#include "BuiltinType.h"
#include "FunctionType.h"

DeclarationNode::DeclarationNode() {}

// -----------------------------------------------------------------------

DeclarationNode::DeclarationNode(DeclarationSpecifiersNode* declSpecifier)
	: declSpecifier(declSpecifier)
{
	nodeData = toOperations();
}

DeclarationNode::DeclarationNode(DeclarationSpecifiersNode* declSpecifier, InitDeclaratorListNode* initDeclList)
	: declSpecifier(declSpecifier), initDeclList(initDeclList)
{
	nodeData = toOperations();
}

ASTData* DeclarationNode::toOperations()
{
	ASTData* data = new ASTData();

	if( initDeclList != 0 )

		return initDeclList->nodeData;

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

	TypeInfo tInfo = declSpecifier->getTypeInfo();
	// std::cout << "InideDeclList.size() : " << initDeclList->declaratorList.size()<< std::endl; // debug

	InitDeclaratorListNode* list = initDeclList;

	while( list != 0 ) {

		Type* t = 0;
		Symbol* s = 0;
		SymbolLocation sloc;

		// seg fault here since some of these are mutually exlusive pointers
		auto decl = list->initDeclarator->declarationNode;
		// auto init = initDecl->initNode;
		auto dirDecl = decl->dirDeclNode;
		auto dirDeclId = dirDecl->id;
		// auto ptr     = decl->ptrNode;

		int dKind = dirDecl->getKind();

		std::string id;

		SymbolTableInfo info;

		Symbol::TACOperandType tacType = ( stab->isGlobalScope() ) ? Symbol::GLOB : Symbol::LOCAL;

		// TODO SymbolLocation
		// std::cout << "dKind" << dKind << std::endl;
		switch(dKind) {
			case DirectDeclaratorNode::Id:

				id = dirDecl->id->getId();

				info = stab->getSymbolInfo( id , true );

				if( info.symbol == 0 )

					std::cout << "Symbol Lookup was null" << endl;

				//This needs to be dynamic
				t = new BuiltinType( Type::Int );

				info.symbol->symbolType = t;

				info.symbol->operandType = tacType;

				break;
			case DirectDeclaratorNode::None: 
				//TODO: fix this ish
				//t = buildType(tInfo);
				id = dirDeclId->getId();

				info = stab->getSymbolInfo( id , true );

				if( info.symbol == 0 )

					std::cout << "Symbol Lookup was null" << endl;

				//This needs to be dynamic
				t = new BuiltinType( Type::Int );

				info.symbol->symbolType = t;

				info.symbol->operandType = tacType;

				//s = new Symbol(id, sloc, t);
				//cout << "declre() : before insertSymbol" << endl;
				//stab->insertSymbol(s);
				//cout << "declre() : after insertSymbol" << endl;
				break;
			case DirectDeclaratorNode::Array: 
				break;
			case DirectDeclaratorNode::ArrayWithSize: 

				id = dirDecl->dirDeclNode->id->getId();

				info = stab->getSymbolInfo( id , true );

				if( info.symbol == 0 )

					std::cout << "Symbol Lookup was null" << endl;

				// TODO Asuming int for now
				t = new ArrayType( decl->nodeData->value , new BuiltinType( Type::Int ) );

				info.symbol->symbolType = t;

				info.symbol->operandType = tacType;

				break;
			case DirectDeclaratorNode::FunctionDefinition: 

				id = dirDecl->dirDeclNode->id->getId();

				info = stab->getSymbolInfo( id , true );

				if( info.symbol == 0 )

					std::cout << "Symbol Lookup was null" << endl;

				// TODO Asuming int for now
				t = new FunctionType();

				info.symbol->symbolType = t;

				info.symbol->operandType = tacType;

				break;
			case DirectDeclaratorNode::FunctionDefinitionWithParam: 
				break;
			// TODO: These two should not reduce to declaration node ?
			case DirectDeclaratorNode::FunctionCall: 
				break;
			case DirectDeclaratorNode::FunctionCallWithParam:
				break;
		}

		list = list->initDeclaratorList;

	}

}

/*Type* DeclarationNode::buildType(DeclarationSpecifiersNode::TypeInfo tInfo) const
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
*/
std::string DeclarationNode::toString() const
{
	std::string s="DeclarationNode: \n" ;
	TypeInfo t = declSpecifier->getTypeInfo();
	s+= "\t" + t.toString() + "\n";
	return s;
}
