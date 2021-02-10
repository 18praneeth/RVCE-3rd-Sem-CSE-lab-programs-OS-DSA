#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
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
    printf("Child Process \n ");
    int fd;
    char buffer[100];
    struct flock filelock;
    if (argc == 1)
    {
        printf("Usage: %s filename\n", argv[0]);
        return -1;
    }
    fd = open(argv[1], O_RDWR | O_CREAT | O_APPEND, 0777);
    if (fd == -1)
    {
        printf("ERROR\n");
        return (0);
    }
    filelock.l_type = F_WRLCK;
    filelock.l_whence = SEEK_END;
    filelock.l_start = SEEK_END - 100;
    filelock.l_len = 100;
    printf("Press Enter to set lock by Child\n");
    getchar();
    printf("Trying to get lock\n");
    while (fcntl(fd, F_SETLK, &filelock) == -1)
    {
        fcntl(fd, F_GETLK, &filelock);
        printf("File already locked by (PID):%d\n", filelock.l_pid);
    }
    printf("LOCKED\n");
    if (lseek(fd, SEEK_END - 50, SEEK_END) == -1)
    {
        perror("lseek\n");
        exit(1);
    }
    if (read(fd, buffer, 100) != -1)
    {
        printf("Data Read\n");
        puts(buffer);
    }
    printf("Press Enter to release lock by Child\n");
    getchar();
    filelock.l_type = F_UNLCK;
    filelock.l_whence = SEEK_END;
    filelock.l_start = SEEK_END - 100;
    filelock.l_len = 100;
    if (fcntl(fd, F_UNLCK, &filelock) == -1)
    {
        perror("fcntl\n");
        exit(0);
    }
    printf("The file is unlocked\n");   
    return 0;
}
else
{
    printf("Parent Process\n");
    //wait(&res);
    int fd;
    char buffer[100];
    struct flock filelock;
    if (argc == 1)
    {
        printf("Usage: %s filename\n", argv[0]);
        return -1;
    }
    fd = open(argv[1], O_RDWR | O_CREAT | O_APPEND, 0777);
    if (fd == -1)
    {
        printf("ERROR\n");
        return (0);
    }
    filelock.l_type = F_WRLCK;
    filelock.l_whence = SEEK_END;
    filelock.l_start = SEEK_END - 100;
    filelock.l_len = 100;
    printf("Press Enter to set lock by Parent\n");
    getchar();
    printf("Trying to get lock\n");
    while (fcntl(fd, F_SETLK, &filelock) == -1)
    {
        fcntl(fd, F_GETLK, &filelock);
        printf("File already locked by (PID):%d\n", filelock.l_pid);
    }
    printf("LOCKED\n");
    if (lseek(fd, SEEK_END - 50, SEEK_END) == -1)
    {
        perror("lseek\n");
        exit(1);
    }
    if (read(fd, buffer, 100) != -1)
    {
        printf("Data Read\n");
        puts(buffer);
    }
    printf("Press Enter to release lock by Parent\n");
    getchar();
    filelock.l_type = F_UNLCK;
    filelock.l_whence = SEEK_END;
    filelock.l_start = SEEK_END - 100;
    filelock.l_len = 100;
    if (fcntl(fd, F_UNLCK, &filelock) == -1)
    {
        perror("fcntl\n");
        exit(0);
    }
    printf("The file is unlocked\n");   
    return 0;
}
}
