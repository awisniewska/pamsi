CPPFLAGS=-pedantic -Wall -Iinc
LDFLAGS=-Wall

all: structures

obj:
	mkdir obj

structures: obj/main.o 
	g++ $(CPPFLAGS) obj/main.o -o structures

obj/main.o: src/main.cpp
	g++ $(CPPFLAGS) -c src/main.cpp -o obj/main.o
	

clean:
	rm -rf structures obj/*
