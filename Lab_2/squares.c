#include <stdio.h>
int main(void)
{
	int i;
	int number = 0;
	
	scanf("%d", &number);
	for (i = 1; i < number+1; i++){
		printf("%d\n", i*i);
	}
	return 0;
}
