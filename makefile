ifeq ($(DEBUG), yes)
	CC = gcc -g
else
	CC = gcc
endif

all: main.o LinkList.o
	$(CC) -o program main.o LinkList.o

main.o: main.c LinkList.h
	$(CC) -c main.c LinkList.h

LinkList.o: LinkList.c
	$(CC) -c LinkList.c

run: 
	./program

clean:
	rm *.o
	rm *~

memtest:
	valgrind --leak-check=yes ./program
