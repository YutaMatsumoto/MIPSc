#include <map>
#include <list>
#include "Parserbase.h"

#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

// > -------------------------------------------------------------------------
// References
// ---------------------------------------------------------------------------
//
//  [PA05 Requirements](http://www.cse.unr.edu/~fredh/class/460/S2013/PA/PA5/PA5.php)
//
//  dragon book pg85
//

// > -------------------------------------------------------------------------
// Auxiliaries for Symbol 
// ---------------------------------------------------------------------------
//
// SymbolKey ... lookup key in the table
//
// SymbolVal ... consists of 
//
//      SymbolData ... arbitrary data of the symbol. Depends on the type of the
//                     symbol such as int, float, array, struct, and so on.
//
//      SymbolLoc  ... location of the symbol in the program
//
// 

typedef std::string         SymbolKey;      // lexeme
struct                      SymbolData {};  // data for the symbol
typedef ParserBase::LTYPE__ SymbolLoc;

struct SymbolVal { 
    SymbolVal() 
        : loc(SymbolLoc()), data(SymbolData())
    {}
    SymbolVal(SymbolLoc l, SymbolData v) 
        :loc(l), data(v)
    {}
    SymbolLoc loc; 
    SymbolData data; 
};

// > -------------------------------------------------------------------------
// Auxiliaries for Symbol Table
// ---------------------------------------------------------------------------
//
//  SymbolTable consists of a set of scopes, each of which containing a set of symbols.
//
//  Scope 
//
//  SymbolDetail
//
//  SymbolInfo 
//
//  SymbolCondition
//

enum SymbolCondition { Healthy, Shadow, Conflict };
    
typedef std::map< SymbolKey , SymbolVal > Scope;
typedef std::list< Scope >                ScopeStack;
typedef std::pair<SymbolKey,SymbolVal>    SymbolPair;

struct SymbolInfo {
    SymbolInfo(SymbolCondition c, SymbolLoc l) 
        : cond(c), loc(l)
    {}
    SymbolCondition cond;
    SymbolLoc loc;
};

// SymbolData with Scope
typedef ScopeStack::iterator SymbolScope;
struct SymbolDetail {
    SymbolDetail(SymbolScope s, SymbolData d)
        : sscope(s), sdata(d)
    {}
    SymbolScope sscope;
    SymbolData sdata;
};

// > -------------------------------------------------------------------------
// SymbolTable Interface
// ---------------------------------------------------------------------------

class SymbolTable
{
public:

    SymbolTable() 
        : cscope(ss.end())
    {}

    // Insert symbol and returns info about condition of the symbol
    // ( whether it shadows/conflicts another symbol). If the inserted symbol
    // Shadows/Concflicts, then only the location of the first
    // shadowed/conflicted symbol will be contained in return.
    SymbolInfo insertSymbol( SymbolKey, SymbolLoc );

    // Search the symbol and return SymbolScope and SymbolData.
    // If the symbol is not found, the iterator points to the ss.end().
    // The search starts from the Scope specified. 
    // This function cannot be used when the SymbolTable is empty ( when cscope==ss.end() ).
    SymbolDetail searchSymbol( SymbolKey, SymbolScope );

    // Return iterator to the current scope.
    // If the scope stack is empty, return ss.end().
    SymbolScope currentScope();

    // Push/Pop a scope from the table
    void pushScope();
    void popScope();

    //dumps the symbol table to a file
    void dumpTable( std::string filename );

protected:

    //This is the "stack" of balanced binary search trees for symbols
    // front of the list is the top of the stack
    ScopeStack ss; // Scope Stack

    // Iterator to the current scope in ss
    // When symbol table is empty, cscope == ss.end().
    SymbolScope cscope; // currernt scope

};

#endif
