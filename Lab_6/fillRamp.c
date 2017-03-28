
#include <stdio.h>
#include <stdlib.h>

void fillRamp(int* data, int n)
{
	for(int i = 0; i < n; i++) {
		data[i] = i+1;
	}

}

int main(void)
{
	int n = 0;
	scanf("%d", &n);
	int* data = malloc(n);
	fillRamp(data, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", data[i]);
	}
	free(data);
	return EXIT_SUCCESS;
}
