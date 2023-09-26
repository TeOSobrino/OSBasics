//run the program using strace ($ strace ./a.out)
#include <stdio.h>
#include <stdlib.h>

#define KB 1024
#define MB KB*KB
#define GB MB*KB

#define SMALL_BLOCK 50*KB //small memory blocks should ariase call to brk()
#define BIG_BLOCK 5*MB //bigger blocks should call mmap()

//for a "very small" block only one call to brk will sufice, and this
//difference won't be noticeable 

int main (void)
{
        for(int i = 0; i < 10; i++){
                char* arr = malloc(SMALL_BLOCK);
                printf("Memory allocated, address = %p\n", arr);
                //free(arr); //freeing will cause the program to not work as we
                //want, since brk and mmap functionalities
        }
        return 0;
}

//brk bumps up the program break line in stack, (the usual way heap allocation
// is teached), mmap allocates a block of memory anywhere the os assigns