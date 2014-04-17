CPPFLAGS=-pedantic -Wall -Iinc
LDFLAGS=-Wall

all: benchmark

obj:
	mkdir obj

benchmark: obj/main.o obj/tablice.o obj/tablica.o
	g++ $(CPPFLAGS) obj/main.o obj/tablice.o obj/tablica.o -o benchmark

obj/main.o: src/main.cpp inc/tablice.hh
	g++ $(CPPFLAGS) -c src/main.cpp -o obj/main.o
	
obj/tablice.o: src/tablice.cpp inc/tablice.hh
	g++ $(CPPFLAGS) -c src/tablice.cpp -o obj/tablice.o
	
obj/tablica.o: src/tablica.cpp inc/tablica.hh
	g++ $(CPPFLAGS) -c src/tablica.cpp -o obj/tablica.o

clean:
	rm -rf benchmark obj/*
