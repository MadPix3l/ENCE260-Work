#include <stdio.h>

int main(void) 
{
	int n1 = 0;
	int n2 = 0;
	int i;
	int j;
	int prime;
	
	scanf("%d%d", &n1, &n2);
	for(i = n1; i <= n2; i++){
		prime = 1;
		printf("WHY WONT YOU PRINT CUNT");
		for(j = 3; j<i; j++){
			if(j / i == 0){
				prime = 0;
				printf("%d\n", j / i);
			}
		}
		if (prime == 1){
			printf("%d\n", i);
		} else {
			printf("ruined");
		}
	}
	printf("DONE");
	return 0;
}
