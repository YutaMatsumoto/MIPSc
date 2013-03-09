#include <stack>
#include <unordered_map>
#include "Parserbase.h"

//
//      TODO/TOTHINK
//
//  1. Parameter list of searchSymbol() should contain scope level to search
//     so that the shadowed variables can be searched ?
//

//
//      References
//
//  [PA05 Requirements](http://www.cse.unr.edu/~fredh/class/460/S2013/PA/PA5/PA5.php)
//
//  dragon book pg85
//
class SymbolTable
{

    // Symbol
    typedef std::string                                 SymbolKey; // lexeme
    typedef Meta__::SType                               SymbolVal;
    typedef struct { SymbolKey key; SymbolVal val; }    Symbol;

    // Scope
    typedef std::unordered_map< SymbolKey, SymbolVal > Scope;

    // Symbol Diagnostic Info
    enum            SymbolCondition { Healthy, Shadow, Conflict };
    typedef LTYPE__ SymbolLoc;
    struct SymbolInfo {
        SymbolCondition cond;
        SymbolLoc loc;
    };

    // Symbol with Scope Level
    typedef int ScopeLevel;
    struct SymbolDetail {
        ScopeLevel level;
        SymbolVal& val;
    };

public:

    // Insert symbol and returns info about condition of the symbol
    // ( whether it shadows/conflicts another symbol). If the inserted symbol
    // Shadows/Concflicts, then the location of the firste shadowed/conflicted
    // symbol will be contained in return.
    SymbolInfo insertSymbol( Symbol );

    // Search the symbol and return the scope level the symbol is in. 
    // The search starts from the current scope. 
    //
    // ScopeLevel :
    //
    //  -1 : used to report that the symbol is not in the table for search
    //       symbol
    //   1 : global in C
    //   2 : main in C
    //   3 : current function OR naked block in main in C
    //   4 : naked block in current function in C
    //   5 : another naked block in naked block in C
    //   6 : ...
    //
    //   These level corresponds to the number of Scopes in stack.
    //
    SymbolDetail searchSymbol( SymbolKey );

    // Current Scope Level. See searchSymbol().
    ScopeLevel currentScopeLevel(); 

    // Push/Pop a scope from the table
    void pushScope();
    void popScope();


    //dumps the symbol table to a file
    void dumpTable( std::string filename );

protected:

    //This is the stack of Hash Maps
    std::stack< Scope > tableStack;

    //This is another stack of hash maps, when you pop a HashMap off the 
    //  first stack, we push it on here to preserve the stack ordering
    // std::stack< Scope > inverseTableStack;


};
