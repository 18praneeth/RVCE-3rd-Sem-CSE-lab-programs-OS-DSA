#include<stdio.h>
#include "calc.h"
int main(void)
{
    int x = 5;
    int y = 8;
    int result;
    result = sum(x, y);

    printf("%d\n",result);

    result = diff(x,y);

    printf("%d\n",result);
sleep(100);

    return (0);
}
