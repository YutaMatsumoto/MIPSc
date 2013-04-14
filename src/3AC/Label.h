/*
 * Label.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef LABEL_H_
#define LABEL_H_

#include "Operation.h"

#include <string>

class Label: public Operation {

public:

	inline Label( std::string _name , unsigned int _id )
	{

		name = _name + std::to_string( id );

		id = _id;

	}

	inline std::string to3AC()
	{

		return name + std::string(": ")

	}

protected:

	unsigned int id;

};

#endif /* LABEL_H_ */
