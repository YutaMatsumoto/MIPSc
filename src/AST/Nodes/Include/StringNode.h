/*
 * StringNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef STRINGNODE_H_
#define STRINGNODE_H_

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class StringNode : public Node
{

public:

	StringNode( std::string _value );
	std::string getValue();
	ASTData* toOperations();

	std::string getNodeTypeAsString();

protected:

	std::string value;

};


#endif /* STRINGNODE_H_ */
