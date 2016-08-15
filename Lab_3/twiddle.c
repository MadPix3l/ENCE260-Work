/* A program to demonstrate the (mis)use of external
 * variables. Reads a name (well, any string of chars,
 * really), converts it to upper case, then prints it
 * out.
 * Written for ENCE260, June 2011/July 2015
 * Author: Richard Lobb
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 80
char name[MAX_NAME_LENGTH];

// Read a name (or any string) into the external "name" array.
// Terminate it with null.
void readName()
{
    char c = '\0';
    int i = 0;
    printf("Enter your name: ");
    while ((c = getchar()) != '\n' && i < MAX_NAME_LENGTH - 1) {
        name[i++] = c;
    }
    name[i++] = '\0';  /* terminator */
}

// Convert the global "name" string to upper case
void convertNameToUpper()
{
    int i = 0;
    while (name[i] != '\0') {
        name[i] = toupper(name[i]);
        i++;
    }
}


int main(void)
{
    readName();
    convertNameToUpper();
    printf("Your name in upper case: %s\n", name);  
    return EXIT_SUCCESS;
}
