//exec -> create a child process that runs another program
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

void basic_proc(void);

int main (void)
{
        basic_proc();
}

void basic_proc(void)
{
        if( fork() == 0){
                printf("I'm a child\n");
                execlp("ls", "ls", "-al", NULL);
                printf("bananas\n"); //this never will be executed
        }
        else{
                printf("I'm a parent\n");
        }
        printf("Hello, world! %d\n", getpid());

}

