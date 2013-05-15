# stop using yacc!!
.SUFFIXES :

BISONFLAG=--debug
BISONCPP=bisonc++
FLEX=flexc++
CC=g++-4.7 -std=c++0x 
CCOPTION=-g -Wall -Wno-reorder

# ----------------------------------------------------------------------------

root=$(shell git rev-parse --show-toplevel)
src_dir=$(root)/src
INCLUDEDIRS = $(shell find src/ -type d -exec echo -I{} \;)
SRCS  = $(shell find src/ -name "*.cpp" -exec readlink -f {} \; )
OBJS  = $(SRCS:.cpp=.o)
COMPILER=mipsc
MAIN = $(shell find src/Compiler -name "main.cc")
LEX_OBJ = src/Compiler/lex.o 
PARSER_OBJ = src/Compiler/parse.o
COMPILER_OBJ = $(LEX_OBJ) $(PARSER_OBJ)

# Register Allocation Objects
RSRCS = $(shell find src/RegisterAllocation/ -name "*.cpp")
ROBJS = $(RSRCS:.cpp=.o)

# Mips Code Generation Objects
MSRCS = $(shell find src/MipsCode/ -name "*.cpp")
MOBJS = $(MSRCS:.cpp=.o)

# 3AC
TACSRCS = $(shell find src/3AC -name "*.cpp" -exec readlink -f {} \; )
TACOBJS = $(TACSRCS:.cpp=.o)

# ----------------------------------------------------------------------------
# mipsc

DEFAULT : $(OBJS) $(COMPILER_OBJ)
	$(CC) $(INCLUDEDIRS) $(CCOPTION) $(MAIN) $^ -o $(COMPILER)

# ----------------------------------------------------------------------------
# Register Allocation Driver

RA_DRIVER=$(root)/src/RegisterAllocation/RegAlloc.out

.PHONY : ra
ra : $(RA_DRIVER)

$(RA_DRIVER) : $(root)/drivers/reg_alloc_driver.o src/Types/Type.o $(ROBJS) $(MOBJS) $(root)/src/3AC/IdTracker.o
	$(CC) $(INCLUDEDIRS) $(CCOPTION) $^ -o $@

# ----------------------------------------------------------------------------
# Mips Code Generator Driver

MC_DRIVER=$(root)/src/MipsCode/MipsCode.out

.PHONY : mc
mc : $(MC_DRIVER)

$(MC_DRIVER) : $(root)/drivers/mips_code_driver.o $(MOBJS) $(root)/src/3AC/IdTracker.o src/Types/Type.o src/Types/BuiltinType.o src/RegisterAllocation/MipsVariable.o
	$(CC) $(INCLUDEDIRS) $(CCOPTION) $^ -o $@
	# src/3AC/IdTracker.o

# ---------------------------------------------------------------------
#  AddOp

.PHONY : ao

ao : $(root)/drivers/addop_driver.out

$(root)/drivers/addop_driver.out : $(root)/drivers/addop_driver.o $(TACOBJS) $(MOBJS) $(ROBJS) src/Types/Type.o src/Types/BuiltinType.o  
	$(CC) $(INCLUDEDIRS) $(CCOPTION) $^ -o $@

# ---------------------------------------------------------------------

# DEPDIR = .deps
# df = $(DEPDIR)/$(*F)

MAKEDEPEND = gcc $(INCLUDEDIRS) -M $(CPPFLAGS) -o $*.d $<

#
# TODO 
# This does not understand update on .h files, but putting %.h on dependency
# list causes 
# 
# 	make: *** No rule to make target `src/AST/Nodes/Source/InitializerListNode.o'.  Stop.
#
%.o : %.cpp
	@$(MAKEDEPEND); \
	cp $*.d $*.P; \
	sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
		-e '/^$$/ d' -e 's/$$/ :/' < $*.d >> $*.P; \
	rm -f $*.d
	$(CC) $(CCOPTION) -c $(INCLUDEDIRS) $(CCOPTION) -o $@ $<


-include $(SRCS:.cpp=.P)	

# ---------------------------------------------------------------------
# scanner
SCANNERDEF = $(shell find -name "scanner.lex")
SCANNERIMPL = $(shell find -name "lex.cc") 

$(SCANNERIMPL) : $(SCANNERDEF)
	cd src/Compiler && $(FLEX) $(FLEXFLAG) $(shell basename $(SCANNERDEF) )

$(LEX_OBJ) : $(SCANNERIMPL) $(shell find -name "Scanner*")
	$(CC) $(CCOPTION) $(INCLUDEDIRS) -c $(SCANNERIMPL) -o $(LEX_OBJ) 

#	cd src/Compiler && $(CC) $(CCOPTION) $(INCLUDEDIRS) -c lex.cc -o lex.o

# ----------------------------------------------------------------------------
# parser
PARSERDEF = $(shell find -name "parser.y")
PARSER_IH= $(shell find -name "Parser.ih")
PARSER_H= $(shell find -name "Parser.H")
PARSERIMPL = $(shell find -name "parse.cc")

$(PARSERIMPL) : $(PARSERDEF) $(PARSER_IH) $(PARSR_H)
	cd src/Compiler && $(BISONCPP) $(BISONFLAG) $(shell basename $(PARSERDEF) )

$(PARSER_OBJ) : $(PARSERIMPL)
	$(CC) $(CCOPTION) $(INCLUDEDIRS) -c $(PARSERIMPL) -o $(PARSER_OBJ)

# ---------------------------------------------------------------------
# misc

clean :
	find -name "*.o" -exec rm {} \;
	find -name "*.P" -exec rm {} \;
	find -name "*.d" -exec rm {} \;
	rm $(COMPILER)
	rm tags

cleanAll :
	rm $(EXECUTABLES) ; make clean

tags : $(shell find -name "*.ih" -or -name "*.h" -or -name "*.cc" -or -name "*.cpp")
	ctags -R .

