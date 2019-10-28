all: main.o LinkList.o
	gcc -o program main.o LinkList.o

main.o: main.c LinkList.h
	gcc -c main.c LinkList.h

LinkList.o: LinkList.c
	gcc -c LinkList.c

run: 
	./program

clean:
	rm *.o
	rm *~