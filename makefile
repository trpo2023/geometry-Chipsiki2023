all: exe

exe: main.o libmylib.a
	gcc main.o -L. -lmylib -o exe

main.o: main.c
	gcc main.c -c -o main.o

libmylib.a: mylib.c mylib.h
	ar rsc libmylib.a mylib.c mylib.h

-include main.d mylib.d

