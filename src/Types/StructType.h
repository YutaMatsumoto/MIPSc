/*
 * StructType.h
 *
 *  Created on: Mar 29, 2013
 *      Author: njordan
 */

#ifndef STRUCTTYPE_H_
#define STRUCTTYPE_H_

#include "Type.h"

#include <map>

class StructType: public Type {
public:

	StructType();

	virtual ~StructType();

	//string is symbol name, Symbol* is info/data about the struct member
	std::map< std::string , Symbol* > members;

};

#endif /* STRUCTTYPE_H_ */
