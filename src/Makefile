BISONFLAG=--debug
BISON=bisonc++
FLEX=flexc++
CC=g++ -std=c++0x
CCOPTION=-g

COMPILER_NAME=compiler

scanner_driver : scanner_driver.cpp lex.o
	$(CC) $(CCOPTION) $^ -o $@ 

% : %.cpp
	$(CC) $(CCOPTION) $< -o $@ 

$(COMPILER_NAME) : parse.o lex.o
	$(CC) $(CCOPTION) $^ main.cc -o $@

%.o : %.cc 
	$(CC) -c $(CCOPTION) $< -o $@

lex.o : lex.cc Scannerbase.h Scanner.h Scanner.ih
	$(CC) -c $(CCOPTION) $< -o $@

parse.o : parse.cc Parserbase.h Parser.h Parser.ih 
	$(CC) -c $(CCOPTION) $< -o $@

# This produces Scannerbase.h Scanner.h Scanner.ih lex.cc
.PHONY : scanner_src
scanner_src : scanner.lex
	$(FLEX) $< 

# This produces Parserbase.h Parser.h Parser.ih parse.cc
.PHONY : parser_src
parser_src : parser.y
	$(BISON) $(BISONFLAG) $<
	
clean : 
	rm *.o $(COMPILER_NAME)
