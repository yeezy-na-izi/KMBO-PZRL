// input n, a, gen mas len n

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float get_float_number(int min, int max) {
    float number;
    int number_int = rand() % (max - min + 1) + min;
    number = (float) number_int;
    return number;
}

int main() {
    int n;
    int a;

    printf("Please enter n: ");
    scanf("%d", &n);
    printf("Please enter a: ");
    scanf("%d", &a);

    int vec[n];
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        vec[i] = get_float_number(-a, a);
        printf("%d ", vec[i]);
    }
    printf("\n")

    int sign_changes = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (vec[i] * vec[i + 1] < 0) {
            ++sign_changes;
        }
    }
    printf("%d\n", sign_changes);
}