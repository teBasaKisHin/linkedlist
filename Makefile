main.out: main.o LinkedList.o LinkedList.h
	gcc -o main.out main.o LinkedList.o

LinkedList: LinkedList.o LinkedList.j
	gcc -o LinkedList LinkedList.o

main.o: main.o LinkedList.h
	gcc -c main.c

LinkedList.o: LinkedList.c LinkedList.h
	gcc -c LinkedList.c
