#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    int n;
    int a;
    int b;
    printf("Введите количество элементов массива, нижнюю и верхнюю границы рандома через пробел\n");
    scanf("%i %i %i", &n, &a, &b);
    int mass[n];
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        mass[i] = rand() % (b - a + 1) + a;
    }
    for (int i = 0; i < n; ++i) {
        printf("%i ", mass[i]);
    }
    printf("\n");
    int unique[n];
    int i_unique = 0;
    int is_unique;
    for (int i = 0; i < n; ++i) {
        is_unique = 1;
        for (int j = 0; j < n; ++j) {
            if (mass[i] == mass[j] && i != j) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            unique[i_unique] = mass[i];
            i_unique++;
        }
    }
    for (int i = 0; i < i_unique; ++i) {
        printf("%i ", unique[i]);
    }
    return 0;
}
