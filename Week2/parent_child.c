#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char *argv[])
{
    int res = 1;
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("Error generated\n");
    }
    if (pid == 0)
    {
        printf("Inside child process, Child PID= %d\n", getpid());
        printf("Inside child process, Parent PID= %d\n", getppid());
        execl("./encrypt", "encry", argv[1], argv[2], (char *)NULL);
    }
    else
    {
        printf("Inside parent process, Parent PID = %d\n", getpid());
        wait(&res);
        if (WIFEXITED(res) == 1)
        {
            printf("Terminates normally\n");
        }
        else
        {
            printf("AbNormal termination");
            exit(0);
        }
    }
}
