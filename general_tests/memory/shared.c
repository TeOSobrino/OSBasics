#define _GNU_SOURCE // to include MAP_ANON or MAP_ANONYMOUS
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>

#define PAGESIZE 4096
int n = 10;

void not_shared(void)
{
        if (fork() == 0) {
                n = 50;
        } else {
                wait(NULL);
        }
        printf("not shared %i\n", n);
}

/*
https://stackoverflow.com/questions/34042915/what-is-the-purpose
-of-map-anonymous-flag-in-mmap-system-call
//MAP_ANON is required to map directly on memory, else -> create a file and
use that file increase it's size with mmap
*/

void shared(void)
{
        uint32_t addr = 0xceba4f00;
        uint32_t *shared_block =
            mmap((void *)(&(addr)), PAGESIZE, PROT_READ | PROT_WRITE,
                 MAP_SHARED | MAP_ANON, -1, 0);

        *(shared_block) = 9;

        if (fork() == 0) {
                *(shared_block) = 30;
                n = 50;
        } else {
                wait(NULL);
        }
        printf("not shared %i\n", n);
        printf("shared %i\n", *(shared_block));
}
int main(void)
{
        shared();
        return 0;
}
