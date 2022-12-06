#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0;
    int *mas = calloc(n, sizeof(int));
    int number;
    while (scanf("%d", &number) == 1) {
        n++;
        mas = realloc(mas, n * sizeof(int));
        mas[n - 1] = number;
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", mas[i]);
    }

    return 0;
}