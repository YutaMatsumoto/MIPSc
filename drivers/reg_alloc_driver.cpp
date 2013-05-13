#include "RegisterTable.h"
#include "MemoryTable.h"
#include "IdTracker.h"
#include "RegisterAllocationCommon.h"
#include "DescriptorTable.h"
#include <vector>
#include <iostream>
using namespace std;

void RegisterTableDriver()
{
	// const int fstart = 0;
	// const int fend = 30;
	// const int istart = 4;
	// const int iend = 25;

	const int fstart = 1;
	const int fend = 3;
	// const int istart = 4;
	// const int iend = 25;
	

	MemoryTable mTable;
	mTable.setDebug();
	// RegisterTable iTable(istart, iend, mTable);
	// iTable.setDebug();
	RegisterTable fTable(fstart, fend, mTable);
	fTable.setDebug();

	std::vector<unsigned int> floatIds;
	std::vector<unsigned int> intIds;

	for (int i = 0 ; i < 10 ; i++) {
		floatIds.push_back( IdTracker::getInstance()->getId() );
		intIds.push_back(   IdTracker::getInstance()->getId() );
	}
		
	RegisterInfo ri(0,false);
	// getRegister for each id sequentially
	for ( int i = 0; i<floatIds.size() ; i++ ) {
		VarId vid = floatIds[i];
		cout << "Getting Register for vid = "  << vid << endl;
		ri = fTable.getRegister(vid);
		cout << ri.toString() << endl; 
	}

	cout << "MTable" << endl;
	cout << mTable.toString() << endl << endl;
	cout << "RTable" << endl;
	cout << fTable.toString() << endl << endl;

	// getRegister for variable already stored in memory
	fTable.getRegister(0);

}


int main()
{
	RegisterTableDriver();

	DescriptorTable& dTable = DescriptorTable::getInstance();

	
}
