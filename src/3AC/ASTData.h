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

	//the 'result' points to temporaries, in the event
	// we need to get someting like an array data this can
	// point to an array
	Symbol* idResult = 0;

	//This is how we get the array size for a declaration
	int value = -1;

	static void removeLoadOps( ASTData* data  );

};

#endif /* ASTDATA_H_ */
