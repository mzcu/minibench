#include "minibench.h"

// On my arm64 mac, resolution of clock_gettime is 1us which
// is insufficient for benchmarking syscalls (see example-linux.c for that)

int state = 0;

void loop(int times) {
    for (int i=0; i<times; i++) {
        state ^= i + state;
    }
}

BENCHMARK(25,
    // warmup
    { loop(1000);  }
    // measured
    TIMED("loop(1000)", loop(1000);)
    TIMED("loop(10000)", loop(10000);)
)
