CC = g++
CFLAGS = -g -std=c++11 -lpthread

house : house.cpp house.h
	${CC} ${CFLAGS} -c house.cpp

test:
	@echo "I'm too lazy currently";

clean:
	cd house && $(MAKE clean)
	rm *.o
