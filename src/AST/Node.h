/*
 * Node.h
 *
 *  Created on: Apr 3, 2013
 *      Author: njordan
 */

#ifndef NODE_H_
#define NODE_H_

#include <vector>

#include "Operation.h"
#include "Label.h"
#include "ASTData.h"

class Node {

public:

	virtual ~Node();

	virtual ASTData* toOperations() = 0;

	virtual std::string getNodeTypeAsString() = 0;

	//Node* getParent();

	//void setParent( Node* _parent );

	ASTData* nodeData = 0;

protected:

	//Node* parent;



	Node();

};

#endif /* NODE_H_ */
