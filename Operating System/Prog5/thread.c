#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sum = 0;

void *func(void *arg){
	int n = atoi(arg);
	for(int i=1; i<=n; i++)
		sum+=i;
	pthread_exit(0);
}

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Usage: a.out <num>\n");
		exit(0);
	}
	pthread_t tid;
	pthread_create(&tid, NULL, func, argv[1]);
	pthread_join(tid, NULL);
	printf("Sum of %d natural number is %d\n", atoi(argv[1]), sum);
	return 0;
}
