/*
 * ConstantNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef CONSTANTNODE_H_
#define CONSTANTNODE_H_


#include "IntegerConstantNode.h"
#include "FloatConstantNode.h"
#include "CharConstantNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>


class ConstantNode : public Node
{

public:

	ConstantNode( IntegerConstantNode* _intConstant );

	ConstantNode( FloatConstantNode* _floatConstant );

	ConstantNode( CharConstantNode* _charConstant );

	ASTData* toOperations();

	std::string getNodeTypeAsString();

	~ConstantNode();

protected:

	IntegerConstantNode* intConstant = 0;
	FloatConstantNode* floatConstant = 0;
	CharConstantNode* charConstant = 0;

	// TODO Enumeration constant
	// EnumerationConstantNode* enumConstant;

	//~CharConstantNode(){}

};


#endif /* CONSTANTNODE_H_ */
