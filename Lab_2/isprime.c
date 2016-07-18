#include <stdio.h>
#include <stdbool.h>

int main(void) {
	int n1 = 0;
	int n2 = 0;
	int notPrime;
	scanf("%d%d", &n1, &n2);
	for (int i = n1; i <= n2; i++){
		notPrime = false;
		for (int j = 2; j <= i/2; ++j){
			if (i%j == 0){
				notPrime = true;
			}
		}
		if(notPrime == false){
			printf("%d\n", i);
		}
	}
	return 0;
}
