#include <stdio.h>
#include <stdlib.h>


int isWonRow(char player, char game[3][3], int rowNum);

int main(void)
{
	char game[3][3] = {{'X', 'O', ' '},{'X', 'X', 'X'}, {' ', ' ', ' '}};
	printf("%d\n", isWonRow('X', game, 1));
	char game2[3][3] = {{'X', 'O', ' '},{' ', ' ', ' '}, {'X', 'X', 'O'}};
	printf("%d\n", isWonRow('X', game2, 2)); 
}

int isWonRow(char player, char game[3][3], int rowNum)
{
	int isWon = 1;
	for (int i = 0; i < 3; i++){
		if (game[rowNum][i] != player){
			isWon = 0;
		}
		else {
			isWon = 1;
		}
	}
	return isWon;
}
