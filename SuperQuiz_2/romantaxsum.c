 /*
 * Tyler Holland ENCE260 
 * SuperQuiz 2
 * adds up denariis by converting roman
 * numerals to integers
 * Last Edited 16th August 2016
 */

#include <stdio.h>
#include <string.h>

#define MAX_BUFFER 80

/*
 * convertFromRoman(const char* s)
 * converts a string of roman numerals
 * to an integer
 */
 
int convertFromRoman(const char* s)
{
	
	int total = 0;
	int nan = 0;
	for(int i = 0; i < strlen(s); i++) {
		char numeral = s[i];
		if (nan == 1){
			total = 0;
			return 0;
		}
		else{
			if(numeral == 'M') {
				total += 1000;
				
			} else if (numeral == 'D') {
				total += 500;
				
			} else if (numeral == 'C') {
				total += 100;
				
			} else if (numeral == 'L') {
				total += 50;
				
			} else if (numeral == 'X') {
				total += 10;
				
			} else if (numeral == 'V') {
				total += 5;
				
			} else if (numeral == 'I') {
				total += 1;
				
			} else {
				total = 0;
				nan = 1;
				
			}
		}
	}
	return total;
}


/* 
 * takes input and parses it
 * it ignores any input that is
 * not a valid roman numeral followed
 * by a "dn","dn." or "dn,"
 */
int parseScroll()
{
	/* 
	 * These constant string array is used
	 *  to prevent a ridiculously long if statement
	 */
	const char* denarii[3] = {"dn","dn.","dn,"};
	int total = 0;
	char prev[MAX_BUFFER+1] = "";
	char string[MAX_BUFFER+1] = "";
	int value = 0;
	int is_currency = 0;
	
	while (scanf("%80s", string) != EOF) {
		string[MAX_BUFFER] = '\0';
		value = convertFromRoman(string);
		
		for(int i = 0; i < strlen(*denarii); i++) {
			
			if(strncmp(string, denarii[i], strlen(string)) == 0) {
				is_currency = 1;
			} else {
				is_currency = 0;
			}
		}
		if(value == 0 && is_currency == 1) {
			total += convertFromRoman(prev);
			strncpy(prev, string, strlen(string));
			
		} else if (value != 0 && is_currency != 1) {
			strncpy(prev, string, strlen(string));
			
		} else if (value == 0 && is_currency != 1){
			
			strncpy(prev, "", strlen(prev));
		}
	}
	return total;
}


int main(void)
{
	printf("%d\n",parseScroll());
	return 0;
}
