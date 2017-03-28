#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 500

void readline(FILE* worldFile, char *cp){
	char char_buff[MAX_BUFFER];
	
	cp = fgets(char_buff, MAX_BUFFER, worldFile);
	while (cp != NULL){
		char* index = strchr(cp, ' ');
		printf("%s\n", index-1);
		//printf("%s", cp);
		cp = fgets(char_buff, MAX_BUFFER, worldFile);
		
		
	}
}

int main(int argc, char* argv[])
{
	char* line[MAX_BUFFER];
	
	if(argc == 2){
		FILE* worldFile = fopen(argv[1], "r");
		if (worldFile == NULL) {
			fprintf(stderr, "Missing or invalid world file.\n");
		}
		
		else{
			readline(worldFile, *line);
			printf("%s\n", *line);
		}
		
	} else {
		printf("Missing or invalid world file.\n");
	}
	
	return EXIT_SUCCESS;
}


