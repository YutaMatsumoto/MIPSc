/*
 * DeclarationListNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef DECLARATIONLISTNODE_H_
#define DECLARATIONLISTNODE_H_

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class DeclarationListNode : public Node
{

public:

	DeclarationListNode();

	std::vector< Operation* >* toOperations();

	std::string getNodeTypeAsString();

};


#endif /* DECLARATIONLISTNODE_H_ */
