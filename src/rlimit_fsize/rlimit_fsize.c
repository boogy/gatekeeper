#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

#include <sys/time.h>
#include <sys/resource.h>
int main(int argc, char** argv) {
    if(argc < 2) {
        printf("Usage: %s <limit> argv0 argv1\n", argv[0]);
        exit(1);
    }
    struct rlimit limit = {0,0};
    limit.rlim_cur = limit.rlim_max = atoi(argv[1]);
    setrlimit(RLIMIT_FSIZE, &limit);
    execvp(argv[2], &argv[2]);
}
