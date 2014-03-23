CPPFLAGS=-pedantic -Wall -Iinc -g
LDFLAGS=-Wall

all: structures

obj:
	mkdir obj

structures: obj/main.o obj/benchmark.o
	g++ $(CPPFLAGS) obj/main.o obj/benchmark.o -o structures

obj/main.o: src/main.cpp 
	g++ $(CPPFLAGS) -c src/main.cpp -o obj/main.o
	
obj/benchmark.o: src/benchmark.cpp
	g++ $(CPPFLAGS) -c src/benchmark.cpp -o obj/benchmark.o
	

clean:
	rm -rf structures obj/*
