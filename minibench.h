#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#include "ministat.h"


#define BENCHMARK(iters, ...) int main(int argc, char *argv[]) { \
    int N = iters;                                               \
    int MAX_TESTS = 7;                                           \
    int tests = -1;                                              \
    double results[MAX_TESTS][N];                                \
    const char *names[MAX_TESTS];                                \
    __VA_ARGS__                                                  \
    ministat(2, tests+1, N, results, names);                     \
    return 0;                                                    \
}

#define TIMED(name, ...)                                         \
    {                                                            \
        tests += 1;                                              \
        struct timespec before;                                  \
        struct timespec after;                                   \
        names[tests] = name;                                     \
        for (int i=0; i<N; i++) {                                \
            clock_gettime(CLOCK_MONOTONIC, &before);             \
            __VA_ARGS__                                          \
            clock_gettime(CLOCK_MONOTONIC, &after);              \
            results[tests][i] = (after.tv_sec - before.tv_sec)*1000000000UL + (after.tv_nsec - before.tv_nsec); \
        }                                                        \
    }
