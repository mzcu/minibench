example-benchmark: example.o
	$(CC) $< -o $@.out -lm

run: example-benchmark
	./example-benchmark.out

%.o : %.c
	$(CC) -c $< -o $@

clean:
	$(RM) *.o *.out
