// Generated by Flexc++ V0.98.00 on Tue, 26 Feb 2013 15:00:00 -0800

#ifndef Scanner_H_INCLUDED_
#define Scanner_H_INCLUDED_

// $insert baseclass_h
#include "Scannerbase.h"
#include "SymbolTable.h"
#include <string>


class Parser;

struct Loc {
    Loc() 
        : lnum(1), cnum(1)
    {} 
    int lnum; // line number
    int cnum; // column number
};

// $insert classHead
class Scanner: public ScannerBase
{
    public:
        explicit Scanner(std::istream &in = std::cin,
                                std::ostream &out = std::cout);

	Scanner(SymbolTable*, std::istream &in = std::cin, std::ostream &out = std::cout);

    explicit Scanner(SymbolTable*);

        Scanner(std::string const &infile, std::string const &outfile);

        Scanner(std::istream &in, std::ostream &out, Parser* parser );

        void scannerError();

        void commentHandler();

        void updateLocation();

        void dumpSymbolTable();

        static const int tabWidth = 4;

        // $insert lexFunctionDecl
        int lex();


        Loc& getLoc() { return location; }

    private:

        Loc location; // current location

        std::string lineValue;

        int lex__();

        int executeAction__(size_t ruleNr);

        Parser* parser;

        void print();

        void preCode();     // re-implement this function for code that must 
                            // be exec'ed before the patternmatching starts

	SymbolTable* stab;
    std::istream& ref_istream;
};

// $insert scannerConstructors
inline Scanner::Scanner(std::istream &in, std::ostream &out)
:
    ScannerBase(in, out), ref_istream(in)
{}


inline Scanner::Scanner(SymbolTable* tab, std::istream &in, std::ostream &out)
:
    ScannerBase(in, out), stab(tab), ref_istream(in)
{}


// $insert scannerConstructors
inline Scanner::Scanner(std::istream &in, std::ostream &out, Parser* parser )
:
    ScannerBase(in, out), ref_istream(in)
{

	this->parser = parser;

}



inline Scanner::Scanner(std::string const &infile, std::string const &outfile)
:
    ScannerBase(infile, outfile)
{}

// $insert inlineLexFunction
inline int Scanner::lex()
{
    return lex__();
}

inline void Scanner::preCode() 
{
    // optionally replace by your own code
}

inline void Scanner::print() 
{
    print__();
}


#endif // Scanner_H_INCLUDED_

