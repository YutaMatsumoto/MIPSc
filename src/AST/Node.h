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

class Node {

public:

	virtual ~Node();

	virtual std::vector< Operation* >* toOperations() = 0;

	virtual std::string getNodeTypeAsString() = 0;

	Node* getParent();

	void setParent( Node* _parent );

protected:

	Node* parent;

	Node();

};

#endif /* NODE_H_ */
