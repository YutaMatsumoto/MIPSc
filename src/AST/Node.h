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

class Node {

public:

	virtual ~Node();

	virtual std::vector< Operation > toOperations();

	inline Node* getParent()
	{

		return parent;

	}

	inline void setParent( Node* _parent )
	{

		parent = _parent;

	}

protected:

	Node* parent;

	inline Node( )
	{

	}

};

#endif /* NODE_H_ */
