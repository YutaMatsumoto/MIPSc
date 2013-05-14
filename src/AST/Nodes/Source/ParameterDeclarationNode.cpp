#include "ParameterDeclarationNode.h"
#include "TypeInfo.h"
#include "ArrayType.h"
#include "BuiltinType.h"

TypeInfo ParameterDeclarationNode::getType()
{
	return ds->getTypeInfo();
}

ParameterDeclarationNode::ParameterDeclarationNode( DeclarationSpecifiersNode* ds,  DeclaratorNode* d,
		SymbolTable* stab
)
		: ds(ds), d(d)
{
	declare(stab);

	nodeData = toOperations();
}

ParameterDeclarationNode::ParameterDeclarationNode( DeclarationSpecifiersNode* ds,
		SymbolTable* stab )
	: ds(ds)
{
	declare(stab);

	nodeData = toOperations();
}

ParameterDeclarationNode::ParameterDeclarationNode( DeclarationSpecifiersNode* ds, AbstractDeclaratorNode* ad,
		SymbolTable* stab)
	: ds(ds), ad(ad)
{
	declare(stab);
	nodeData = toOperations();
}

ASTData* ParameterDeclarationNode::toOperations()
{
	ASTData* data = new ASTData();



	return data;
}

std::string ParameterDeclarationNode::getNodeTypeAsString()
{

	return std::string("");

}

void ParameterDeclarationNode::declare(SymbolTable* stab)
{

	Type* t = 0;
	Symbol* s = 0;
	SymbolLocation sloc;
	std::string id;

	SymbolTableInfo info;
	// seg fault here since some of these are mutually exlusive pointers
	// auto init = initDecl->initNode;
	auto dirDecl = d->dirDeclNode;
	auto dirDeclId = dirDecl->id;
	// auto ptr     = decl->ptrNode;

	int dKind = dirDecl->getKind();

	//This will need to change to ref if we get an ampersand
	Symbol::TACOperandType tacType = Symbol::VALARG;

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
				t = new ArrayType( dirDecl->nodeData->value , new BuiltinType( Type::Int ) );

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

}

