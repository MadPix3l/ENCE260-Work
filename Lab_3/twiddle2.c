/* An improved (but incomplete) version of twiddle.c that
 * doesn't use external (global) variables.
 * Written for ENCE260 June 2011, June 2013, July 2015.
 * Author: Richard Lobb
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 80

// Read a name (or any string) into the parameter array.
// Terminate it with null.
void readName(int maxLen, char name[])
{
    char c = '\0';
    int i = 0;
    printf("Enter your name: ");
    c = getchar();
    while (c != '\n' && i < maxLen - 1) {
        name[i++] = c;
        c = getchar();
    }
    name[i++] = '\0';  /* terminator */
}

void convertStringToUpper(char name[])
{
	int i = 0;
	while(name[i] != '\0'){
		name[i] = toupper(name[i]);
		i++;
	} 
	
}

int main(void)
{
	char testString[] = "aB0X?";
	convertStringToUpper(testString);
	printf("%s\n", testString);
    char name[MAX_NAME_LENGTH];
    readName(MAX_NAME_LENGTH, name);
    convertStringToUpper(name);
    printf("Your name in upper case: %s\n", name);	
    return EXIT_SUCCESS;
}
