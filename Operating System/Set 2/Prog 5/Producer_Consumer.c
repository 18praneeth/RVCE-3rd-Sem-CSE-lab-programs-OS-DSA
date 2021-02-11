#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#define Prodcount 2
#define Conscount 2
#define Quesize 5
int in=0,out=0,i=0;
char s[]="rvcollege";
pthread_mutex_t mutex;
sem_t empty,full;
int q[Quesize];
void *prod(void *arg)
{
    long int num=(long int)arg;
    int f;
    for(f=0;f<4&&s[i]!='\0';f++)
    {
       sem_wait(&empty);
       pthread_mutex_lock(&mutex);
       q[in]=s[i];
       printf("Producer %ld has produced %c\n",num,q[in]);
       i=(i+1);
       in=(in+1)%Quesize;
       pthread_mutex_unlock(&mutex);
       sem_post(&full);
    }
}
void *cons(void *arg)
{
     long int num=(long int)arg;
     int f;
     for(f=0;f<3&&s[i]!='\0';f++)
     {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        printf("Consumer %ld has consumed %c\n",num,q[out]);
        
        out=(out+1)%Quesize;
        pthread_mutex_unlock(&mutex);
       sem_post(&empty);
     }
     
}
int main()
{
  pthread_t pid[Prodcount],cid[Conscount];
  long int i;
  pthread_mutex_init(&mutex,NULL);
  sem_init(&full,0,0);
  sem_init(&empty,0,Quesize);
  for(i=0;i<2;i++)
  pthread_create(&pid[i],NULL,prod,(void *)i);
   for(i=0;i<2;i++)
  pthread_create(&cid[i],NULL,cons,(void *)i);
   for(i=0;i<2;i++)
  pthread_join(pid[i],NULL);
  for(i=0;i<2;i++)
  pthread_join(cid[i],NULL);
  pthread_mutex_destroy(&mutex);
  sem_destroy(&full);
  sem_destroy(&empty);
  return 0;
  
}
