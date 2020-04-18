CC=gcc
CFLAGS=-g -std=c99 -pedantic -Wall -Wextra -fPIC
HEADERS=htab.h htab_table.h

all: tail libhtab.so

*.o: *.c
	$(CC) $(CFLAGS) -c $<

#pr1
tail: tail.o
	$(CC) $(CFLAGS) -o tail tail.o
tail.o: tail.c

#pr2
libhtab.so: htab_hash_fun.o htab_init.o htab_size.o htab_bucket_count.o htab_find.o htab_lookup_add.o
	$(CC) $(CFLAGS) -shared $^ -o $@

htab_hash_fun.o: htab_hash_fun.c $(HEADERS)
htab_init.o: htab_init.c $(HEADERS)
htab_size.o: htab_size.c $(HEADERS)
htab_bucket_count.o: htab_bucket_count.c $(HEADERS)
htab_find.o: htab_find.c $(HEADERS)
htab_lookup_add.o: htab_lookup_add.c $(HEADERS)

clean:
	rm -f *.o tail