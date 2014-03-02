CPPFLAGS=-pedantic -Wall -Iinc
LDFLAGS=-Wall

all: benchmark

obj:
	mkdir obj

benchmark: obj/main.o obj/tablice.o
	g++ $(CPPFLAGS) obj/main.o obj/tablice.o -o benchmark

obj/main.o: src/main.cpp inc/tablice.hh
	g++ $(CPPFLAGS) -c src/main.cpp -o obj/main.o
	
obj/tablice.o: src/tablice.cpp inc/tablice.hh
	g++ $(CPPFLAGS) -c src/tablice.cpp -o obj/tablice.o

clean:
	rm -rf benchmark obj/*
