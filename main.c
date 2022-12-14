#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define N 9
void draw_table(int board[N][N]) {
	printf("- - - - - - -\n");
	for (int i = 0; i < 9; i++) {
		printf("|");
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == 0) {
				printf("-");
			}
			else {
				printf("%d", board[i][j]);
			}
			if (j % 3 == 2) {
				printf("|");
			}
		}
		if (i % 3 == 2) {
			printf("\n- - - - - - -");
		}
		printf("\n");
	}
}
void asign_value(int board[N][N],int value,int row, int column) {
	board[row][column] = value;
}
void ask_for_value(int board[N][N], int* value, int* row, int* column) {
	bool istrue = false;
	while (istrue != true) {
		printf("Insert value from %d to %d:", 1, 9);
		scanf_s("%d", value);
		printf("Which row from %d to %d:", 1, 9);
		scanf_s("%d", row);
		printf("Which column from %d to %d:", 1, 9);
		scanf_s("%d", column);
		if (*value < 1 || *value>9 || *row < 1 || *row>9 || *column < 1 || *column>9) {
			printf("You entered wrong values.Please try again.\n");
		}
		else {
			istrue = true;
		}
	}
}
void insert_to_table(int board[N][N]) {
	int row = 0, column = 0, value = 0;
	ask_for_value(board,&value,&row,&column);
	asign_value(board, value, row-1, column-1);
}
void main() {
	/*int board[N][N] = {
		{0,0,7,4,9,1,6,0,5},
		{2,0,0,0,6,0,3,0,9},
		{0,0,0,0,0,7,0,1,0},
		{0,5,8,6,0,0,0,0,4},
		{0,0,3,0,0,0,0,9,0},
		{0,0,6,2,0,0,1,8,7},
		{9,0,4,0,7,0,0,0,2},
		{6,7,0,8,3,0,0,0,0},
		{8,1,0,0,4,5,0,0,0} 
	};*/
	
	int board[N][N];
	memset(board, 0, sizeof(board));
	bool istrue = false;
	int go_on;
	while (istrue != true) {
		insert_to_table(board);
		printf("Do you want to enter another value?\n");
		printf("1.Yes\n");
		printf("2.No\n");
		scanf_s("%d", &go_on);
		if (go_on == 2) {
			istrue = true;
		}
	}
	draw_table(board);
}