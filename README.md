# minibench

Tiny, zero-dependency, header-only microbenchmarking library for C.

Includes [ministat](https://www.freebsd.org/cgi/man.cgi?query=ministat) code for stats.

## Example (Linux)

This example shows speed difference for getting current cpuid between using (default)
[vdso](https://man7.org/linux/man-pages/man7/vdso.7.html) call and forcing the transition 
to kernel mode by using explicit system call instruction.

``` shell
$ make clean run
rm -f *.o *.out
cc -c example-linux.c -o example.o
cc example.o -o example-benchmark.out -lm
./example-benchmark.out

===== Running microbench =====
* system: Linux 5.15.0-56-generic x86_64
* resolution: 1ns
* iterations: 25
------------------------------
======= Ministat report ======
x vdso-getcpu (default)
+ syscall-getcpu
+--------------------------------------------------------------------------+
|                                                                   +      |
|                                                                   +      |
|                                                                   +      |
|                                                                   +      |
|                                                                   +      |
| x                                                                 +      |
| x     x                                                           +      |
| x     x                                                           +      |
| x     x                                                           +      |
| x     x                                                           +     +|
| x     x                                                           +     +|
| x     x                                                           +     +|
| x     x                                                           +     +|
| x     x                                                           +     +|
| x     x                                                           +     +|
| x     x                                                           +     +|
| x     x     x     x                                               +     +|
||____A_M_|                                                        |M_A__| |
+--------------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  25            20            50            30          26.4     7.5718778
+  25           130           140           130         133.2     4.7609523
Difference at 95.0% confidence
        106.8 +/- 3.59739
        404.545% +/- 13.6265%
        (Student's t, pooled s = 6.32456)

```

## Example (Darwin)

```shell
$ make clean run
rm -f *.o *.out
cc -c example-darwin.c -o example.o
cc example.o -o example-benchmark.out -lm
./example-benchmark.out

===== Running microbench =====
* system: Darwin 22.1.0 arm64
* resolution: 1000ns           
* iterations: 25           
------------------------------
======= Ministat report ======
x loop(1000)
+ loop(10000)
+--------------------------------------------------------------------------+
|x                                                                      +  |
|x                                                                      + +|
|x x                                                                    + +|
|x x                                                                    + +|
|x x                                                                    + +|
|x x                                                                    + +|
|x x                                                                    + +|
|x x                                                                    + +|
|x x                                                                    + +|
|x x                                                                    + +|
|x x                                                                    + +|
|x x                                                                    + +|
|x x                                                                    + +|
|MA|                                                                    MA||
+--------------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  25          3000          4000          3000          3440     506.62281
+  25         34000         35000         34000         34480     509.90195
Difference at 95.0% confidence
	31040 +/- 289.099
	902.326% +/- 8.40405%
	(Student's t, pooled s = 508.265)

```

