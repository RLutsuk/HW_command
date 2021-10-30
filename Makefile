OBJS	 = main.o algorithm.o benchmark.o utils.o
SOURCE	 = main.c algorithm.c benchmark.c utils.c
HEADER	 = includes/algorithm.h includes/benchmark.h inclues/utils.h
OUT_DIR	 = out
OUT      = $(OUT_DIR)/sort
CC	     = gcc
FLAGS	 = -g -c -Wall
LFLAGS   = -lm

all: $(OBJS) | mkdir
	$(CC) -g $(OUT_DIR)/* -o $(OUT) $(LFLAGS)

main.o: main.c | mkdir
	$(CC) $(FLAGS) main.c -o $(OUT_DIR)/main.o -std=c11

algorithm.o: algorithms.c | mkdir
	$(CC) $(FLAGS) algorithms.c -o $(OUT_DIR)/algorithms.o -std=c11

benchmark.o: benchmark.c | mkdir
	$(CC) $(FLAGS) benchmark.c -o $(OUT_DIR)/benchmark.o -std=c11

utils.o: utils.c | mkdir
	$(CC) $(FLAGS) utils.c -o $(OUT_DIR)/utils.o -std=c11

mkdir:
	mkdir $(OUT_DIR)

clean:
	rm -rf $(OUT_DIR)
