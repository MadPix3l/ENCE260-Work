/* Simple array demo program.
 * Also demonstrates sizeof.
 * Reads a line of input characters into a 1D array
 * of 'char', then writes the line out backwards.
 * Written for ENCE260 by RJL.
 * February 2011, June 2013, July 2015, June 2016
 */

#include <stdio.h>
#include <stdlib.h>

#define N_MAX 100

int main(void)
{
	double ayy = 0.0;
    char line[N_MAX] = { '\0' };        // An array of char, init'ed to zero
    int c = 0;                  // An int with a char in its low byte
    int n = 0;
	
	printf("size of double %ld", sizeof ayy);
    printf("Variable n requires %zd bytes of memory\n", sizeof n);
    printf("Array line occupies %zd bytes of memory\n", sizeof line);

    printf("Enter a line of text, terminated by 'Enter'\n");
    // Read characters until EOF, newline or buffer full

    c = getchar();              /* Get char (cast to int) or EOF */
    while (c != EOF && c != '\n') {
        line[n] = c;
        n += 1;
        c = getchar();
    }

    // Now print out all those characters backwards

    printf("Your input line, written backwards, is:\n");
    for (int i = n - 1; i >= 0; i--) {
        putchar(line[i]);
    }
    putchar('\n');

    return EXIT_SUCCESS;
}
