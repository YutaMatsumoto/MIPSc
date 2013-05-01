/*
 * UnaryOperatorNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef UNARYOPERATORNODE_H_
#define UNARYOPERATORNODE_H_

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class UnaryOperatorNode : public Node
{

public:

	enum UnaryOperatorType
	{
		Address,
		Indirection,
		Positive,
		Negative,
		BitwiseNot,
		LogicalNot

	};

	UnaryOperatorNode( UnaryOperatorType _type );
	ASTData* toOperations();
	std::string getNodeTypeAsString();

	UnaryOperatorType type;

};


#endif /* UNARYOPERATORNODE_H_ */
