#include <stdio.h>

void swap(int* p, int* q)
{
	int tempval = 0;
	tempval = *p;
	*p = *q;
	*q = tempval;
	
}

int main(void)
{
	int i = 10, j = 20;
	swap(&i, &j);
	printf("%d %d\n", i, j);
	return 0;

}
