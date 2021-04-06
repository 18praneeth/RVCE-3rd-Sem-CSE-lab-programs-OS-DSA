#include <stdio.h>
#include <pthread.h>
#define size 15

int ar[size];
int sum =0;

void entermat()
{
int i;
printf("\n Enter the elements for matrix\n");
for(i=0; i<15; i++)
scanf("%d", &ar[i]);
}

void * operation(void * arg)
{ 
int j;
long int num=(long int) arg;
printf("Threads %ld\n", num);
for(j=((num)*15)/4; j<((num+1)*15)/4;j++)
if(ar[j]%2!= 0)
sum +=ar[j];

}

int main()
{
entermat();
pthread_t t[20];
long int c;
for(c=0; c<4; c++)
pthread_create(&t[c], NULL, operation, (void*)c);
for(c=0; c<4; c++)
pthread_join(t[c], NULL);

printf("Total sum = %d\n", sum);
return 0;
}
