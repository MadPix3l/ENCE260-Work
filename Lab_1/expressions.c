#include <stdio.h>
int main(void)
{
	int i = 1;
	int j = 10;
	int k = 100;
	
	printf("Initially, i, j, k = %d, %d, %d\n", i, j, k);
	j = i++;
	printf("After j = i++, i, j, k = %d, %d, %d\n", i, j, k);
	k = ++i;
	printf("After k = ++i, i, j, k = %d, %d, %d\n", i, j, k);
	i = --k;
	printf("After i = --k, i, j, k = %d, %d, %d\n", i, j, k);
	j = i--;
	printf("After j = i++, i, j, k = %d, %d, %d\n", i, j, k);
	i = (j = 20) + (k = 30);
	printf("i = (j = 20) + (k = 30), i, j, k = %d, %d, %d\n", i, j, k);
	
	return 0;
	
}
