#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear_console() {
    system("@cls||clear");
}

int check_winner(int matrix[3][3]) {
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && (matrix[1][1] == 1 || matrix[1][1] == 2)) {
        return matrix[1][1];
    } else if (
            matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0] && (matrix[1][1] == 1 || matrix[1][1] == 2)
            ) {
        return matrix[1][1];
    }
    for (int i = 0; i < 3; ++i) {
        if (matrix[0][i] && matrix[1][i] && matrix[2][i]) {
            int sum = matrix[0][i] + matrix[1][i] + matrix[2][i];
            if (sum == 3 || sum == 6) {
                return sum / 3;
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (matrix[i][0] && matrix[i][1] && matrix[i][2]) {
            int sum = matrix[i][0] + matrix[i][1] + matrix[i][2];
            if (sum == 3 || sum == 6) {
                return sum / 3;
            }
        }
    }
    if (
            matrix[0][0] && matrix[0][1] && matrix[0][2] &&
            matrix[1][0] && matrix[1][1] && matrix[1][2] &&
            matrix[2][0] && matrix[2][1] && matrix[2][2]
            ) {
        return 3;
    }
    return 0;

}

int output_matrix(int matrix[3][3]) {
    clear_console();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (matrix[i][j] == 0) {
                printf(" ");
            } else if (matrix[i][j] == 1) {
                printf("X");
            } else if (matrix[i][j] == 2) {
                printf("O");
            }
            if (j != 2) {
                printf("|");
            }
        }
        printf("\n");
    }

    return 0;
}

// get computer move
int get_computer_move(int matrix[3][3]) {
    int x, y;
    do {
        x = rand() % 3;
        y = rand() % 3;
    } while (matrix[x][y] != 0);
    matrix[x][y] = 2;
    return 0;
}

int main() {
    int matrix[3][3];
    int winner = 0;
    int turn = 1;
    int x, y;
    srand(time(NULL));

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = 0;
        }
    }

    int error = 0;
    while (winner == 0) {

        if (turn == 1) {
            if (error) {
                printf("Error! Please enter correct coordinates!\n");
                error = 0;
            }
            output_matrix(matrix);
            printf("Please enter x and y: ");
            scanf("%d %d", &x, &y);
            if (matrix[x][y] == 0) {
                matrix[x][y] = 1;
                turn = 2;
            } else {
                error = 1;
            }
        } else if (turn == 2) {
            get_computer_move(matrix);
            turn = 1;
        }
        winner = check_winner(matrix);
    }
    output_matrix(matrix);
    if (winner == 1) {
        printf("You won!\n");
    } else if (winner == 2) {
        printf("Computer won!\n");
    } else if (winner == 3) {
        printf("Draw!\n");
    }
}