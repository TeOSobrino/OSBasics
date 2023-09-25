//forking processes -> generating clones
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

void basic_proc(void);
void child_recognize(void);

int main (void)
{
        basic_proc();
        child_recognize();
}

void basic_proc(void)
{
        char slp = 0;
        if( fork() != 0){
                slp = 1;
        }
        printf("Hello, world! %d\n", getpid());
        if(slp == 1){
                sleep(1);
        }
}

void child_recognize(void)
{
        int x = 10;
        printf("initial function: x = %d\n", x);
        if( fork() == 0){
                printf("I'm a child process %d\n", getpid());
                x += 5;
                printf("child process: x = %d\n", x);
        }
        else{
                printf("I'm a parent. Big dad, old-ass process %d\n", getpid());
                x += 10;
                printf("parent process: x = %d\n", x);  
        }
        printf("function exit: x = %d\n", x);
}