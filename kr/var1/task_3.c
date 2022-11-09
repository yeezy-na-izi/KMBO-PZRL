#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    // generate matrix
    int matrix[n][n];
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }
    // out matrix
    printf("Matrix:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    // transpose matrix
    int tmp;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
    // out transposed matrix
    printf("Transposed matrix:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}