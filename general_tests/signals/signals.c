#include <stdio.h>
#include <unistd.h>
#include <signal.h>
//sigaction is preferred over signal
#include <stdlib.h>

//signal 13 is ^c -> this won't kill the program
void handler(int num)
{
        //inside signal handlers only async signal safe functions can be used
        write(STDOUT_FILENO, "I won't be killed.", 13);
}
//instead kill it using another terminal and $kill pid
//another handler can be used to handle sigterm, but sigkill is not handable
//using $kill -9 pid or $kill -KILL pid
int main(void)
{
        signal(SIGINT, handler);
        while(1){
                printf("wasting time. %d\n", getpid());
                sleep(1);
        }
        return 0;
}