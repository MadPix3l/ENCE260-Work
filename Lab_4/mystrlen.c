#include <stdio.h>

size_t mystrlen(const char* s)
{
	int count = 0;
	for(int i = 0; s[i] != '\0'; i++){
		count = i;
	}
	if (count != 0){
		count++;
	}
	return count;
}

int main(void)
{
	printf("%zd\n", mystrlen(""));
	return 0;
}
