#include <iostream>
#include <ostream>
#include <fstream>
#include <unistd.h>
#include <string.h>

#include "Scanner.h"
#include "Parser.h"
#include "SymbolTable.h"

using namespace std;

// Globals
const int endOfFile=0;
const std::string tokens_extension = ".tokens";
const std::string ldebug_extension = ".ldebug";
const std::string sdebug_extension = ".sdebug";

void usage()
{
	system("cat scanner_driver_usage.txt");
}

struct CommandFlags {

	CommandFlags()
		: error(false), lex_debug(false), stab_debug(false)
	{}

	void print() {
		std::cout << "stab_debug  : " << stab_debug << std::endl;
		std::cout << "lex_debug          : " << lex_debug << std::endl;
		std::cout << "output file       : " <<  ofile << std::endl;
		std::cout << "input  file       : " <<  ifile << std::endl;
	}

	bool error;
	bool lex_debug;
	bool stab_debug;
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
				}

				// Debug Mode Specified : Debug l or s
				else {
					for( int i = 0; i < strlen( optarg ) ; i++ ) {
						// Lexer Debug
						if ( optarg[i] == 'l' ) {
							f.lex_debug = true;
						}
						// Symbol Table Debug
						else if ( optarg[i] == 's' )
							f.stab_debug = true;
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

			// Output File Option
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

int main(int argc, char* argv[])
{
	//
	//      Parse Command Line
	//
	// CommandFlags f = parse_command(argc-1, &argv[1]);
	CommandFlags f = parse_command(argc, argv);

	if (f.error) {
		usage();
		return 1;
	}
	// f.print();

	//
	//
	//      Set UptScanner 
	//
	//
	std::ifstream i(f.ifile); // input file
	SymbolTable stab;
	Scanner scanner(&stab, i);

	//
	//      Parepare Output Streams
	//
	
	// token file stream
	std::ofstream t; 
	if (f.ofile.size()==0) {
		f.ofile=f.ifile + tokens_extension;
		t.open(f.ofile);
		scanner.setDebugToken(f.ofile);
		cout << "Producing token file : " << f.ofile << endl;
	}

	//
	//      Open Lex Debug Stream If Lex Debug Specified
	//
	std::ofstream l; 
	if (f.lex_debug) {
		std::string debug_file_lex = f.ifile + ldebug_extension;
		l.open(debug_file_lex);
		scanner.setDebugLexer(l);
		cout << "Producing lexer debug file : " << debug_file_lex << endl;
	}

	//
	//      Open Symbol Table Debug Stream If Symbl Table Debug Specified
	//
	std::ofstream s; 
	if (f.stab_debug) {
		std::string debug_file_stab = f.ifile + sdebug_extension;
		// s.open(debug_file_stab);
		scanner.setDebugSymbolTableDump(debug_file_stab);
		cout << "Producing symbol table debug file: " << debug_file_stab << endl;
	}

	// Run scanner
	scanner.run();	

	t.close();
	l.close();
	s.close();	
}
