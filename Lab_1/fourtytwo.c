#include <stdio.h>

int main(void)
{
	int numbers = 0;
	do 
	{
		scanf("%d", &numbers);
		printf("%d\n", numbers);
	}
	while (numbers != 42);
	return 0;
}
