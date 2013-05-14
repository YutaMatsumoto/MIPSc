#ifndef MIPS_VARIABLE_H_GUARD
#define MIPS_VARIABLE_H_GUARD

#include "Type.h"
#include "MipsData.h"

/** 
 * IdTracker does return only numbers.
 * This class is to distinguish variale types such as char/int/unsigned int/longint
 */

// See AddOp

typedef unsigned int MipsVariableId;

class MipsVariable {
public:

	MipsVariable(Type* type, MipsVariableId id);

	enum RegisterType { Float, Integer, None };

	RegisterType registerType();

	bool typeEqual(const MipsVariable &o);

	DLabel toDLabel(); // based on id and DKind

	DKind toDKind(); // and then toString() 

	// static DKind TypeEnumToDKind();
	// TypeEnum tKind;	
	
	
private:

	Type* type; // to know type and .datapseudo and operation

	MipsVariableId id; // IdTracker return

	// ? DKind::byteSize(); 
	//		to mask bits in char/... 
	//		array access

	// kind
};

#endif
