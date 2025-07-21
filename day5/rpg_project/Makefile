CXX = g++
CXXFLAGS = -std=c++11 -Wall
OBJECTS = main.o character.o warrior.o mage.o paladin.o

rpg: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o rpg $(OBJECTS)

main.o: main.cpp character.h warrior.h mage.h paladin.h
character.o: character.cpp character.h
warrior.o: warrior.cpp warrior.h character.h
mage.o: mage.cpp mage.h character.h
paladin.o: paladin.cpp paladin.h warrior.h mage.h

clean:
	rm -f *.o rpg

run:
	./rpg > rst
	diff expect rst

.PHONY: clean
