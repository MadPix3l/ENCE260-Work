/*
 * file that loops until getchar receives EOF
 * @author Tyler Holland
 */
 
#include <stdio.h>
#include <stdlib.h> 

#define UPPERCASE 64
#define LOWERCASE 96

int main(void)
{
	int c = 0;
	
	while((c = getchar()) != EOF){
		if(48 <= c  && c <= 57){
			printf("'%c': Digit %c\n", c, c);
			
		} else if ((65 <= c && c <= 90)){
			printf("'%c': Letter %d\n", c, c-UPPERCASE);
		
		} else if(97 <= c && c <= 122){
			 printf("'%c': Letter %d\n", c, c-LOWERCASE);
			 
		} else if (c == 10){
			printf("'\\n'\n");
			
		} else {
			printf("'%c': Non-alphanumeric\n", c);
		}
	}
	
	return EXIT_SUCCESS;

}
