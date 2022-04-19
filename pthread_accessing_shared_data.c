/*
Code that runs 5 threads and accesses global data.
To compile: gcc -std=c11 -lpthread pthreads.c
To run ./a.out -j12
*/

#include <pthread.h>
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#define NUM_THREADS 5
int global_data = 0;

void* PrintHello(void *threadid){
 printf("\n%d: Hello World!\n", threadid);
 for(int i = 0; i <100; i++){ 
	 global_data = i;
	 printf("%d\n\r", global_data);
	 sleep(0.1);
	 sched_yield();
 }
 pthread_exit(NULL);
}
int main (int argc, char *argv[]){
 pthread_t threads[NUM_THREADS];
 int args[NUM_THREADS];
 int rc, t;
 for(t=0;t < NUM_THREADS;t++){
 printf("Creating thread %d\n", t);
 args[t] = t;
 rc = pthread_create(&threads[t], NULL, PrintHello,
 (void *) args[t]);
 if (rc) {
 printf("ERROR; return code from pthread_create() is %d\n", rc);
 exit(-1);
 }
 }
 pthread_exit(NULL);
}
