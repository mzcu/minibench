example-benchmark: example.o
	$(CC) $< -o $@.out

run: example-benchmark
	./example-benchmark.out

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o *.out
