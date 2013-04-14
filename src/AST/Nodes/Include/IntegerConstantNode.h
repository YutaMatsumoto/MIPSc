/*
 * IntegerConstantNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef INTEGERCONSTANTNODE_H_
#define INTEGERCONSTANTNODE_H_

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class IntegerConstantNode : public Node
{

public:

	IntegerConstantNode( long long int _value );
	long long int getValue();
	std::vector< Operation* >* toOperations();
	std::string getNodeTypeAsString();

	//These handle the issue of overflow when casting
	// or performing operations
	inline bool canBeShort() { return ( value < 128 ) ? true : false; }
	inline bool canBeInt() { return ( value < 2147483648 ) ? true : false; }
	inline bool canBeLong() { return ( value < 2147483648 ) ? true : false; }
	//Long long is still going to be 32 bits on MIPS
	inline bool canBeLongLong() { return ( value < 2147483648 ) ? true : false; }

	inline bool canBeUnsignedShort() { return ( value < 256 ) ? true : false; }
	inline bool canBeUnsignedInt() { return ( value < 4294967296 ) ? true : false; }
	inline bool canBeUnsignedLong() { return ( value < 4294967296 ) ? true : false; }
	inline bool canBeUnsignedLongLong() { return ( value < 4294967296 ) ? true : false; }

protected:

	long long int value;

};


#endif /* INTEGERCONSTANTNODE_H_ */
