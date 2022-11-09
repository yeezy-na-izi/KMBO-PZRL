// input n, create mass n x n, with random numbers from 0 to 100

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int matrix[n][n];
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }
    printf("Matrix:\n");
    int* pointer = &matrix[0][0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%2d ", *pointer);
            pointer++;
        }
        printf("\n");
    }
    return 0;
}