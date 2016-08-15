// A test program for the "findTwoLargest" function

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void findTwoLargest(const int a[], int n, int* largest, int* secondLargest)
{
	
	for(int i = 0; i < n; i++){
		
		if(a[i] >= *largest ){
			*secondLargest = *largest;
			*largest = a[i];
			
		} else if (a[i] <= *largest && a[i] >= *secondLargest){
			
			*secondLargest = a[i];
		}
	}
}


void printArray(const int a[], int n)
// Print the first n elements of array a in braces, comma-separated
{
    if (n <= 0) {
        printf("{}");
    }
    else {      
        printf("{%d", a[0]);
        for (int i = 1; i < n; i++) {
            printf(",%d", a[i]);
        }
        printf("}");
    }
}

void test_array(const int a[], int n)
// Test the function findTwoLargest on array 'a' of length 'n.
// It is assumed that n >= 2.

{
    int largest = 0, second = 0;

    findTwoLargest(a, n, &largest, &second);
    printf("The two largest elements from ");
    printArray(a, n);
    printf(" are %d and %d\n", largest, second);
}


// Lastly, the main test routine.
int main()
{
	int data[] = {5, 4};
	int result1 = 0, result2 = 0;
	findTwoLargest(data, 2, &result1, &result2);
	printf("%d %d\n", result1, result2);
	printf("%d %d\n", data[0], data[1]);
}
