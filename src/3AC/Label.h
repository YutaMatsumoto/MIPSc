/*
 * Label.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef LABEL_H_
#define LABEL_H_

#include "Operation.h"

class Label: public Operation {

public:

	inline Label( std::string label )
	{

		name = label;

	}

	inline std::string to3AC()
	{

		return label + std::string(": ")

	}

};

#endif /* LABEL_H_ */
