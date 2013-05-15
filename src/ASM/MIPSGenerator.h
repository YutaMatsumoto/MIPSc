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

	void addFunction( Symbol* func );

	virtual ~MIPSGenerator();

	void generateMIPS();

	void writeMIPS( std::ostream& );

	void setTAC( std::vector< Operation* >* _tac );

	static MIPSGenerator& getInstance()
	{

		static MIPSGenerator instance;
		return instance;

	}

protected:

	std::vector< std::string > mipsText;

	std::vector< std::string > mipsData;

	std::vector< Symbol* > functions;

	std::vector< Operation* >* tac = 0;

	Symbol* currentFunction = 0;

	MIPSGenerator();

};

#endif /* MIPSGENERATOR_H_ */
