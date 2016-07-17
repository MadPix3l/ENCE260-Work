#include <stdio.h>

int main(void)
{
	float rushHeight;
	float screeHeight;
	float slideBack;
	float total = 0.0;
	int count = 0;
	scanf("%f%f%f", &screeHeight, &rushHeight, &slideBack);
	while (total < screeHeight){
		count++;
		total += rushHeight;
		if (total >= screeHeight)
			break;
		total -= slideBack;
	}
	printf("%d", count);
	return 0;	
}
