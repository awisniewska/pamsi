CPPFLAGS=-pedantic -Wall -Iinc -g
LDFLAGS=-Wall

all: asarray

obj:
	mkdir obj

asarray: obj/main.o 
	g++ $(CPPFLAGS) obj/main.o -o asarray

obj/main.o: src/main.cpp 
	g++ $(CPPFLAGS) -c src/main.cpp -o obj/main.o
	

clean:
	rm -rf asarray obj/*
