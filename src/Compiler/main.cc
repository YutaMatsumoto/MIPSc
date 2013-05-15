
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <cstring>
#include "Parser.h"
#include "SymbolTable.h"

// Globals
const int endOfFile=0;
const std::string suffix = ".list";
const std::string tokens_extension = ".tokens";
const std::string ldebug_extension = ".ldebug";
const std::string sdebug_extension = ".sdebug";
const std::string pdebug_extension = ".pdebug";

void usage()
{
	system("cat ../src/Doc/usage.txt");
}

struct CommandFlags {

	CommandFlags()
		: error(false), lex_debug(false), stab_debug(false), parser_debug(false)
	{}

	void print() {
		std::cout << "stab_debug  : " << stab_debug << std::endl;
		std::cout << "lex_debug          : " << lex_debug << std::endl;
		std::cout << "parser debug : " <<  parser_debug << std::endl;
		std::cout << "output file       : " <<  ofile << std::endl;
		std::cout << "input  file       : " <<  ifile << std::endl;

	}

	bool error;
	bool lex_debug;
	bool stab_debug;
	bool parser_debug;
	std::string ifile;
	std::string ofile;	

};

CommandFlags parse_command(int argc, char* argv[])
{
	CommandFlags f;
	int c;
	while ( (c = getopt(argc, argv, "d::o:")) != -1 ) {
		// std::cout << "c==" << char(c) << std::endl;

		// Start Parsing Options
		switch (c) { 

			// Debug Option
			case 'd' : {

				// Debug Mode Not Specified : Debug both l and s
				if ( optarg == 0 ) {
					f.lex_debug = true;
					f.stab_debug = true;
					f.parser_debug = true;
				}

				// Debug Mode Specified : Debug l or s
				else {
					for( size_t i = 0; i < strlen( optarg ) ; i++ ) {
						// Lexer Debug
						if ( optarg[i] == 'l' ) {
							f.lex_debug = true;
						}
						// Symbol Table Debug
						else if ( optarg[i] == 's' ) {
							f.stab_debug = true;
						}
						else if ( optarg[i] == 'p' ) {
							f.parser_debug = true;
						}
						// Error
						else { 
							f.error = true;
							std::cerr 
								<< "error: -d option argument is illegal. <"
								<< optarg << "> is given."
								<< std::endl;
							return f;
						}
					}
				}

				break;
			}

			// Output File Option for Token File
			case 'o' : {
				f.ofile = std::string( optarg );
				break;
			}

		} // End Parsing Options
	}

	// Non-option argument is the input file
	int remaining = argc - optind;
	if (remaining==0) {
		std::cerr << "input file not supplied" << std::endl;
		f.error = true;
	}
	else if (remaining>1) {
		std::cerr << "The number of input files must be one" << std::endl;
		std::cerr << "Given Input Files : ";
		int index;
		for (index = optind; index < argc; index++)
			std::cerr << "<" << argv[index] << "> ";
		std::cerr << std::endl;
		f.error = true;
	}
	else { // remaining == 1
		f.ifile = std::string( argv[optind] );
	}

	// f.print();
	return f;
}

void tryOpenForWrite(std::ofstream& os, std::string fname)
{
	os.open(fname);
}


int main(int argc, char** argv) 
{

	//
	//      Parse Command Line
	//
	// CommandFlags f = parse_command(argc-1, &argv[1]);
	CommandFlags f = parse_command(argc, argv);

	// f.print();

	if (f.error) {
		usage();
		return 1;
	}
	// f.print();

	//
	//
	//      Set Up Scanner, Symbol Table, and Parser
	//
	//
	std::ifstream i(f.ifile); // input file
	SymbolTable table;
	Scanner scanner(&table, i);
	Parser p(scanner, &table);
	p.setDebug( false );

	//
	//      Prepare Output Streams
	//
	// token file stream
	std::ofstream t; 
	std::ofstream l; 
	std::ofstream s; 
	std::ofstream pd;

	// 
	// Token File
	//
	if (f.ofile.size()==0) {
		f.ofile=f.ifile + tokens_extension;
		t.open(f.ofile);
		scanner.setDebugToken(f.ofile);
		std::cout << "Producing token file              : " << f.ofile << std::endl;
	}

	// --------------------------------------------------------------------
	// Handle Debug Options

	//
	//      Parser and Lexer Debug at the same time
	//
	// if (f.lex_debug) {
	// 	std::string debug_file_lex_and_parser = f.ifile + suffix;
	// 	l.open(debug_file_lex_and_parser);
	// 	// scanner.setDebugLexer(l);
	// 	scanner.setDebugLineByLine(l);
	// 	p.configDebugPrint(l, "Reducing From ", "");
	// 	cout << "Producing debug list              : " << debug_file_lex_and_parser << " (lex and parse debug to the same file)" << endl;
	// }
	//
	//      Open Lex Debug Stream If Lex Debug Specified
	//
	if (f.lex_debug) {
		std::string debug_file_lex = f.ifile + ldebug_extension;
		l.open(debug_file_lex);
		// scanner.setDebugLexer(l);
		std::cout << "Producing lexer debug file        : " << debug_file_lex << std::endl;
	}
	// 
	//      Parser debug
	// 
	if (f.parser_debug) {
		std::string debug_file_parser = f.ifile + pdebug_extension;	
		pd.open(debug_file_parser);
		// p.configDebugPrint(pd, "Reducing From ", "");
		p.configDebugPrint(pd, "", "");
		scanner.setDebugLineByLine(pd);
		p.setDebug( false );
		std::cout << "Producing Reduction Debug : " << debug_file_parser << std::endl;
	}

	//
	//      Open Symbol Table Debug Stream If Symbl Table Debug Specified
	//
	if (f.stab_debug) {
		std::string debug_file_stab = f.ifile + sdebug_extension;
		// s.open(debug_file_stab);
		scanner.setDebugSymbolTableDump(debug_file_stab);
		std::cout << "Producing symbol table debug file : " << debug_file_stab << std::endl;
	}


	// --------------------------------------------------------------------
	// run parser
	int returnFromParser;
	try {	
		returnFromParser = p.parse();
	} catch (const std::exception& e) {
		std::cerr<<e.what()<<std::endl;
		exit(1);
	} catch (...) {
		std::cerr<<"Some Exception by p.parse()"<<std::endl;
		exit(1);
	}

	ASTData* astData = p.get3AC();

	std::ofstream of;

	of.open( "tac_test.txt");

	std::vector< Operation* >* tac = astData->code;

	system("clear");

	for( unsigned int i = 0 ; i < tac->size() ; i++ )
	{

		Operation* j = tac->at( i );

		of << j->to3AC() << std::endl;

	}

	for( unsigned int i = 0 ; i < tac->size() ; i++ )
	{

		tac->at( i )->produceMips();

	}

	MipsCode& code = MipsCode::getInstance();

	code.dump( std::string("mips_test.txt") );

	/*
	*/

	// --------------------------------------------------------------------
	// clean up and return
	
	// Run scanner
	// scanner.run();	


	t.close();
	l.close();
	s.close();	

	return returnFromParser;
}
