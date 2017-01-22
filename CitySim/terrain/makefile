CC = g++
CFLAGS = -g -std=c++11 -lpthread

terrain.o: terrain.cpp terrain.h
	${CC} ${CFLAGS} -c terrain.cpp

test: terrainDriver.cpp terrain.o
	${CC} ${CFLAGS} terrainDriver.cpp terrain.o -o terrainTest
	./terrainTest

clean:
	rm  terrainTest *.o
