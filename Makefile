CC = gcc
CFLAGS = -c -Wall

APPNAME = tcg

SRC = $(wildcard src/*.c)

build: $(SRC)
		$(CC) -lcurl -lexpat -o $(APPNAME) $(SRC)

run: build
	./$(APPNAME)

clean:
		rm *o $(APPNAME)