BISON=bisonc++
FLEX=flexc++
CC=g++ -std=c++0x
CCOPTION=-g

.PHONY : parser
parser : Parserbase.h Parser.h Parser.ih
Parserbase.h Parser.h Parser.ih : parser.y
	$(BISON) $<

.PHONY : scanner
scanner : Scannerbase.h Scanner.h Scanner.ih
Scannerbase.h Scanner.h Scanner.ih : scanner.lex
	$(FLEX) $<

SymbolTable.o : SymbolTable.cc SymbolTable.h
	$(CC) $(CCOPTION) -c $< -o $@
