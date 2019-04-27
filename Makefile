main: main.o LinkedList.o
	gcc -o main main.o LinkedList.o

LinkedList: LinkedList.o
	gcc -o LinkedList LinkedList.o

main.o: main.o LinkedList.h
	gcc -c main.c

LinkedList.o: LinkedList.c LinkedList.h
	gcc -c LinkedList.c
