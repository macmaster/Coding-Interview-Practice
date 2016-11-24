# makefile
# builds for my c++11 experiments

CC = g++
CFLAGS = -std=c++11 -O2 -o $@ -Wall -g
OBJ = main.o queue.o

test: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)

clean:
	rm $(OBJ)
	rm test
