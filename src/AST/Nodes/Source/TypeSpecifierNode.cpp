#include "AllASTNodes.h"

#include "TypeSpecifierNode.h"

// static function
std::string TypeSpecifierNode::integralToString(int integral)
{
	if (integral==Void) 
		return "void";
	else if (integral==Char) 
		return "char";
	else if (integral==Short) 
		return "short";
	else if (integral==Int) 
		return "int";
	else if (integral==Long) 
		return "long";
	else if (integral==Float) 
		return "float";
	else if (integral==Double) 
		return "double";
	else if (integral==Signed) 
		return "signed";
	else if (integral==Unsigned) 
		return "unsigned";
	else if (integral==Struct) 
		return "struct";
	else if (integral==Union) 
		return "union";
	else if (integral==Enum) 
		return "enum";
	else if (integral==Typedef) 
		return "typedef";
	else
		return "invalid type";
}

ASTData* TypeSpecifierNode::toOperations()
{
	ASTData* data = new ASTData();

	return data;
}

std::string TypeSpecifierNode::getNodeTypeAsString()
{
	return "TypeSpecifier";
}

/*
TypeSpecifierNode::TypeSpecifierNode(std::string type) 
{
	initData();

	// std::cerr << "addTypeSpecifier(string): TODO" << std::endl;
	bool success = false;
	for (size_t spec = 0 ; spec<specs_size ; spec++) {
		if ( specs[ spec ] == type ) {
			success = true;
			this->specifier = (TypeSpecifierEnum) spec ;
			break;
		}
	}

	// error
	if ( ! success ) {
		error("TypeSpecifier is invalid. <" + type + "> given.");
	}
}	
*/

TypeSpecifierNode::TypeSpecifierNode(size_t specifier)
{
	initData();
	bool success = false;
	for ( size_t spec = TypeSpecifierStart ; spec < TypeSpecifierEnd; spec++ ) {
		if (specifier == spec) {
			success = true;
			this->specifier = (TypeSpecifierEnum) spec;
			break;
		}
	}
	// Error
	if ( ! success ) {
		std::string s( std::to_string( specifier ) );
		if ( specifier < specs_size ) {
			s = s + " " + integralToString( specifier );
		}
		error("TypeSpecifier is invalid. <" + s + "> given.");
	}
}

void TypeSpecifierNode::initData()
{
	// specs.push_back( "void" );
	// specs.push_back( "char" );
	// specs.push_back( "short" );
	// specs.push_back( "int" );
	// specs.push_back( "long" );
	// specs.push_back( "float" );
	// specs.push_back( "double" );
	// specs.push_back( "signed" );
	// specs.push_back( "unsigned" );
	// specs.push_back( "struct" );
	// specs.push_back( "union" );
	// specs.push_back( "enum" );
	// specs.push_back( "typedef");
	specs_size = 13;
}

bool TypeSpecifierNode::isIntegral()
{
	// std::cout << "isIntegral() : "  << toString() << " : ";
	for ( size_t integral = IntegralStart ; integral<IntegralEnd ; integral++ ) {
		if ( specifier == integral ) {
			// std::cout << " true  " << std::endl;
			return true;
		}
	}
	// std::cout << " false " << std::endl;
	return false;
}

int TypeSpecifierNode::getTypeSpecifier()
{
	return specifier;
}

std::string TypeSpecifierNode::toString()
{	
	for (size_t spec = TypeSpecifierStart; spec < TypeSpecifierEnd; spec++ ) {
		if ( specifier == spec ) {
			return integralToString( spec );
		}
	}
	return "";
}

void TypeSpecifierNode::error(std::string error) 
{
	std::cout << "TypeSpecifier Error : " << error << std::endl;
}
