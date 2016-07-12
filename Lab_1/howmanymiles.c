#include <stdio.h>

#define CONVERSION 1.609344

int main(void){
	float miles = 0.0;
	float kilometers = 0.0;
	scanf("%f", &miles);
	
	kilometers = miles * CONVERSION;
	printf("That's %.2f km.\n", kilometers);
	
	return 0;
}
