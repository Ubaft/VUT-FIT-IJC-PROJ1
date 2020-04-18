CC = gcc
CFLAGS= -g -std=c11 -pedantic -Wall -Wextra
all: tail

primes: tail.o
	$(CC) $(CFLAGS) -o tail tail.o
tail.o: tail.c
	$(CC) $(CFLAGS) -c tail.c
clean:
	rm -f *.o tail
