#include <stdio.h>

int tokenCopy(char* dest, const char* src, int destSize)
{
	int i ;
	for(i = 0; i != destSize-1; i++){
		if (src[i] == '\0' || src[i] == ' '){
			break;
		}
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return i;
}

int main(void){
	char buff[10];
	int n = tokenCopy(buff, " ", 10);
	printf("%d '%s'\n", n, buff);
	return 0;
}
