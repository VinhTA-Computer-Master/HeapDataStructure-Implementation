EXEC = run
CC = g++
CFLAGS = -Wall -c


$(EXEC): main.o Heap.o util.o
	$(CC) -o $(EXEC) main.o Heap.o util.o
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
Heap.o: Heap.h Heap.cpp
	$(CC) $(CFLAGS) Heap.cpp Heap.h
util.o: util.h util.cpp
	$(CC) $(CFLAGS) util.cpp util.h
clean:	
	rm -f *.o *.gch
