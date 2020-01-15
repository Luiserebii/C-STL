test: algorithm vector valgrind
algorithm:
	cc test-algorithm.c lib/*.c && ./a.out
vector: 
	cc test-vector.c lib/*.c && ./a.out
valgrind:
	cc test-vector.c lib/*.c && valgrind ./a.out 
clean:
	rm a.out
