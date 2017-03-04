

# Problem 1 - test driver
driver1: driver1.o letters.o
	cc driver1.o letters.o -o driver1

# Problem 2 - spell checker
spchk: spchk.o letters.o
	cc spchk.o letters.o -o spchk

# source file dependencies

driver1.o: letters.h

spchk.o: letters.h

letters.o: letters.h


# utility targets

clean:
	rm -f *.o

real_clean: clean
	rm -f driver1 spchk a.out core

