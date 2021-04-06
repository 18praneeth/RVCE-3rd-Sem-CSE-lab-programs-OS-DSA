#include<stdio.h>
int main()
{
	int x,y,result;
	printf("Enter x : ");
	scanf("%d",&x);
	printf("Enter y : ");
	scanf("%d",&y);
	result = sum(x,y);
	printf("Sum of 2 numbers : %d\n",result);
	result=difference(x,y);
	printf("Difference of 2 numbers : %d\n",result);
	return 0;
}
