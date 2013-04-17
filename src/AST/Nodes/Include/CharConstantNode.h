/*
 * CharConstantNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef CHARCONSTANTNODE_H_
#define CHARCONSTANTNODE_H_

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class CharConstantNode : public Node
{

public:

	CharConstantNode( char _value );

	char getValue();

	ASTData* toOperations();

	std::string getNodeTypeAsString();

protected:

	char value;

};


#endif /* CHARCONSTANTNODE_H_ */
