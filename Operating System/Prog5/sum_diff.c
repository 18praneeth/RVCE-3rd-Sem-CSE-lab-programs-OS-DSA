#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const* argv[]){
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	printf("\nSum: %d", a+b);
	printf("\nDiff: %d", a-b);
	return 0;
}
