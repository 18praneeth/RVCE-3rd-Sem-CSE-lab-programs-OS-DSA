#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2

#define LEFT(i) (((i)+4)%N)
#define RIGHT(i) (((i) + 1)%N)

int phil[N] = {0, 1, 2, 3, 4};
int p_state[N] = {};
sem_t eat_sem[N];
sem_t st_sem;


void test(int n){
	if(p_state[n] == HUNGRY && p_state[LEFT(n)] != EATING && p_state[RIGHT(n)] != EATING){
		p_state[n] = EATING;
		printf("Philosopher %d is taking chopsticks %d and %d\n", n+1, n+1, LEFT(n) + 1);
		printf("Philosopher %d is eating\n", n+1);
		sem_post(&eat_sem[n]);
	}
}


void keep_fork(int n){
	sem_wait(&st_sem);
	p_state[n] = THINKING;
	printf("Philosopher %d is taking chopsticks %d and %d\n", n+1, n+1, LEFT(n) + 1);
	printf("Philosopher %d is eating\n", n+1);
	test(LEFT(n));
	test(RIGHT(n));
	sem_post(&st_sem);	
}

void take_fork(int n){
	sem_wait(&st_sem);
	p_state[n] = HUNGRY;
	printf("Philosopher %d is hungry\n", n+1);
	test(n);
	sem_post(&st_sem);
}

void* philosopher(void *num){
	int n = *(int *)num;
	printf("Philosopher %d is thinking\n", n+1);
	
	while(1){
		sleep(5);
		take_fork(n);
		sleep(1);
		sem_wait(&eat_sem[n]);
		keep_fork(n);
	}
}

int main(){
	pthread_t threads[N];
	sem_init(&st_sem, 0, 1);
	
	for(int i=0; i<N; i++)
		sem_init(&eat_sem[i], 0, 0);
		
	for(int i=0; i<N; i++)
		pthread_create(&threads[i], NULL, philosopher, &phil[i]);
		
	for(int i=0; i<N; i++)
		pthread_join(threads[i], NULL);
		
	sem_destroy(&st_sem);
	
	for(int i=0; i<N; i++)
		sem_destroy(&eat_sem[i]);	
}








