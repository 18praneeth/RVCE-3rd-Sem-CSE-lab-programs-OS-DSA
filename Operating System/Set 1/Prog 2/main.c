#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>


int main(int argc, char *argv[])
{
    printf("Inside main\n");
    int res = 1;
    pid_t pid = fork();

    if(pid<0)
    {
        printf("Error generated\n");
    } 

    if(pid==0)
    {
        printf("Inside child proces,PID=%d\n",getpid());
        execl("./pallin","encry",argv[1],argv[2],NULL);//second arg is just a reference name
    }

    else{
        printf("\nInside parent process ID =%d\n",getpid());
        wait(&res);
        if(WIFEXITED(res)==1)
        {
            printf("\nTerminates normally\n");
        }
        else{
        printf("\nAbNormal termination");
        exit(0);
        }

    }
}
