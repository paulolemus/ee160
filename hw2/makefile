
# a makefile for compiling the date difference project and its test drivers


# target for making all executables
all: driver1 driver2 driver3 datediff

# target for driver1
driver1: driver1.o leap.o
	cc  driver1.o leap.o -o driver1

# target for driver2
driver2: driver2.o leap.o days.o
	cc  driver2.o leap.o days.o -o driver2

# target for driver3
driver3: driver3.o leap.o days.o julian.o
	cc  driver3.o leap.o days.o julian.o -o driver3

# target for datediff
datediff: datediff.o leap.o days.o julian.o
	cc  datediff.o leap.o days.o julian.o -o datediff

# header dependency targets
driver1.o: leap.h

driver2.o: leap.h days.h

driver3.o: leap.h days.h julian.h

datediff.o: leap.h days.h julian.h

leap.o: leap.h

days.o: days.h leap.h

julian.o: julian.h days.h


# utility targets

clean:
	rm -f *.o

real_clean: clean
	rm -f driver1 driver2 driver3 datediff a.out core

