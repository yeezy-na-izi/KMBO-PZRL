// input 2 vec out sum vec and len sum vec

#include <stdio.h>
#include <math.h>

int main() {
    int vec1[3];
    int vec2[3];

    printf("Please enter vec1: ");
    scanf("%d %d %d", &vec1[0], &vec1[1], &vec1[2]);
    printf("Please enter vec2: ");
    scanf("%d %d %d", &vec2[0], &vec2[1], &vec2[2]);

    int sum[3] = {vec1[0] + vec2[0], vec1[1] + vec2[1], vec1[2] + vec2[2]};

    printf("sum = (%d, %d, %d)\n", sum[0], sum[1], sum[2]);
    printf("len = %f\n", sqrt(sum[0] * sum[0] + sum[1] * sum[1] + sum[2] * sum[2]));

    return 0;
}