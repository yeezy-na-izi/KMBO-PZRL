#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear_console() {
    system("@cls||clear");
}

int check_winner(int matrix[3][3]) {
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && (matrix[1][1] == 1 || matrix[1][1] == 2)) {
        return matrix[0][0];
    }
    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0] && (matrix[1][1] == 1 || matrix[1][1] == 2)) {
        return matrix[0][2];
    }
    if (matrix[0][0] == matrix[0][1] && matrix[0][1] == matrix[0][2] && (matrix[0][0] == 1 || matrix[0][0] == 2)) {
        return matrix[0][0];
    }
    if (matrix[1][0] == matrix[1][1] && matrix[1][1] == matrix[1][2] && (matrix[1][0] == 1 || matrix[1][0] == 2)) {
        return matrix[1][0];
    }
    if (matrix[2][0] == matrix[2][1] && matrix[2][1] == matrix[2][2] && (matrix[2][0] == 1 || matrix[2][0] == 2)) {
        return matrix[2][0];
    }
    if (matrix[0][0] == matrix[1][0] && matrix[1][0] == matrix[2][0] && (matrix[0][0] == 1 || matrix[0][0] == 2)) {
        return matrix[0][0];
    }
    if (matrix[0][1] == matrix[1][1] && matrix[1][1] == matrix[2][1] && (matrix[0][1] == 1 || matrix[0][1] == 2)) {
        return matrix[0][1];
    }
    if (matrix[0][2] == matrix[1][2] && matrix[1][2] == matrix[2][2] && (matrix[0][2] == 1 || matrix[0][2] == 2)) {
        return matrix[0][2];
    }

    return 0;

}

int print_line_x(int line[3]) {
    printf("      +----+----+----+\n");
    for (int i = 0; i < 4; ++i) {
        printf("      ");
        printf("|");
        if (i == 0 || i == 3) {
            if (line[0] == 0) {
                printf("    ");
            } else if (line[0] == 1) {
                printf("X  X");
            } else if (line[0] == 2) {
                printf(" OO ");
            }
            printf("|");
            if (line[1] == 0) {
                printf("    ");
            } else if (line[1] == 1) {
                printf("X  X");
            } else if (line[1] == 2) {
                printf(" OO ");
            }
            printf("|");
            if (line[2] == 0) {
                printf("    ");
            } else if (line[2] == 1) {
                printf("X  X");
            } else if (line[2] == 2) {
                printf(" OO ");
            }
        } else {
            if (line[0] == 0) {
                printf("    ");
            } else if (line[0] == 1) {
                printf(" XX ");
            } else if (line[0] == 2) {
                printf("O  O");
            }
            printf("|");
            if (line[1] == 0) {
                printf("    ");
            } else if (line[1] == 1) {
                printf(" XX ");
            } else if (line[1] == 2) {
                printf("O  O");
            }
            printf("|");
            if (line[2] == 0) {
                printf("    ");
            } else if (line[2] == 1) {
                printf(" XX ");
            } else if (line[2] == 2) {
                printf("O  O");
            }
        }
        printf("|");
        if (i != 3) {
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}

int output_matrix(int matrix[3][3]) {
    clear_console();
    printf("\n\n\n");
    for (int i = 0; i < 3; ++i) {
        print_line_x(matrix[i]);

    }
    printf("      +----+----+----+\n");
    return 0;
}


int get_computer_move(int matrix[9]) {
    int x, y;
    do {
        x = rand() % 3;
        y = rand() % 3;
    } while (matrix[3 * x + y] != 0);

    matrix[3 * x + y] = 2;
    return 0;
}

//int get_computer_move_2(int matrix[3][3]) {
//    int x, y;
//    for (int i; i < 3, ++i) {
//        for (int j; j < 3, ++j) {
//            if (matrix[i][j] == 0) {
//                matrix[i][j] = 2;
//                return 0;
//            }
//        }
//    }
//    return 0;
//}

int check_move(int matrix[3][3], int x, int y, int turn) {
//    if turn == 1 -> computer
//    if turn == 2 -> player
    int ans = 0;
    if (turn == 1) {
        matrix[x][y] = 2;
        if (check_winner(matrix) == 2) {
            return 2;
        }

        for (int i; i < 3; ++i) {
            for (int j; j < 3; ++j) {
                if (matrix[i][j] == 0) {

                    if (check_move(matrix, i, j, 2) == 0) {
                        return 0;
                    }
                }

            }
        }
        return 1;
    }
    if (turn == 2) {
        matrix[x][y] = 1;
        if (check_winner(matrix) == 1) {
            return 0;
        }
        for (int i; i < 3; ++i) {
            for (int j; j < 3; ++j) {
                if (matrix[i][j] == 0) {
                    if (check_move(matrix, i, j, 1) == 0) {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
    return 1;
}

int get_player_move(int matrix[3][3], int error) {
    int x, y;
    if (error) {
        printf("Error! Please enter correct coordinates!\n");
    }
    output_matrix(matrix);
    printf("Please enter x and y: ");
    scanf("%d %d", &x, &y);
    if (matrix[x][y] == 0) {
        matrix[x][y] = 1;
    } else {
        return 1;
    }
    return 0;
}

int game(int matrix[3][3]) {
    int error = 0;
    int turn = 1;
    int winner = 0;

    while (winner == 0) {

        if (turn == 1) {
            if (!get_player_move(matrix, error)) {
                turn = 2;
                error = 0;
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
    return 0;
}

int main() {
    int matrix[3][3];


    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = 0;
        }
    }

    srand(time(NULL));
    game(matrix);
}

