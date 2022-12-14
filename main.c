#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
void draw_table(int board[]) {
	printf("- - - - - - -\n");
	for (int i = 0; i < 9; i++) {
		printf("|");
		for (int j = 0; j < 9; j++) {
			if (board[9 * i + j] == 0) {
				printf("-");
			}
			else {
				printf("%d", board[9 * i + j]);
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
void asign_value(int board[],int value,int row, int column) {
	board[9 * row + column] = value;
}
void insert_to_table(int board[]) {
	bool istrue = false;
	int value=0;
	int row=0, column=0;
	while (istrue!=true) {

		printf("Insert value from %d to %d:", 1, 9);
		scanf_s("%d", &value);
		printf("Which row from %d to %d:", 1, 9);
		scanf_s("%d", &row);
		printf("Which column from %d to %d:", 1, 9);
		scanf_s("%d", &column);
		if (value < 1 || value>9|| row < 1 || row>9|| column < 1 || column>9) {
			printf("You entered wrong values.Please try again.\n");
		}
		else {
			istrue = true;
		}
	}
	asign_value(board, value, row-1, column-1);
}
void main() {
	int board[81];
	memset(board,0,sizeof(board));
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