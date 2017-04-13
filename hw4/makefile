#makefile for gsnake

GAME = /inst/ee/ee160/ee160/S17/gsnake

all: gsnake dispTest moveTest placeTest attackTest

dispTest: dispTest.o display.o
	cc dispTest.o display.o -o dispTest -lncurses

moveTest: moveTest.o move.o display.o
	cc moveTest.o move.o display.o -o moveTest -lncurses

placeTest: placeTest.o place.o
	cc placeTest.o place.o -o placeTest

attackTest: attackTest.o attack.o move.o display.o place.o
	cc attackTest.o attack.o move.o display.o place.o -o attackTest -lncurses

gsnake: driver.o attack.o place.o move.o place.o
	cc driver.o attack.o place.o move.o place.o -o gsnake -lncurses

dispTest.o: display.h

moveTest.o: move.h display.h

move.o: move.h

placeTest.o: place.h

place.o: place.h

attackTest.o: attack.h move.h display.h

attack.o: attack.h

driver.o: attack.h place.h move.h display.h

links:
	 ln -s -f $(GAME)/display.o .
	 ln -s -f $(GAME)/display.h .
	 ln -s -f $(GAME)/move.h .
	 ln -s -f $(GAME)/place.h .
	 ln -s -f $(GAME)/attack.h .

clean:
	mv display.o display.sav
	rm -rf *.o
	mv display.sav display.o

real_clean: clean
	rm -rf gsnake dispTest moveTest placeTest attackTest a.out core
	 

