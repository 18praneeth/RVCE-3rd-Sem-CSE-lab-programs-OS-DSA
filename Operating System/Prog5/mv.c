#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char const* argv[]){
	if(argc != 3){
		printf("Usage: <old_file> <new_file>\n");
		return 1;
	}
	
	int fd;
	fd = link(argv[1], argv[2]);
	fd = unlink(argv[1]);
	
	return 0;
}
