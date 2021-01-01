#include<stdio.h>
// #include "calc.h"

// int sum(int a, int b);
// int diff(int a, int b);
int main(void)
{
    int x = 5;
    int y = 8;
    int result;
    result = sum(x, y);

    printf("%d\n",result);

    result = diff(x,y);

    printf("%d\n",result);
    return (0);
}
