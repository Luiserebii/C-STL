test: algorithm vector valgrind
algorithm:
	cc ./src/test-algorithm.c lib/*.c && ./a.out
vector: vector-int vector-struct-point
vector-int:
	cc ./src/test-vector-int.c ./src/vector-int.c lib/*.c && ./a.out
vector-struct-point:
	cc ./src/test-vector-struct-point.c ./src/vector-struct-point.c lib/*.c && ./a.out
valgrind:
	cc ./src/test-vector-int.c ./src/vector-int.c lib/*.c && valgrind ./a.out 
clean:
	rm a.out
