CC = gcc
CFLAGS = -I/usr/include -Iinclude/ -O2
LDFLAGS = -lraylib -lm -ldl -lpthread -lGL -lrt -lX11
SRC = src/*.c
OUT = sim

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)
