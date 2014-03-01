CPPFLAGS=-pedantic -Wall -Iinc
LDFLAGS=-Wall

all: benchmark

benchmark: obj/main.o
	g++ ${LDFLAGS} -o benchmark obj/main.o

obj/main.o: src/main.cpp
	g++ -c ${CPPFLAGS} -o obj/main.o  src/main.cpp

clean:
	rm -f benchmark obj/*
