#include <stdio.h>
#include <stdlib.h>


double discriminant(double a, double b, double c)
{
	return (b*b)-(4*a*c);
}
int main(void)
{
	printf("%.2lf\n", discriminant(1, 2, 3));
	printf("%.2lf\n", discriminant(1.5, 1.5, 1.5));
	return EXIT_SUCCESS;
}
