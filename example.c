#include "minibench.h"

void f1() {
    int k = 1;
    for (int z=0; z<100; z++) {
        k ^= z + 1;
    }
}

void f2() {
    int k = 1;
    for (int z=0; z<1000; z++) {
        k ^= z + 1;
    }
}

BENCHMARK(10,
    TIMED("test1", f1();)
    TIMED("test2", f2();)
)
