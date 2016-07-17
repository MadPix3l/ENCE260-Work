#include <stdio.h>
#include <math.h>

int main(void)
{
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	double first_root = 0.0;
	double second_root = 0.0;
	double discriminant = 0.0;
	
	scanf("%lf%lf%lf", &a, &b, &c);
	discriminant = b*b-4*a*c;
	if (a == 0.0){
		printf("Not a quadratic");
		return 0;
	}
	else if(discriminant < 0){
		printf("Imaginary roots");
		return 0;
		
	}
	else 
	{
		first_root = (-b + sqrt(discriminant)) / (2*a);
		second_root = (-b - sqrt(discriminant)) / (2*a);
		if (first_root < second_root)
		{
			printf("Roots are %.4lf and %.4lf", first_root, second_root);
		} 
		else 
		{
			printf("Roots are %.4lf and %.4lf", second_root, first_root);
		}
		
		return 0;
		
	}
	
	
}
