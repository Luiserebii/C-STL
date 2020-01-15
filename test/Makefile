test: algorithm vector valgrind
algorithm:
	cc ./src/test-algorithm.c lib/*.c && ./a.out
vector: 
	cc ./src/test-vector.c ./src/vector-int.c lib/*.c && ./a.out
valgrind:
	cc ./src/test-vector.c ./src/vector-int.c lib/*.c && valgrind ./a.out 
clean:
	rm a.out
