CPPFLAGS=-pedantic -Wall -Iinc -g
LDFLAGS=-Wall

all: structures

obj:
	mkdir obj

structures: obj/main.o obj/tablice.o
	g++ $(CPPFLAGS) obj/main.o obj/tablice.o -o structures

obj/main.o: src/main.cpp 
	g++ $(CPPFLAGS) -c src/main.cpp -o obj/main.o
	
obj/tablice.o: src/tablice.cpp
	g++ $(CPPFLAGS) -c src/tablice.cpp -o obj/tablice.o
	

clean:
	rm -rf structures obj/*
