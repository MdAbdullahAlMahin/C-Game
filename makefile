

game.o: game.cpp player.h enemy.h hotel.h fileIO.h fight.h
	g++ -pedantic-errors -std=c++11 -c game.cpp

game: game.o game.cpp
	g++ -pedantic-errors -std=c++11 game.o -o game

clean:
	rm -rf *.o game

PHONY: clean
