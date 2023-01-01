OS=$(shell uname -s | tr '[A-Z]' '[a-z]')

example-benchmark: example.o
	$(CC) $< -o $@.out -lm

run: example-benchmark
	./example-benchmark.out

%.o : %-$(OS).c
	$(CC) -c $< -o $@

clean:
	$(RM) *.o *.out
