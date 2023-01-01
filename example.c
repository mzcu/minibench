#define _GNU_SOURCE
#include "minibench.h"
#include <sched.h>
#include <sys/syscall.h>

unsigned int cpu;
unsigned int node;


void syscall_getcpu() {
    syscall(SYS_getcpu, &cpu, &node);
}

void vdso_getcpu() {
    getcpu(&cpu, &node);
 }

BENCHMARK(25,
    // warmup
    { vdso_getcpu(); syscall_getcpu(); }
    // measured
    TIMED("vdso-getcpu (default)", vdso_getcpu();)
    TIMED("syscall-getcpu", syscall_getcpu();)
)
