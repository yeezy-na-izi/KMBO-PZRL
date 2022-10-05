// input matrix 3x3 and output transposed matrix and determinant

#include <stdio.h>
#include <stdlib.h>


int main() {
    int matrix[3][3];

    printf("Please enter matrix:\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("Please enter matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    int det;
    det = matrix[0][0] * matrix[1][1] * matrix[2][2]
            + matrix[0][1] * matrix[1][2] * matrix[2][0]
            + matrix[0][2] * matrix[1][0] * matrix[2][1]
            - matrix[0][2] * matrix[1][1] * matrix[2][0]
            - matrix[0][1] * matrix[1][0] * matrix[2][2]
            - matrix[0][0] * matrix[1][2] * matrix[2][1];

    printf("det = %d\n", det);

    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}