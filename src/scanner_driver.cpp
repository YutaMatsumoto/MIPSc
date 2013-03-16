#include <iostream>
#include <ostream>
#include <fstream>
#include <unistd.h>
#include <string.h>

#include "Scanner.h"

void debug_symboltable()
{
}

void debug_tokens()
{
}

void usage()
{
	system("cat scanner_driver_usage.txt");
}

struct CommandFlags {

	CommandFlags()
		: error(false), lex_debug(false), symboltable_debug(false)
	{}

	void print() {
		std::cout << "symboltable_debug  : " << symboltable_debug << std::endl;
		std::cout << "lex_debug          : " << lex_debug << std::endl;
		std::cout << "output file       : " <<  ofile << std::endl;
		std::cout << "input  file       : " <<  ifile << std::endl;
	}

	bool error;
	bool lex_debug;
	bool symboltable_debug;
	std::string ofile;	
	std::string ifile;

};

CommandFlags parse_command2(int argc, char* argv[])
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
					f.symboltable_debug = true;
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
							f.symboltable_debug = true;
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

			// Output File
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

const int endOfFile=0;

int main(int argc, char* argv[])
{
	// CommandFlags f = parse_command(argc-1, &argv[1]);
	CommandFlags f = parse_command2(argc, argv);
	if (f.error) {
		usage();
		return 1;
	}
	return 1;

	Scanner s;
	int val = s.lex();
	std::string matched = s.matched();
	while (val!=endOfFile) {
		std::cout << matched << " : " << val << std::endl;
		val = s.lex();
		matched = s.matched();
	}
	
}
