#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>

#define MAX 5

sem_t in_sem;
sem_t rm_sem;

void* producer(){
	int count = 0;
	while(1){
		sem_wait(&in_sem);
		sleep(3);
		printf("Producer inserted at %d\n", count % MAX + 1);
		count ++;
		sem_post(&rm_sem);		
	}
}

void* consumer(){
	int count = 0;
	while(1){
		sem_wait(&rm_sem);
		sleep(3);
		printf("Producer consumed at %d\n", count % MAX + 1);
		count ++;
		sem_post(&in_sem);
	}
}


int main(){
	pthread_t threads[2];
	sem_init(&in_sem, 0, MAX);
	sem_init(&rm_sem, 0, 0);
	
	pthread_create(&threads[0], NULL, producer, NULL);
	pthread_create(&threads[1], NULL, consumer, NULL);
	
	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	
	sem_destroy(&in_sem);
	sem_destroy(&rm_sem);
	
	return 0;
}
