/*
 * FloatConstantNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef FLOATCONSTANTNODE_H_
#define FLOATCONSTANTNODE_H_

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

#include <cfloat>

class FloatConstantNode : public Node
{

public:

	FloatConstantNode( double _value );
	double getValue();
	//These handle the issue of overflow when casting
	// or performing operations

	bool canBeFloat();

	ASTData* toOperations();
	std::string getNodeTypeAsString();

protected:

	double value;

};


#endif /* FLOATCONSTANTNODE_H_ */
