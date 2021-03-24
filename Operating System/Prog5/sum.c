#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const* argv[]){
	int a = atoi(argv[1]);
	
	int sum = 0;
	for(int i=1; i<=a; i++)
		sum += i;
	
	printf("\nSum of %d natural number is: %d", a, sum);
	return 0;
}
