<<<<<<< HEAD
=======

# TEMP MAKEFILE
all: driver1 spchk

driver1:
	cc driver1.c letters.c -o driver1

spchk:
	cc spchk.c spchkDriver.c letters.c -o spchk


>>>>>>> c2a636d9f262d5ac44465a7110eaf9d6e3b7ea65
# Problem 1 - test driver
#driver1: driver1.c obj/letters.o
#	cc driver1.c obj/letters.o -o driver1

# Problem 2 - spell checker
#spchk: obj/spchk.o obj/letters.o
#	cc spchk.o letters.o -o spchk

# source file dependencies

#objs: obj/spchk.o obj/letters.o obj/driver1.o obj/spchkDriver.o

#obj/spchk.o: spchk.c
#	cc spchk.c -c -o obj/spchk.o
#obj/letters.o: letters.c
#obj/driver1.o: driver1.c
#obj/spchkDriver.o: spchkDriver.c


# utility targets

clean:
	rm -f *.o

real_clean: clean
	rm -f driver1 spchk a.out core

