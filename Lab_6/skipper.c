#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* skipping(const char* s)
{
	char* c = malloc(strlen(s));
	int counter = 0;
	for(int i = 0; i < strlen(s); i++){
		if (i%2 == 0 && s[i] != 0){
			c[counter] = s[i];
		} else {
			counter += 1;
		}
	}
	c[counter] = '\0';
	return c;
}

int main(void)
{
	char* s = skipping("0123456789");
	printf("%s\n", s);
	free(s);
	return EXIT_SUCCESS;
}
