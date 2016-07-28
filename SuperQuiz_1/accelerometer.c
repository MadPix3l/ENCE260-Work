/*
 * Super Quiz 1 ENCE260
 * @author Tyler Holland
 * Last Edited: 28/07/2016
 */

#include <stdio.h>

/*
 * calculates peak magnitudes of
 *  acceleration
 */

int main(void)
{

    int input = 0;
    int peak = 0;
    int previous = 0;
    int t = 0;

    printf("Number  Magnitude\n");

    do {
        scanf("%u", &input);

        if (input != -1 && input >= peak) {
            peak = input;
        } else if (input != -1 && input < peak && previous == peak) {
            t += 1;
            printf("%4.u%11.u\n", t, peak);
        } else {
            peak = previous;
        }

        previous = input;

    } while (input != -1);

    return 0;
}
