.PHONY: all run

CC = gcc
CCFLAGS = -lm -Wall -Wextra -O3
ENG = engine.c
GAME = skel.c
OUT = engine


all:
	$(CC) -o $(OUT) $(GAME) $(ENG) $(CCFLAGS)

run:
	./$(OUT)
