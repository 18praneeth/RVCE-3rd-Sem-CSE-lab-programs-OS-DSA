#include<stdio.h>
int main(int argc, char* argv[])
{
	int fd;
	fd = unlink(argv[1]);
	if(fd == -1)
	{
		perror("unlink error");
		return 3;
	}
}
