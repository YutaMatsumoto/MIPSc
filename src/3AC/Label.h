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

	inline Label( std::string _name , unsigned int _id ) : Operation(0,0,0)
	{

		name = _name + std::to_string( _id );

		id = _id;

	}

	virtual void produceMips()
	{

		MipsCode::getInstance().writeToTextSection(
			getName()+":", "from Label Operation"
		);

	}

	inline std::string to3AC()
	{

		return std::string("\n") + name + std::string(": ");

	}

protected:

	unsigned int id;

};

#endif /* LABEL_H_ */
