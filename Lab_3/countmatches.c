#include <stdio.h>
#include <stdlib.h>

int countMatches(int n, int data[], int searchValue);

int main(void)
{
	int nums[] = {10, 20, 30}; 
	printf("%d\n", countMatches(3, nums, 1));
	int nums2[] = {1, 2, 3, 4, 1, 1, 5}; 
	printf("%d\n", countMatches(7, nums2, 1));
	return EXIT_SUCCESS;
}

int countMatches(int n, int data[], int searchValue)
{
	int freq = 0;
	for(int i = 0; i < n; i++){
		if(data[i] == searchValue){
			freq++;
		}
	}
	return freq;

}
