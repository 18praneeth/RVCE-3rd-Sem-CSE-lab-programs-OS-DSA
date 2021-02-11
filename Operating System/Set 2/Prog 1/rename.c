#include<stdio.h>
int main(int argc, char* argv[])
{
	int old_fd, new_fd;
	if(argc != 3)
	{
		printf("Usage: mv file1 file2");
		return 1;
	}
    old_fd = link(argv[1],argv[2]);
    if(old_fd == -1)
    {
    	perror("link error");
    	return 2;
    }
    new_fd = unlink(argv[1]);
    if(new_fd == -1)
    {
    	perror("unlink");
    	return 3;
    }




} 