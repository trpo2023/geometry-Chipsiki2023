CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD -I "source"

all: exe

exe: main libmylib.a
	$(CC) ./obj/main/main.o -L./obj/libs -lmylib -o ./bin/exe $(CFLAGS)

main: source/main/main.c
	$(CC) ./source/main/main.c -c -o ./obj/main/main.o $(CFLAGS)

libmylib.a: mylib source/mylib/mylib.h
	ar ./obj/libs/libmylib.a ./obj/mylib/mylib.o ./source/mylib/mylib.h rcs

mylib: source/mylib/mylib.c
	$(CC) ./source/mylib/mylib.c -c -o ./obj/mylib/mylib.o $(CFLAGS)

clean:
	rm ./obj/main/main.o ./obj/libs/libmylib.a ./obj.mylib/mylib.o ./bin/exe

-include main.d mylib.d

