#include <stdio.h>

char* mystrrchr(char* s, int c)
{
	int found = 0;
	int result = 0;
	for(int i = 0; s[i] != '\0'; i++){
		
		if (s[i] ==  c){
			result = i;
			found = 1;
		}
	
	}
	if (found == 0){
		return NULL;
	}
	else{
		return &s[result];
	}
}

int main(void)
{
	char* s = "ENCN260";
	char* foundAt = mystrrchr(s, 'E');
	if (foundAt == NULL) {
		puts("Not found");
	}
	else {
		printf("%zd\n", foundAt - s);
	}
	return 0;
}
