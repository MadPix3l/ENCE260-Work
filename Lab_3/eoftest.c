/*
 * file that loops until getchar receives EOF
 * @author Tyler Holland
 */
 
#include <stdio.h>
#include <stdlib.h> 

int main(void)
{
	int c = 0;
	
	while((c = getchar()) != EOF){
		printf("%d\n", c);
	}
	
	return EXIT_SUCCESS;

}
