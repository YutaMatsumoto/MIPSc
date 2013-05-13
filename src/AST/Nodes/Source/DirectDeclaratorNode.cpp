#include "DirectDeclaratorNode.h"

#include "AllASTNodes.h"

#include "ArrayType.h"
#include "FunctionType.h"

// ---------------------------------------------------------------------------
// Constructors


DirectDeclaratorNode::DirectDeclaratorNode( DeclaratorNode* declaratorNode ) : declNode(declaratorNode)
{
	initData();

	nodeData = toOperations();
}


DirectDeclaratorNode::DirectDeclaratorNode( DirectDeclaratorNode* a, DirectDeclaratorNode::DirectDeclaratorKind _kind )
{
	initData();
	dirDeclNode = a;
	kind = _kind;
	nodeData = toOperations();
}

DirectDeclaratorNode::DirectDeclaratorNode( IdentifierNode* id )
{
	initData();
	this->id = id;
	kind = Id;
	nodeData = toOperations();
}

DirectDeclaratorNode::DirectDeclaratorNode( DirectDeclaratorNode* a, ParameterTypeListNode* _p )
{
	dirDeclNode = a;
	funcParams = _p;
	nodeData = toOperations();

}

DirectDeclaratorNode::DirectDeclaratorNode( DirectDeclaratorNode* _directDeclarator , ConstantExpressionNode* _constantExpression )
: dirDeclNode( _directDeclarator ) , arraySize( _constantExpression )
{
	kind = ArrayWithSize;
	nodeData = toOperations();
}


void DirectDeclaratorNode::initData()
{
	// array = false;
	// functionCall = false;
	// functionDefinition = false;

	kind = None;

	id = NULL;
	dirDeclNode = NULL;
	declNode = NULL;
	idListNode = NULL;
	arraySize = NULL;
	funcParams = NULL;
}

// ---------------------------------------------------------------------------
// Declarations

Symbol* DirectDeclaratorNode::declare(Type* type , SymbolTable* _stab )
{
	// For returning symbol
	SymbolLocation sloc;
	std::string symId;
	Type* returnType = NULL; // ArrayType* , FunctionType* or BuiltinType*

	//
	// Build type
	//
	// Regardless of DirectDeclaratorKind, the botttom of DirectDeclaratorNode
	// must be identifier. 
	//
	// 3 possible Types : Array, Function  Definition, or primitive type
	//
	DirectDeclaratorNode* ddn = this;
	while ( ddn->id == NULL ) {
		// Array
		if (ddn->kind == Array || ddn->kind == ArrayWithSize) {
			if (!returnType) 
				returnType = new ArrayType(arraySize, type);
			else
				( (ArrayType*) returnType )->addDimension(arraySize);
		}
		// Function Definition
		// TODO
		else if (ddn->kind == FunctionDefinition || ddn->kind == FunctionDefinitionWithParam) { 
			returnType = (FunctionType*) new FunctionType();
			// TODO : type not known at this point
			//
			// Function Declaration with Identifiers with parameter types outside of parentheses
			if (idListNode)	 {
			/*
				( (FunctionType*) returnType )->setReturnType(type);
				for (auto id : idListNode ) {
					( (FunctionType*) returnType )->add(id);
				}
			*/
			}
			// Function Declaration with paremeter types and identifiers inside of parentheses
			// TODO function return type
			else if (funcParams) {
				for (auto type : funcParams->typeList() ) {
					( (FunctionType*)returnType	)->addOperand(type);
				}
			}
			break;
		}
		ddn = ddn->dirDeclNode;
	}

	//
	// Now Bottom of DirectDeclarator 
	//
	// primitive type
	if (!returnType) 
		returnType = type;	
	// array
	else if (returnType->getType() == Type::Array)
		; // TODO check array dimenstion
	// function
	else if (returnType->getType() == Type::Function)
		;
	else
		;


	// Get Id of the symbol
	IdentifierNode* id = ddn->id;
	if (id)
		symId = id->getId();
	else {
		std::cerr << "Declration : id not found" << std::endl;
	}

	Symbol::TACOperandType tacType = ( _stab->isGlobalScope() ) ? Symbol::GLOB : Symbol::LOCAL;

	return new Symbol(symId, sloc, returnType, tacType );
}

// ---------------------------------------------------------------------------

ASTData* DirectDeclaratorNode::toOperations()
{

	ASTData* data = new ASTData();

	if( id )
	{

		data->result = id->resolveSymbol();

		data->code = id->nodeData->code;

		return data;

	}

	if( declNode )

		return declNode->nodeData;

	if( dirDeclNode && arraySize )
	{

		data->result = dirDeclNode->nodeData->result;

		return data;

	}

	if( dirDeclNode && funcParams )
	{

		data->result = dirDeclNode->nodeData->result;

		return data;

	}

	if( dirDeclNode && kind == FunctionCall )
	{

		data->result = dirDeclNode->nodeData->result;

		return data;

	}
}

std::string getNodeTypeAsString()
{
	return std::string("DirectDeclaratorNode");
}

// ---------------------------------------------------------------------------

string DirectDeclaratorNode::toString()
{
	if (id) {
		return id->getId();
	}
	else if (dirDeclNode){
		return dirDeclNode->toString();
	}
	else {
		error("both of id and dirDeclNode is null");
		return "bad DirectDeclaratorNode";
	}
}

void DirectDeclaratorNode::error(string msg)
{
	cerr << "Error : DirectDeclaratorKind : " << msg << endl;
}

int DirectDeclaratorNode::getKind()
{
	return kind;
}

bool DirectDeclaratorNode::hasIdentifier()
{
	return (id!=NULL);
}

std::string DirectDeclaratorNode::getNodeTypeAsString()
{
	return std::string("initializer list node");
}
