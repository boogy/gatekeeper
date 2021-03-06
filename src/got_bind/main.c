#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "bind_now.h"

int main(int argc, char** argv) {
    if(argc < 2) {
        printf("Usage: %s <dir> argv0 argv1\n", argv[0]);
        exit(1);
    }
    set_bind_now();
    execvp(argv[1], &argv[1]);
}
