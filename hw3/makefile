# TEMP MAKEFILE
all: driver1 spchk spchk1

driver1:
	cc driver1.c letters.c -o driver1

spchk:
	cc spchk.c letters.c -o spchk

spchk1:
	cc spchk1.c letters.c spchkDriver.c -o spchk1

# object targets
letters.o: letters.h
spchk1.o: spchk1.h

# utility targets

clean:
	rm -f *.o

real_clean: clean
	rm -f driver1 spchk spchk1 a.out core

