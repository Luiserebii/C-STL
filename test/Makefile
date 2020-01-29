CC=cc
test: algorithm vector valgrind
algorithm:
	$(CC) -g3 -Wall./src/algorithm/*.c lib/*.c && ./a.out
vector: vector-int vector-struct-point
vector-int:
	$(CC) -g3 -Wall ./src/vector/test-vector-int.c ./src/vector/vector-int.c lib/*.c && ./a.out
vector-struct-point:
	$(CC) -g3 -Wall ./src/vector/test-vector-struct-point.c ./src/vector/vector-struct-point.c lib/*.c && ./a.out
valgrind:
	$(CC) ./src/vector/test-vector-int.c ./src/vector/vector-int.c lib/*.c && valgrind ./a.out && $(CC) ./src/vector/test-vector-struct-point.c ./src/vector/vector-struct-point.c lib/*.c && valgrind ./a.out
clean:
	rm a.out
