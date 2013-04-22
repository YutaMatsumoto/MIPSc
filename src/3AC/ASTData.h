/*
 * ASTData.h
 *
 *  Created on: Apr 16, 2013
 *      Author: njordan
 */

#ifndef ASTDATA_H_
#define ASTDATA_H_

#include "Symbol.h"
#include "Label.h"
#include <vector>

class ASTData {

public:

	ASTData();

	Symbol* result;

	std::vector< Operation* >* code;

	Label* before;

	Label* after;

};

#endif /* ASTDATA_H_ */
