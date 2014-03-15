CPPFLAGS=-pedantic -Wall -Iinc
LDFLAGS=-Wall

all: struktury

obj:
	mkdir obj

struktury: obj/main.o 
	g++ $(CPPFLAGS) obj/main.o -o struktury

obj/main.o: src/main.cpp
	g++ $(CPPFLAGS) -c src/main.cpp -o obj/main.o
	

clean:
	rm -rf struktury obj/*
