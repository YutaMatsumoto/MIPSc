/*
 * Comment.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef COMMENT_H_
#define COMMENT_H_

#include "Operation.h"

#include <string>

class Comment: public Operation {

public:

	inline Comment( std::string _text ) : Operation(0,0,0)
	{

		name = _text;

	}

	inline std::string to3AC()
	{

		return "# " + name;

	}

};

#endif /* COMMENT_H_ */
