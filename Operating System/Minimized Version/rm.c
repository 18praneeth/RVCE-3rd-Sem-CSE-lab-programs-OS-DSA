#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char const* argv[]){
	if(argc != 2){
		printf("Usage: <filename> \n");
		return 1;
	}
	
	int fd;
	fd = unlink(argv[1]);
	
	return 0;
}
