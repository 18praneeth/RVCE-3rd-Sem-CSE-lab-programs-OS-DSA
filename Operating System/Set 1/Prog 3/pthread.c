#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define MAX 2
char str[10];
char substring[3];

void *subString(void *arg)
{
    long int n = (long int)arg;
    printf("Thread : %ld \n",n);
    for (int i = n * 5; i < (n + 1) * 5 - 3; i++)
    {
        if (str[i] == substring[0])
        {
            if (str[i + 1] == substring[1] && str[i + 2] == substring[2])
                printf("Substring found at : %d\n", i + 1);
        }
    }
}

int main()
{
    int maxs = 0;
    int i;
    pthread_t tid[MAX];
    printf("Enter the String : ");
    scanf("%s", str);
    printf("Enter the Substring : ");
    scanf("%s", substring);

    for (i = 0; i < MAX; i++)
        pthread_create(&tid[i], NULL, subString, (void *)i);

    for (i = 0; i < MAX; i++)
        pthread_join(tid[i], NULL);
}
