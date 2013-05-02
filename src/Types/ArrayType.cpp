#include "ArrayType.h"

int ArrayType::sizeInBytes()
/*
{
	return array.size() * getElementType()->sizeInBytes();
}
*/
{
	// return size->getSize()*elementType->sizeInBytes();
	cerr << "sizeInBytes() called but not implemented" << endl;
	return -1;
}

std::string ArrayType::getTypeAsString()
{
	return this->toString();
}

std::string ArrayType::toString()
{

	// std::cout << elementType->getType() << std::endl;

	return (!elementType) 
		? ( std::string( "array with bad element type(null pointer)") )
		: ( std::string( "array of " ) + elementType->toString() ) //+ size->getNodeTypeAsString();
		;

}
