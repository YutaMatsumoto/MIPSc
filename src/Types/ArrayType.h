#ifndef ARRAYTYPE_H_
#define ARRAYTYPE_H_

#include "ConstantExpressionNode.h"

#include "Type.h"

class ArrayType : public Type {

public:

	// delete this 
	// ArrayType(ConstantExpressionNode* size, Type* elementType)
	// 	: size(size), elementType(elementType), Type(Type::Array)
	// {}

	ArrayType(int size, Type* elementType)
		: elementType(elementType), Type(Type::Array)
	{
		sizes.push_back(size);
	}

	void addDimension(int s)
	{
		sizes.push_back(s);			
	}

	Type* getElementType()
	{
		return elementType;
	}

	virtual int sizeInBytes();

	virtual std::string getTypeAsString();

	virtual std::string toString();

	// TODO : This should be array or size_t instead of ConstantExpressionNode
	// sizes of arrays
	// [0]    : size of the outermost array
	// [last] : size of the innermost dimension
	vector<int> sizes;

	Type* elementType;

};

#endif /* ARRAYTYPE_H_ */
