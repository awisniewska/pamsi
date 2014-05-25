EXECUTABLE=graph
CFLAGS= -Wall -pedantic -Iinc

CC=g++
SOURCES= $(wildcard src/*.cpp)
HEADERS= $(wildcard inc/*.hh)
OBJECTS= $(subst src/,obj/,$(subst .cpp,.o,$(SOURCES)))

all: executable

obj:
	mkdir obj

executable: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

obj/%.o: src/%.cpp $(HEADERS) obj
	$(CC) $(CFLAGS) -c -o $@ $<
	
clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
	
dox:
	doxygen > /dev/null
	
pdf:
	cd doc/latex && make > /dev/null
	
cleandox:
	rm -rf doc/*