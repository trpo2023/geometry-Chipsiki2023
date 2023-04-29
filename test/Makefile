CC=gcc

all: test

remake: clean all

%.c.o: %.c ctest.h
	$(CC) -c -o $@ $<

test: main.c.o ctest.h test.c.o
	$(CC) main.c.o test.c.o -o test

clean:
	rm -f test *.o
