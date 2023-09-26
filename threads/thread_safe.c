/*
  Thread safety is important, avoiding race conditions is the only way to 
  assure the code will be executed correctly when we have multiple threads
 
  This programs illustrates that not always threads improve runtime
  sharing a unique variable that is only being incremented shows how the overhead
  of mutexes can decrease the performance.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define BIG 10000000UL

unsigned int counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* count(void *arg);

int main(void)
{
        pthread_t thread;
        pthread_create(&thread, NULL, count, NULL);
        count(NULL);
        printf("counter = ");
        pthread_join(thread, NULL);
        printf("%u\n", counter);
        return 0;
}

void* count(void *arg)
{
        for(int i = 0; i < BIG; i++){
                pthread_mutex_lock(&lock);
                counter++;
                pthread_mutex_unlock(&lock);
        }
        return NULL;
}