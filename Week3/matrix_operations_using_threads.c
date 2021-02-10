#include <stdio.h>
#include <pthread.h>

int a[10][10], b[10][10], c[10][10], d[10][10];
int m, n;
int x, y;

void matrix_read()
{
    int i, j;
    printf("Enter matrix size :\n");
    scanf("%d%d", &m, &n);

    printf("\nEnter A matrix:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("\nEnter B matrix:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &b[i][j]);

    printf("\nEnter C matrix:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &c[i][j]);

    printf("\nEnter the value of x:\n");
    scanf("%d", &x);
    printf("\nEnter the value of y:\n");
    scanf("%d", &y);
}

void *check(void *arg)
{
    long int num = (long int)arg;
    int i, j;
    int sum = 0, pro = 1;

    if (num == 0)
    {
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                d[i][j] = a[i][j] * x - b[i][j] * y + c[i][j];

        printf("\nAx-By + C is\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
                printf("%d ", d[i][j]);
            printf("\n");
        }
    }
    else if (num == 1)
    {
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                if ((j + 1) % 2 != 0)
                    sum = sum + a[i][j];

        printf("\nSum of odd colums of A - %d\n", sum);
    }
    else
    {

        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                if ((i + 1) % 2 != 0)
                    pro = pro * b[i][j];
        printf("\nProduct of odd rows of B - %d\n", pro);
    }
}

int main()
{
    pthread_t tid[5];

    long int it;

    matrix_read();

    for (it = 0; it < 3; it++)
        pthread_create(&tid[it], NULL, check, (void *)it);

    for (it = 0; it < 3; it++)
        pthread_join(tid[it], NULL);

    return 0;
}