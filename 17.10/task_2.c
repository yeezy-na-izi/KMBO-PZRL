#include <stdio.h>
#include <stdlib.h>


int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);


    char *answer = calloc(32, sizeof(char));
    int i = 1;
    int k;


    while (n > 0) {
        k = n & 1;
        if (k == 1) {
            answer[32 - i] = '1';
        } else {
            answer[32 - i] = '0';
        }
        ++i;
        n >>= 1;
    }

    for (int j = 0; j < 32; ++j) {
        printf("%c", answer[j]);
    }

    printf("\n");

    free(answer);
    return 0;
}