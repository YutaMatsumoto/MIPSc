# stop using yacc!!
.SUFFIXES :

BISONFLAG=--debug
BISONCPP=bisonc++
FLEX=flexc++
CC=g++-4.7 -std=c++0x 
CCOPTION=-g -Wall -Wno-reorder

%.out : %.cpp
	$(CC) $(CCOPTION) $(INCLUDEDIRS) $(CCOPTION) -o $@ $<

all : tac_driver.out

clean : 
	rm *.o *.out *.d *.P

