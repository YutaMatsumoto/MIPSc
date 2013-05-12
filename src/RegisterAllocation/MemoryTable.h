#ifndef ADDRESS_TABLE_H_GUARD
#define ADDRESS_TABLE_H_GUARD
#include <vector>
#include <map>
#include <cstdlib>

#include "RegisterTable.h"
#include "RegisterAllocationCommon.h"

class MemoryTable {

	// MemoryId is sddress(size_t) for now, but label might be better
	typedef size_t MemoryId;

	struct MemoryComponent {
		MemoryComponent()
			: id(0), byteSize(0)
		{}

		MemoryComponent(MemoryId id, size_t byteSize)
			: id(id), byteSize(byteSize)
		{}

		MemoryId id;
		size_t byteSize;	
	};

	MemoryId currentAddress;
	
	typedef std::map<VarId, MemoryComponent> MTable;
	MTable table;

	bool debug;	

public:

	MemoryTable();

	void setDebug();

	void debugPrint(std::string msg);

	bool isInMemory(VarId vid);

	void load(RegisterNumber rNumber, VarId vid );

	void store(/*RegisterNumber rNumber,*/ VarId vid );

};

#endif
