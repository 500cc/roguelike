roguelike: main.o gamestate.o game.o title.o
	lcc -o roguelike.gb main.o gamestate.o game.o title.o
main.o: main.c main.h gamestate.h game.h title.h
	lcc -c $*.c
gamestate.o: gamestate.c gamestate.h
	lcc -c $*.c
game.o: game.c game.h
	lcc -c $*.c
title.o: title.c title.h
	lcc -c $*.c

clean:
	rm *.o
