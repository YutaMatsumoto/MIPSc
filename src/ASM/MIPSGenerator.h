/*
 * MIPSGenerator.h
 *
 *  Created on: Apr 3, 2013
 *      Author: njordan
 */

#ifndef MIPSGENERATOR_H_
#define MIPSGENERATOR_H_

#include <vector>
#include <string>
#include <iostream>

#include "Operation.h"

class MIPSGenerator
{

public:

	inline MIPSGenerator( std::vector< Operation* >& __3AC ) : _3AC( __3AC )
	{

	}

	virtual ~MIPSGenerator();

	void generateMIPS();

	void writeMIPS( std::ostream& );

protected:

	std::vector< Operation* > _3AC;

	std::vector< std::string > mips;

};

#endif /* MIPSGENERATOR_H_ */
