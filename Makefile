# target: dependencies 
#	action
COMMANDFLAGS = -Wall -Wextra -pedantic -std=c11

gameoflife: gol.o gameoflife.o
	gcc $(COMMANDFLAGS) gol.o gameoflife.o -o gameoflife

libgol.so: gol.o
	gcc $(COMMANDFLAGS)

gameoflife.o: gameoflife.c11	
	gcc $(COMMANDFLAGS) -c gameoflife.c11

gol.o: gol.c gol.h
	gcc $(COMMANDFLAGS) -c gol.c

clean:
	rm *.0 gameoflife libgol.so






