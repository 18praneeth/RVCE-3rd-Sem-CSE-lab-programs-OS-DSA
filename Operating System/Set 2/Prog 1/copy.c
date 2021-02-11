#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/types.h>
#include<unistd.h>

#define BUF_SIZE 8192

int main(int argc, char* argv[])
{
   int old_fd, new_fd;
   int ret_old, ret_new;
   char buffer[BUF_SIZE];

   if(argc != 3){
   	printf("usage: cp file1 file2\n");
   	return 1;
   }
   old_fd = open(argv[1], O_RDONLY);
   if(old_fd == -1){
   	perror("open");
   	return 2;
   }

   new_fd = open(argv[2], O_WRONLY | O_CREAT, 0644);
   if(new_fd == -1){
   	perror("open");
   	return 3;
   }

   while((ret_old = read(old_fd, &buffer, BUF_SIZE))>0)
   {
   	ret_new = write(new_fd, &buffer, (int)ret_old);
   	if(ret_old != ret_new){
   		perror("write");
   		return 4;
   	}

   }

    close(old_fd);
    close(new_fd);
    return (EXIT_SUCCESS);
}