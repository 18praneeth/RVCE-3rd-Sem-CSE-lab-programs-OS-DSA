#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>


int main(int argc, char const* argv[]){
	int fd;
	
	struct flock filelock;
	
	if(argc != 2){
		printf("Usage: <a.out> <filename>\n");
		return -1;
	}
	
	fd = open(argv[1], O_RDWR);
	
	if(fd == -1){
		printf("Error while opening the file\n");
		exit(0);
	}
	
	filelock.l_type = F_WRLCK;
	filelock.l_whence = SEEK_SET;
	filelock.l_start = 0;
	filelock.l_len = 100;
	
	printf("Press Enter to set to lock\n");
	getchar();
	printf("Trying to get lock\n");
	
	if(fcntl(fd, F_SETLK, &filelock) == -1){
		fcntl(fd, F_GETLK, &filelock);
		printf("File already locked by (PID): %d\n", filelock.l_pid);
		exit(0);
	}
	printf("LOCKED!!\n");
	
	printf("Press Enter to release lock\n");
	getchar();
	filelock.l_type = F_UNLCK;
	printf("Trying to unlock the file\n");
	
	if(fcntl(fd, F_SETLK, &filelock) == -1){
		printf("Unable to get lock\n");
		exit(0);
	}
	
	printf("File Unlocked\n");
	
	close(fd);
	
	return 0;	
}

