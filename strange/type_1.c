#include <stdlib.h>
#include <stdio.h>

int main() {
    int *a = calloc(10, sizeof(int));
    int *b = calloc(10, sizeof(int));

    for (int i = 0; i < 15; ++i) {
        a[i] = i;
    }
    printf("a: ");
    for (int i = 0; i < 10; ++i) {
        printf("%2i ", a[i]);
    }
    printf("\n");
    printf("b: ");
    for (int i = 0; i < 10; ++i) {
        printf("%2i ", b[i]);
    }
    printf("\n");
    free(a);
    free(b);
    return 0;
}