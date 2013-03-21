// Generated by Bisonc++ V4.01.00 on Tue, 26 Feb 2013 14:54:58 -0800

#ifndef Parser_h_included
#define Parser_h_included

// $insert baseclass
#include "Parserbase.h"
#include "Scanner.h"
#include "SymbolTable.h"

#undef Parser
class Parser: public ParserBase
{
        
    public:
        int parse();

	Parser( std::istream& stream, SymbolTable* table )
	{

		scanner = new Scanner( stream );

		symbolTable = table;

	}

    Parser( Scanner& s, SymbolTable* table ) 
        : scanner(&s), symbolTable(table)
    {}

	LTYPE__* getLocationStruct()
	{

		return &d_loc__;

	}

    private:
        void error(char const *msg);    // called on (syntax) errors
        int lex();                      // returns the next token from the
                                        // lexical scanner. 
        void print();                   // use, e.g., d_token, d_loc
	
	Scanner* scanner;
	SymbolTable* symbolTable;

    // support functions for parse():
        void executeAction(int ruleNr);
        void errorRecovery();
        int lookup(bool recovery);
        void nextToken();
        void print__();
};


#endif
