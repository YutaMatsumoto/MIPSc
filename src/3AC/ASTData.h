/*
 * ASTData.h
 *
 *  Created on: Apr 16, 2013
 *      Author: njordan
 */

#ifndef ASTDATA_H_
#define ASTDATA_H_

// #include "Symbol.h"
#include "Label.h"
#include <vector>
class Symbol;

class ASTData {

public:

	ASTData();

	Symbol* result = 0;

	std::vector< Operation* >* code;

	Label* before = 0;

	Label* after = 0;

	int value = -1;

	static void removeLoadOps( std::vector< Operation* >* );

};

#endif /* ASTDATA_H_ */
