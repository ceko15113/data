#include <stdio.h>

#define SIZE 15
#define N 5

void print_board(int board[][SIZE])
{
	int i, j;

	printf(" ");
	for (i = 0; i < SIZE; i++) printf("%d", i % 10);
	printf("\n");

	for (i = 0; i < SIZE; i++) {
		printf("%d", i % 10);
		for (j = 0; j < SIZE; j++) {
			if (board[i][j] == 1) printf("○");
			else if (board[i][j] == -1) printf("×");
			else printf(" ");
		}
		printf("\n");
	}
}

void mark_board(int board[][SIZE], int turn) {
	int height, width;

	if (turn == 1) printf("先手の番です\n");
	else printf("後手の番です\n");

	while (1) {
		printf("縦位置は？");
		scanf("%d", &height);
		printf("横位置は？");
		scanf("%d", &width);
		if (0 <= height && height < SIZE
			&& 0 <= width && width < SIZE
			&& board[height][width] == 0) break;
		printf("そこには置けません\n");
	}

	board[height][width] = turn;
}

int judge(int board[][SIZE])
{
	int i, j, k, m, n, p1cnt, p2cnt;

	for (i = 0; i < SIZE; i++) {
		p1cnt = p2cnt = 0;
		for (j = 0; j < SIZE; j++) {
			if (board[i][j] == 1) p1cnt++;
			else p1cnt = 0;

			if (board[i][j] == -1) p2cnt++;
			else p2cnt = 0;
			
			if (p1cnt == N) return 1;
			if (p2cnt == N) return -1;
		}
	}

	for (i = 0; i < SIZE; i++) {
		p1cnt = p2cnt = 0;
		for (j = 0; j < SIZE; j++) {
			if (board[j][i] == 1) p1cnt++;
			else p1cnt = 0;

			if (board[j][i] == -1) p2cnt++;
			else p2cnt = 0;

			if (p1cnt == N) return 1;
			if (p2cnt == N) return -1;
		}
	}

	for (i = 0; i < SIZE; i++) {
		p1cnt = p2cnt = 0;
		for (j = 0; j < SIZE; j++) {
			if (board[i][j] != 0) {
				for (m = i, n = j, k = 0; k < N; m++, n++, k++) {
					if (board[m][n] == 1) p1cnt++;
					else p1cnt = 0;

					if (board[m][n] == -1) p2cnt++;
					else p2cnt = 0;

					if (p1cnt == N) return 1;
					else if (p2cnt == N) return -1;
				}
			}
		}
	}

	for (i = 0; i < SIZE; i++) {
		p1cnt = p2cnt = 0;
		for (j = 0; j < SIZE; j++) {
			if (board[i][j] != 0) {
				for (m = i, n = j, k = 0; k < N && 0 <= n; m++, n--, k++) {

					if (board[m][n] == 1) p1cnt++;
					else p1cnt = 0;

					if (board[m][n] == -1) p2cnt++;
					else p2cnt = 0;

					if (p1cnt == N) return 1;
					if (p2cnt == N) return -1;
				}
			}
		}
	}

	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			if (board[i][j] == 0) return 0;

	return -2;
}

void print_message(int result)
{
	if (result == 1) printf("先手の勝ちです\n");
	else if (result == -1) printf("後手の勝ちです\n");
	else printf("引き分けです\n");
}

int main()
{
	int board[SIZE][SIZE] = {};
	int turn = 1;
	int result;

	print_board(board);

	while ((result = judge(board)) == 0) {
		mark_board(board, turn);
		print_board(board);
		turn *= -1;
	}

	print_message(result);

	return 0;
}
