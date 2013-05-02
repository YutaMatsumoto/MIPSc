/*
 * BuiltinType.h
 *
 *  Created on: Mar 27, 2013
 *      Author: jordan
 */

#ifndef BUILTINTYPE_H_
#define BUILTINTYPE_H_

#include "Type.h"

class BuiltinType : public Type
{
public:

	static Type* buildType(TypeInfo tInfo);

	virtual ~BuiltinType();

	BuiltinType(Type::TypeEnum type);

	// BuiltinType(int type);
	
	virtual std::string getTypeAsString();

	virtual std::string toString();


	virtual int sizeInBytes();
};


#endif /* BUILTINTYPE_H_ */
