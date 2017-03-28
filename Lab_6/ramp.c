
#include <stdio.h>
#include <stdlib.h>

int* ramp(int n)
{
	
	int* val_list = malloc(n * sizeof(int));
	for(int i = 0; i < n; i++) {
		val_list[i] = i+1;
	}
	return val_list;
}
int main(void)
{
	int n = 0;
	scanf("%d", &n);
	int* data = ramp(n);
	for (int i = 0; i < n; i++) {
		printf("%d ", data[i]);
	}
	free(data);
	return EXIT_SUCCESS;
}
