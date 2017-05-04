# EE 160 Team AMERICA Road Trip Final Project Makefile


all: RoadTrip

RoadTrip: fileIO.o Node.o RoadTrip.c

pathplanning.o: pathplanning.h

fileIO.o: fileIO.h

Node.o: Node.h

# clean targets

.PHONY: clean build-clean

clean: build-clean

build-clean:
	-rm *.o RoadTrip
