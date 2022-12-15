#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 9
#define true 1
#define false 0
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
	int istrue = false;
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
	int check = false;
	while (check == false) {
		ask_for_value(board, &value, &row, &column);
		check = isviable(board, value, column-1, row-1);
		if (check == false) {
			printf("You entered value that's not viable.Please try again.\n");
		}
	}
	asign_value(board, value, row-1, column-1);
}
int isviablerow(int board[N][N],int value,int row) {
	int boolean = true;
	for (int i = 0; i < N; i++) {
		if (board[row][i] == value) {
			boolean = false;
			break;
		}
	}
	return boolean;
}
int isviablecolumn(int board[N][N], int value, int column) {
	int boolean = true;
	for (int i = 0; i < N; i++) {
		if (board[i][column] == value) {
			boolean=false;
			break;
		}
	}
	return boolean;
}
int isviablebox(int board[N][N], int value, int row, int column) {
	int localrow = row - row % 3;
	int localcolumn = column - column % 3;
	for (int i = localrow; i < localrow + 3; i++) {
		for (int j = localcolumn; j < localcolumn + 3; j++) {
			if (board[i][j] == value) {
				return false;
			}
		}
	}
	return true;
}
int isviable(int board[N][N],int value,int column,int row) {
	int boolean = false;
	if (isviablerow(board, value, row) && isviablecolumn(board, value, column)&& isviablebox(board, value, row, column)) {
		boolean=true;
	}
	return boolean;
}
int solve_board(int board[N][N]) {
	for (int row = 0; row < 9; row++) {
		for (int column = 0; column < 9; column++) {
			if (board[row][column] == 0) {
				for (int try = 1; try <= N; try++) {
					if (isviable(board, try, column, row)) {
						board[row][column] = try;
						if (solve_board(board)) {
							return true;
						}
						else {
							board[row][column] = 0;
						}
					}
				}
				return false;
			}
		}
	}
}
void write_to_file(int board[N][N]) {
	FILE* file;
	file = fopen("results.txt", "a");
	fprintf(file,"\nint board[N][N] = {\n");
	for (int i = 0; i < 9; i++) {
		fprintf(file,"{");
		for (int j = 0; j < 9; j++) {
			if (j == 8) {
				fprintf(file,"%d", board[i][j]);
			}
			else {
				fprintf(file,"%d,", board[i][j]);
			}
		}
		if (i == 8) {
			fprintf(file,"}\n");
		}
		else {
			fprintf(file,"},\n");
		}
	}
	fprintf(file,"};");
	fclose(file);
	printf("Solved table was copied to results.txt\n");
}
void main() {
	int board[N][N] = {
		{0,0,7,4,9,1,6,0,5},
		{2,0,0,0,6,0,3,0,9},
		{0,0,0,0,0,7,0,1,0},
		{0,5,8,6,0,0,0,0,4},
		{0,0,3,0,0,0,0,9,0},
		{0,0,6,2,0,0,1,8,7},
		{9,0,4,0,7,0,0,0,2},
		{6,7,0,8,3,0,0,0,0},
		{8,1,0,0,4,5,0,0,0} 
	};
	
	/*int board[N][N];
	memset(board, 0, sizeof(board));
	int istrue = false;
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
	}*/
	/*/int istrue = false;
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
	}*/
	draw_table(board);
	printf("\n\n\n");
	if (solve_board(board)) {
		printf("Board has been solved\n");
		draw_table(board);
		write_to_file(board);
	}
	else{
		printf("Board is not solvable\n");
	}
}