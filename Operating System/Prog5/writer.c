#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>


#define N 10

int process[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int r_count = 0;

sem_t rw_sem;
sem_t rc_sem;


void* reader(void *num){
	int n = *(int *)num;
	sem_wait(&rc_sem);
	
	if(!r_count){
		printf("Waiting for reading\n");
		sem_wait(&rw_sem);
	}
	r_count ++;
	sem_post(&rc_sem);
	
	printf("Process %d is reading\n", n+1);
	sleep(2);
	
	sem_wait(&rc_sem);
	
	r_count --;
	if(!r_count){
		printf("Finished Reading\n");
		sem_post(&rw_sem);
	}
	sem_post(&rc_sem);	
	
}


void* writer(void *num){
	int n = *(int *)num;
	printf("Waiting for writing\n");
	sem_wait(&rw_sem);
	printf("Process %d is writing\n", n+1);
	sleep(4);
	printf("Finished writing\n");
	sem_post(&rw_sem);
}


int main(){
	pthread_t threads[N];
	
	sem_init(&rw_sem, 0, 1);
	sem_init(&rc_sem, 0, 1);
	
	for(int i = 0; i<N; i++){
		if( i == 1 || i == 7){
			pthread_create(&threads[i], NULL, writer, &process[i]);
			continue;
		}
		pthread_create(&threads[i], NULL, reader, &process[i]);
	}
	
	for(int i=0; i<N; i++)
		pthread_join(threads[i], NULL);
		
	sem_destroy(&rw_sem);
	sem_destroy(&rc_sem);
	
	return 0;	
}



