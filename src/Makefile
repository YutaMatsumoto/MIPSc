BISONFLAG=--debug
BISON=bisonc++
FLEX=flexc++
CC=g++ -std=c++0x
CCOPTION=-g

COMPILER_NAME=MIPSc
EXECUTABLES=$(COMPILER_NAME) scan

# ---------------------------------------------------------------------
# Drivers

default : $(EXECUTABLES)

scan : scanner_driver.cpp lex.o parse.cc SymbolTable.o
	$(CC) $(CCOPTION) $^ -o $@ 

SymbolTableDriver.out : SymbolTableDriver.cpp SymbolTable.o parse.o lex.o
	$(CC) $(CCOPTION) parse.o lex.o SymbolTable.o $< -o $@

# ---------------------------------------------------------------------
# Objects

% : %.cpp
	$(CC) $(CCOPTION) $< -o $@ 

$(COMPILER_NAME) : parse.o lex.o SymbolTable.o
	$(CC) $(CCOPTION) $^ main.cc -o $@

%.o : %.cc 
	$(CC) -c $(CCOPTION) $< -o $@

lex.o : lex.cc Scannerbase.h Scanner.h Scanner.ih
	$(CC) -c $(CCOPTION) $< -o $@

parse.o : parse.cc Parserbase.h Parser.h Parser.ih 
	$(CC) -c $(CCOPTION) $< -o $@

lex.cc Scannerbase.h Scanner.h Scanner.ih : scanner.lex parse.cc
	$(FLEX) $< 

parse.cc : parser.y
	$(BISON) $(BISONFLAG) $<

SymbolTable.o : SymbolTable.cc SymbolTable.h
	$(CC) -c $(CCOPTION) $< -o $@

# ---------------------------------------------------------------------
# Test

.PHONY : test_scan
test_scan : scan
	bash test_scan.sh ts*.c

# ---------------------------------------------------------------------
clean : 
	rm *.o $(EXECUTABLES) *debug *tokens *.out

