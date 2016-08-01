#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


int main(void)
{
	int counts[26] = {0};
	int c = 0;
	
	do {
		c = getchar();
		
		if (isalpha(c)){	
			c = toupper(c);
			counts[c-'A'] += 1;
		}
		
	} while(c != -1);
	
	for(int i = 0; i < 26; i++){
		
		printf("%c: %d\n", 'A'+i, counts[i]);
	}
	
	return EXIT_SUCCESS;
}
