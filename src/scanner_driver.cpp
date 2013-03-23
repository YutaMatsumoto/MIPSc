#include <iostream>
#include <ostream>
#include <fstream>
#include <unistd.h>
#include <string.h>

#include "Scanner.h"
#include "Parser.h"

//	TODO
//		
//		Add symbol table to scanner
//	
//		Replace system("cat...") in usage
//
//		check if file is openable on open
//

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
	// CommandFlags f = parse_command(argc-1, &argv[1]);
	CommandFlags f = parse_command(argc, argv);
	if (f.error) {
		usage();
		return 1;
	}

	std::ifstream i(f.ifile); 
	std::ofstream t;
	std::ofstream l;
	// std::ofstream s;

	if (f.ofile.size()==0) {
		f.ofile=f.ifile + tokens_extension;
		t.open(f.ofile);
	}
	if (f.lex_debug) {
		std::string debug_file_lex = f.ifile + ldebug_extension;
		l.open(debug_file_lex);
	}

	Scanner s(i);

	int val = s.lex();
	std::string matched = s.matched();
	while ( val != Parser::ENDOFFILE ) {
		std::cout << matched << " : " << val << std::endl;
		// token file
		t << matched << std::endl;
		// lex debug file
		if (f.lex_debug) 
			l << matched << " : " << val << std::endl;
		// stab debug should be done within scanner

		// update
		val = s.lex();
		matched = s.matched();
	}
	t.close();
	l.close();
	
}
