/*
 * Operation.h
 *
 *  Created on: Apr 3, 2013
 *      Author: njordan
 */

#ifndef OPERATION_H_
#define OPERATION_H_

#include <string>
#include "Symbol.h"

typedef Symbol Operand;
typedef Symbol Temporary;

class Operation
{

public:

	virtual ~Operation();

	virtual std::string to3AC() = 0;

protected:

	std::string name;

	Operation();

};

#endif /* OPERATION_H_ */
