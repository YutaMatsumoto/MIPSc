/*
 * Type.h
 *
 *  Created on: Mar 13, 2013
 *      Author: njordan
 */

#include <string>

#ifndef TYPE_H_
#define TYPE_H_

class Type
{
	public:

	Type( std::string , int , int );

	std::string getId();

	virtual ~Type();

	protected:

	std::string id;

	int lineNumber;

	int columnNumber;
};

#endif /* TYPE_H_ */
