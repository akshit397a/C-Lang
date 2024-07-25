#include <stdio.h>
#define SIZE 3
int i,j;
void printBoard(char board[SIZE][SIZE]) {
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---|---|---\n");
    }
}

int checkWin(char board[SIZE][SIZE], char player) {
    for (i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }

    return 0;
}

int main() {
    char board[SIZE][SIZE] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char player = 'X';
    int moves = 0;

    while (1) {
        printBoard(board);
        printf("Player %c, enter your move (1-9): ", player);
        int move;
        scanf("%d", &move);

        int row = (move - 1) / SIZE;
        int col = (move - 1) % SIZE;

        if (move < 1 || move > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row][col] = player;
        moves++;

        if (checkWin(board, player)) {
            printBoard(board);
            printf("Player %c wins!\n", player);
            break;
        }

        if (moves == 9) {
            printBoard(board);
            printf("It's a draw!\n");
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
