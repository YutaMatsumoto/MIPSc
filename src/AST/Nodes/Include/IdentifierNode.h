/*
 * IdentifierNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef IDENTIFIERNODE_H_
#define IDENTIFIERNODE_H_

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class IdentifierNode : public Node
{

public:

	IdentifierNode( std::string _id );

	std::string getId();

	ASTData* toOperations();

	std::string getNodeTypeAsString();

protected:

	std::string id;

};


#endif /* IDENTIFIERNODE_H_ */
