#include <stdio.h>

int main(void)
{
	
	//unsigned int t = 0;
	int input = 0;
	int peak = 0;
	int previous = 0;
	int i = 0;
	printf("Number  Magnitude\n");
	do {
		scanf("%u", &input);
		if(input >= peak) {
			peak = input;
		} else if (input != -1 && input < peak && previous == peak) {
			i += 1;
			printf("%4.u%11.u\n", i, peak);
		} else {
			peak = previous;
		}
		previous = input;
	} while(input != -1);
	return 0;
}
