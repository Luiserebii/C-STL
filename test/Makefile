INCLUDE_FLAGS=-I../include
CFLAGS = -g3 -Wall -Wextra -Wstrict-prototypes $(INCLUDE_FLAGS)


test: algorithm string vector valgrind
algorithm:
	$(CC) $(CFLAGS) ./src/algorithm/*.c lib/*.c && ./a.out
string:
	$(CC) $(CFLAGS) ./src/string/*.c ../src/*.c lib/*.c && ./a.out
vector: vector-int vector-struct-point
vector-int:
	$(CC) $(CFLAGS) ./src/vector/test-vector-int.c ./src/vector/vector-int.c ../src/*.c lib/*.c && ./a.out
vector-struct-point:
	$(CC) $(CFLAGS) ./src/vector/test-vector-struct-point.c ./src/vector/vector-struct-point.c ../src/*.c lib/*.c && ./a.out
valgrind:
	$(CC) $(INCLUDE_FLAGS) ./src/vector/test-vector-int.c ./src/vector/vector-int.c ../src/* lib/*.c && valgrind ./a.out
	$(CC) $(INCLUDE_FLAGS) ./src/vector/test-vector-struct-point.c ./src/vector/vector-struct-point.c ../src/* lib/*.c && valgrind ./a.out
	$(CC) $(INCLUDE_FLAGS) ./src/string/*.c ../src/*.c lib/*.c && valgrind ./a.out

.PHONY: clean
clean:
	rm a.out
