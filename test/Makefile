CC=cc
test: algorithm vector valgrind
algorithm:
	$(CC) ./src/test-algorithm.c lib/*.c && ./a.out
vector: vector-int vector-struct-point
vector-int:
	$(CC) ./src/test-vector-int.c ./src/vector-int.c lib/*.c && ./a.out
vector-struct-point:
	$(CC) ./src/test-vector-struct-point.c ./src/vector-struct-point.c lib/*.c && ./a.out
valgrind:
	$(CC) ./src/test-vector-int.c ./src/vector-int.c lib/*.c && valgrind ./a.out && $(CC) ./src/test-vector-struct-point.c ./src/vector-struct-point.c lib/*.c && valgrind ./a.out
clean:
	rm a.out
