
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Parser.h"
#include "SymbolTable.h"
using namespace std;

const string suffix = ".list";

int main( int argc , char** argv ) {
	
	//
	//      Erro Handling
	//
	if( argc < 2 )
	{

		cerr << "specify file" << endl;

		exit(1);

	}

	//
	//      Try Open Input File
	//
	string input_filename( argv[1] );
	fstream inf;
	inf.open( input_filename, fstream::in );
	if( !inf.good() )
	{
		cerr << "cannot open file" << endl;
		exit(2);
	}

	//
	//      Open Output File
	//
	const string output_filename = input_filename + suffix;
	ofstream ofs(output_filename);

	// Symbol Table
	SymbolTable table;

	//
	//      Scanner with ofstream
	//
	Scanner scanner(inf);
	scanner.setDebugLineByLine(ofs);

	//
	//      Scanner with stdout
	//
	// Scanner scanner(&table, inf, cout); 
	// scanner.setDebugLineByLine(cout);
	
	//
	//      Parser
	//
	// Parser p( inf , table );
	Parser p(scanner, &table);
	p.configDebugPrint(ofs, "Reducing From ", "");
	p.setDebug( false );
	
	return p.parse();
}
