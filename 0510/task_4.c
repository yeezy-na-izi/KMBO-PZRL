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
    // input n, a, b gen mass len(n) elem get_float_number(a, b)
    int n;
    int a;
    int b;

    printf("Please enter n: ");
    scanf("%d", &n);
    printf("Please enter a: ");
    scanf("%d", &a);
    printf("Please enter b: ");
    scanf("%d", &b);

    int elem;
    int vec[n];
    int len;
    for (int i = 0; i < n; ++i) {
        srand(time(NULL));
        elem = get_float_number(a, b);
        int checker = 0;
        for (int j = 0; j < len; ++j) {
            if (elem == vec[j]) {
                checker = 1;
                break;
            }
        }
        if (checker == 0) {
            vec[len] = elem;
            printf("%d ", vec[len]);
            ++len
        }
        checker = 0;
    }
    printf("\n");
}