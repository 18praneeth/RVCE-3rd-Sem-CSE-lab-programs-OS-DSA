#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 9000

int main(int argc, char const* argv[]){
	if(argc != 3){
		printf("Usage: a.out <sourcefile> <destinationfile>\n");
		return 1;
	}
	
	int input_fd, output_fd, ret_in, ret_out;
	char buffer[BUF_SIZE];
	
	input_fd = open(argv[1], O_RDONLY);
	if(input_fd == -1){
		perror("open");
		return 2;
	}
	output_fd = open(argv[2], O_WRONLY | O_CREAT, 0644);
	if(output_fd == -1){
		perror("open");
		return 3;
	}
	
	//copy process
	while((ret_in = read(input_fd, &buffer, BUF_SIZE)) > 0){
		ret_out = write(output_fd, &buffer, ret_in);
		if(ret_in != ret_out){
			perror("write");
			return 4;
		}
	}
	
	close(input_fd);
	close(output_fd);
	
	return 0;
}


