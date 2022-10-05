// input n and input n elem

#include <stdio.h>
#include <stdlib.h>


int main() {
    int n;

    printf("Please enter n: ");
    scanf("%d", &n);
    int vec[n];

    for (int i = 0; i < n; ++i) {
        printf("Please enter vec[%d]: ", i);
        scanf("%d", &vec[i]);
    }

    int* output = calloc(n, sizeof(int));
    int len = 0;
    int checker = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < len; ++j) {
            if (vec[i] == output[j]) {
                checker = 1;
                break;
            }
        }
        if (checker == 0) {
            output[len] = vec[i];
            ++len;
        }
        checker = 0;
    }

    output = realloc(output, len * sizeof(int));

    for (int i = 0; i < len; ++i) {
        printf("%d ", output[i]);
    }

    printf("\n");
    free(output);

    return 0;
}