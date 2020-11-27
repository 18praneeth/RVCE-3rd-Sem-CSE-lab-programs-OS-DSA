#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
	int fd;
	char buffer[255];
	struct flock fvar;

	if(argc == 1){
		printf("Usage: %s filename\n",argv[0] );
		return -1;
	}

	if((fd = open(argv[1], O_RDWR)) == -1){
		perror("open");
		exit(1);
	}

	fvar.l_type=F_WRLCK;
	fvar.l_whence = SEEK_END;
	fvar.l_start = SEEK_END - 100;
	fvar.l_len = 100 ;
	printf("Press enter to set lock\n");
	getchar();
	printf("Trying to get lock ....\n");
	while((fcntl(fd, F_SETLK, &fvar)) == -1){
		fcntl(fd, F_GETLK, &fvar);
		printf("File already locked by process (pid): %d\n", fvar.l_pid);
	}
	printf("locked\n");

	if((lseek(fd, SEEK_END-50, SEEK_END)) == -1){
		perror("lseek");
		exit(1);
	}

	if((read(fd, buffer, 100)) == -1){
		perror("read");
		exit(1);
	}
	printf("Data from the file\n");
	puts(buffer);
	printf("Press enter to release lock\n");
	getchar();
	fvar.l_type = F_UNLCK;
	fvar.l_whence = SEEK_SET;
	fvar.l_start = 0;
	fvar.l_len = 0;

	if((fcntl(fd, F_UNLCK, &fvar)) == -1){
		perror("fcntl");
		exit(0);
	}
	printf("Unlocked\n");
	close(fd);

	return 0;
}
