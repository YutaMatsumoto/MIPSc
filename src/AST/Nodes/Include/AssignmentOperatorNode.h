/*
 * AssignmentOperatorNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef ASSIGNMENTOPERATORNODE_H_
#define ASSIGNMENTOPERATORNODE_H_

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class AssignmentOperatorNode : public Node
{

public:

	enum AssignmentOperatorType
	{
		Assign,
		MulAssign,
		DivAssign,
		ModAssign,
		AddAssign,
		SubAssign,
		LeftAssign,
		RightAssign,
		AndAssign,
		XORAssign,
		OrAssign

	};

	AssignmentOperatorNode( AssignmentOperatorType _type );

	std::vector< Operation* >* toOperations();

	inline std::string getNodeTypeAsString();

	AssignmentOperatorType type;

};


#endif /* ASSIGNMENTOPERATORNODE_H_ */
