#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
    int x, y;
    x = fork();
    if (x == 0)
    {
        printf("PID of child process is %d and its parent is %d\n", getpid(), getppid());
        printf("In child Process X value is %d\n", x);
        exit(0);
    }
    else
    {
        wait();
        printf("PID of Parent process is %d and its parent is %d\n", getpid(), getppid());
        printf("In Parent Process X value is %d\n", x);
        y = fork();
        if (y == 0)
        {
            printf("PID of child process is %d and its parent is %d\n", getpid(), getppid());
            printf("In child Process X value is %d\n", x);
            exit(0);
        }
        else
        {
            wait();
            printf("PID of Parent process is %d and its parent is %d\n", getpid(), getppid());
            printf("In Parent Process X value is %d\n", x);
            exit(0);
        }
    }
}
