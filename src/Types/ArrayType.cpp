#include "ArrayType.h"

int ArrayType::sizeInBytes()
{
	int total = 0;

	for( int i : sizes )
	{

		total += i * elementType->sizeInBytes();

	}

	return total;

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
