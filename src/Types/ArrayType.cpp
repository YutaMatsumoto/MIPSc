#include "ArrayType.h"

int ArrayType::sizeInBytes()
{
	int total = 0;

	for( int i : sizes )
	{

		//asuming int, right now elementType->sizeInBytes() returning -1...
		total += i * 4;

		//total += i * elementType->sizeInBytes();

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
