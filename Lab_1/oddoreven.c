#include <stdio.h>

#define EVEN 2

int main(void)
{
	int number = 0;
	scanf("%d", &number);
	
	if (number == 0)
	{
		puts("Zero");
	}
	else if (number % EVEN == 0)
	{
		puts("Even");
	}
	else
	{
		puts("Odd");
	}
}
