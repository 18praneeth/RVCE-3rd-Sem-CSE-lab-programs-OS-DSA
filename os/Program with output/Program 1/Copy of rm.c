#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>



int main(int argc, char const *argv[])
{
	int delete_fd;

	if (argc != 2){
		printf("\nUsage: rm file");
		return 1;
	}

	delete_fd = unlink(argv[1]);


	if (delete_fd == -1){
		perror("Unlink");
		return 1;
	}

	return (EXIT_SUCCESS);
}
