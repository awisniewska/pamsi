CPPFLAGS=-pedantic -Wall -Iinc -g
LDFLAGS=-Wall

all: asarray

obj:
	mkdir obj

asarray: obj/main.o obj/benchmark.o
	g++ $(CPPFLAGS) obj/main.o obj/benchmark.o -o asarray
	
obj/benchmark.o: src/benchmark.cpp
	g++ $(CPPFLAGS) -c src/benchmark.cpp -o obj/benchmark.o

obj/main.o: src/main.cpp 
	g++ $(CPPFLAGS) -c src/main.cpp -o obj/main.o
	

clean:
	rm -rf asarray obj/*
