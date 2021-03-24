#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>

int main(){
	DIR *d; 
	struct dirent *de;
	struct stat buf;
	int i, j;
	char P[10] = "rwxrwxrwx", AP[10] = " ";
	struct passwd *p;
	struct group *g;
	struct tm *t;
	char time[26];

	d = opendir(".");

	while(de=readdir(d)){
		stat(de->d_name, &buf);

		if(S_ISDIR(buf.st_mode))
		printf("d");
		else if(S_ISREG(buf.st_mode))
		printf("-");
		else if(S_ISCHR(buf.st_mode))
		printf("c");
		else if(S_ISBLK(buf.st_mode))
		printf("b");
		else if(S_ISLNK(buf.st_mode))
		printf("l");
		else if(S_ISFIFO(buf.st_mode))
		printf("p");
		else if(S_ISSOCK(buf.st_mode))
		printf("s");


		for(i=0, j=(1<<8); i<9; i++, j>>=1){
			AP[i] = (buf.st_mode & j ) ? P[i] : '-';
		}

		printf("%s",AP); //FILE PERMISSITION
		printf("\t%ld",buf.st_nlink ); // NUMBER OF HARD LINKS
		p = getpwuid(buf.st_uid);
		printf("\t%s",p->pw_name ); // USER NAME
		g = getgrgid(buf.st_gid);
		printf("\t%s", g->gr_name); //GROUP NAME
		printf("\t%ld", buf.st_size); //FILE SIZE
		printf("\t%-15s", de->d_name ); //NAME
		printf("\t%s", ctime(&buf.st_mtime));
	}
}
