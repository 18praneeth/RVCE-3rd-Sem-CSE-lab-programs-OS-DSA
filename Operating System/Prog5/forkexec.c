#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>


int main(int argc, char* argv[]){
	if(argc!=3){
		printf("Usage: execl <int1> <int2>\n");
		exit(0);
	}
	
	pid_t pid;
	pid = fork();
	
	if(pid < 0){
		printf("Fork Failed\n");
		exit(0);
	}
	else if(pid == 0){
		printf("Child: \n");
		execv("sum_diff", argv);
		exit(0);		
	}
	else{
		wait(0);
		printf("\nParent: \n");
	}
	
	return 0;	
}












