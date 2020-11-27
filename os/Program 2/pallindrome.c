#include <stdio.h>

int main(int argc, char *argv[])
{

int num, reverse_num=0, remainder, temp;

num = atol(argv[1]);
temp=num;

while(temp!=0){
	remainder = temp%10;
	reverse_num = reverse_num*10 + remainder;
	temp /= 10;
}

if(reverse_num==num)
	printf("\n%d is a palindrome number",num);
else
	printf("\n%d is not a palindrome number",num);
return 0;
}