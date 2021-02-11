#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
	int input_fd, output_fd;

	if (argc != 3){
		printf("\nUsage: mv oldfile newfile");
		return 1;
	}

	input_fd = link(argv[1], argv[2]);

	if(input_fd == -1){
		perror("Link error");
		return 2;
	}

	output_fd = unlink(argv[1]);

	if (output_fd == -1){
		perror("Unlink");
		return 3;
	}

	return (EXIT_SUCCESS);
}
