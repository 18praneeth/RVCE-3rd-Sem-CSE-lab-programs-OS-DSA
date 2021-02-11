#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<fcntl.h>
#include<unistd.h>

#define No_READERS 5
#define No_WRITER 2
pthread_mutex_t mutex;
sem_t rw_lock;
int read_count;
int fp;
char buffer[100];

void *Writer(void *arg)
{
long int num = (long int) arg;
int i=0;


{
sem_wait(&rw_lock);

if(num==0)
{
for(i=1;i<5;i++)
{
char f[3];
f[0]=i+48;
f[1]='0';
f[2]='  ';
printf("Writer number %ld is writing %c%c\n",num,f[0],f[1]);
write(fp,f,3);
}
}
else if(num==1)
{
for(i=5;i<9;i++)
{
char f[3];
f[0]=i+48;
f[1]='0';
f[2]='  ';
write(fp,f,3);
printf("Writer number %ld is writing %c%c\n",num,f[0],f[1]);
}
}
sleep(1);
sem_post(&rw_lock);
}
}

void *Reader(void *arg)
{
long int num=(long int)arg;
int i,n;


{
pthread_mutex_lock(&mutex);
read_count++;
if(read_count==1)
sem_wait(&rw_lock);
pthread_mutex_unlock(&mutex);
// perform read

//sleep(2);
lseek(fp,SEEK_SET,0);
if((n=read(fp,buffer,100))>0)
{
buffer[n+1]='\0';
printf("The reader thread %ld is reading \n",num);
printf("It read %s\n",buffer);
}

pthread_mutex_lock(&mutex);
read_count--;
if(read_count==0)
sem_post(&rw_lock);
pthread_mutex_unlock(&mutex);
}
}


void main()
{
  pthread_t rid[No_READERS],wid[No_WRITER];
  long int i;
  
  fp=open("test",O_RDWR|O_CREAT,0777);
  
  pthread_mutex_init(&mutex,NULL);
  sem_init(&rw_lock,0,1);
  for(i=0;i<No_WRITER;i++)
  pthread_create(&wid[i],NULL,Writer,(void *)i);
  for(i=0;i<No_READERS;i++)
  pthread_create(&rid[i],NULL,Reader,(void *)i);
  
  
 
  for(i=0;i<No_READERS;i++)
  pthread_join(rid[i],NULL);
  
  for(i=0;i<No_WRITER;i++)
  pthread_join(wid[i],NULL); 
  
  pthread_mutex_destroy(&mutex);
  sem_destroy(&rw_lock);
  close(fp);
}
