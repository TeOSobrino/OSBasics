#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void fun_1(void);
void fun_2(void);
void* thread_fun_1(void* ret); //threaded functions have to be in the form:
// (void *) fun(void* arg);

int main(void)
{
        pthread_t newthread;

        pthread_create(&newthread, NULL, thread_fun_1, NULL);       
        //fun_1();
        fun_2();
        
        pthread_join(newthread, NULL); //wait until the thread finishes
        
        return 0;
}

void fun_1(void)
{
        while(1){
                sleep(1);
                printf("fun 1\n");
        }
}

void fun_2(void)
{
        for(int i = 0; i < 4; i++){
                sleep(2);
                printf("fun 2\n");
        }
}

void* thread_fun_1(void* ret)
{
        while(1){
                sleep(1);
                printf("fun 1\n");
        }
        return NULL;
}