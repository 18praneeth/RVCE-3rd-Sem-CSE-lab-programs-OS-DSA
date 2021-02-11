#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>


#define BUF_SIZE 8192



int main(int argc, char const *argv[])
{
	int input_fd, output_fd;  //Input and out put file discriptor

	ssize_t ret_in, ret_out; // Number of bytes returened

	char buffer[BUF_SIZE];  //Character buffer

	if(argc != 3){
		printf("\nUsage: cp source_file destination_file");
		return 1;
	}


	//INput file Descriptor
	input_fd = open(argv[1], O_RDONLY);

	if (input_fd == -1){
		perror("open");
		return 2;
	}

	//Output file Descriptor
	output_fd = open(argv[2], O_WRONLY | O_CREAT , 0644);
	if (output_fd == -1){
		perror("open");
		return 3;
	}

	//Copy Process

	while((ret_in = read(input_fd, &buffer, BUF_SIZE)) > 0){
		ret_out = write(output_fd, &buffer, (ssize_t) ret_in);

		if (ret_out != ret_in){
			perror("write");
			return 4;
		}
	}


	close(input_fd);
	close(output_fd);

	return (EXIT_SUCCESS);
}
