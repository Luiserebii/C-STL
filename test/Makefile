CFLAGS = -g3 -Wall -Wextra -Wstrict-prototypes

test: algorithm string vector valgrind
algorithm:
	$(CC) $(CFLAGS) ./src/algorithm/*.c lib/*.c && ./a.out
string:
	$(CC) $(CFLAGS) ./src/string/*.c ../src/*.c lib/*.c && ./a.out
vector: vector-int vector-struct-point
vector-int:
	$(CC) $(CFLAGS) ./src/vector/test-vector-int.c ./src/vector/vector-int.c lib/*.c && ./a.out
vector-struct-point:
	$(CC) $(CFLAGS) ./src/vector/test-vector-struct-point.c ./src/vector/vector-struct-point.c lib/*.c && ./a.out
valgrind:
	$(CC) ./src/vector/test-vector-int.c ./src/vector/vector-int.c lib/*.c && valgrind ./a.out
	$(CC) ./src/vector/test-vector-struct-point.c ./src/vector/vector-struct-point.c lib/*.c && valgrind ./a.out
	$(CC) ./src/string/*.c ../src/*.c lib/*.c && valgrind ./a.out
clean:
	rm a.out
